// PlayerSpectatorSwitchComponent.cpp

#include "PlayerSpectatorSwitchComponent.h"
#include "CustomSpectatorPawn.h" 
#include "GameFramework/SpectatorPawn.h"
#include "Kismet/GameplayStatics.h"

UPlayerSpectatorSwitchComponent::UPlayerSpectatorSwitchComponent()
{
    bIsInSpectatorMode = false;
    GlobalTimeDilationValue = 0.000001f; // Set your default global time dilation value
    CustomSpectatorTimeDilationValue = 10000.0f; // Set your default custom spectator time dilation value
}

void UPlayerSpectatorSwitchComponent::BeginPlay()
{
    Super::BeginPlay();

    // Bind the ToggleSpectatorMode function to the input action
    AActor* Owner = GetOwner();
    if (Owner)
    {
        Owner->InputComponent->BindAction("ToggleSpectatorMode", IE_Pressed, this, &UPlayerSpectatorSwitchComponent::ToggleSpectatorMode);
    }
}

void UPlayerSpectatorSwitchComponent::ToggleSpectatorMode()
{
    APlayerController* PlayerController = Cast<APlayerController>(GetOwner());
    if (!PlayerController) return;

    if (bIsInSpectatorMode)
    {
        // Switch back to player pawn
        if (OriginalPlayerPawn.IsValid())
        {
            PlayerController->Possess(OriginalPlayerPawn.Get());
            UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1.f);
        }
        bIsInSpectatorMode = false;
    }
    else
    {
        // Switch to custom spectator pawn
        if (PlayerController->GetPawn())
        {
            OriginalPlayerPawn = PlayerController->GetPawn();
            PlayerController->UnPossess();

            FActorSpawnParameters SpawnParams;
            SpawnParams.Owner = PlayerController;
            ACustomSpectatorPawn* SpectatorPawn = GetWorld()->SpawnActor<ACustomSpectatorPawn>(ACustomSpectatorPawn::StaticClass(), OriginalPlayerPawn->GetActorLocation(), OriginalPlayerPawn->GetActorRotation(), SpawnParams);

            PlayerController->Possess(SpectatorPawn);
            UGameplayStatics::SetGlobalTimeDilation(GetWorld(), GlobalTimeDilationValue);

            // Set the spectator pawn's custom time dilation based on the property from the component
            SpectatorPawn->CustomTimeDilation = CustomSpectatorTimeDilationValue;
        }
        bIsInSpectatorMode = true;
    }
}
