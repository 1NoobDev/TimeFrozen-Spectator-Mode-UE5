// CustomSpectatorPawn.cpp

#include "CustomSpectatorPawn.h"
#include "PlayerSpectatorSwitchComponent.h"

// Initialize the static constants  
const float ACustomSpectatorPawn::MinTimeDilation = 1337.f; // Set your desired minimum time dilation value  
const float ACustomSpectatorPawn::MaxTimeDilation = 100000.0f; // Set your desired maximum time dilation value  

ACustomSpectatorPawn::ACustomSpectatorPawn()
{
    // Enable ticking to move the pawn
    PrimaryActorTick.bCanEverTick = true;
}

void ACustomSpectatorPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ACustomSpectatorPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Bind the AdjustCustomTimeDilation function to the mouse wheel axis  
    PlayerInputComponent->BindAxis("MouseWheelAxis", this, &ACustomSpectatorPawn::AdjustCustomTimeDilation);
}

void ACustomSpectatorPawn::AdjustCustomTimeDilation(float AxisValue)
{
    if (AxisValue != 0.0f)
    {
        // Get the PlayerSpectatorSwitchComponent from the player controller  
        APlayerController* PlayerController = Cast<APlayerController>(GetController());
        if (PlayerController)
        {
            UPlayerSpectatorSwitchComponent* SpectatorSwitchComponent = PlayerController->FindComponentByClass<UPlayerSpectatorSwitchComponent>();
            if (SpectatorSwitchComponent)
            {
                // Adjust the CustomSpectatorTimeDilationValue based on the mouse wheel input
                // Multiply AxisValue by 100 to change the value by 100 units per scroll notch
                SpectatorSwitchComponent->CustomSpectatorTimeDilationValue += AxisValue * 100.f;

                // Clamp the value to the defined range  
                SpectatorSwitchComponent->CustomSpectatorTimeDilationValue = FMath::Clamp(SpectatorSwitchComponent->CustomSpectatorTimeDilationValue, MinTimeDilation, MaxTimeDilation);

                // Apply the new time dilation value to the spectator pawn  
                CustomTimeDilation = SpectatorSwitchComponent->CustomSpectatorTimeDilationValue;

                // Log the new time dilation value
                UE_LOG(LogTemp, Log, TEXT("Custom Time Dilation adjusted to: %f"), CustomTimeDilation);
            }
        }
    }
}
