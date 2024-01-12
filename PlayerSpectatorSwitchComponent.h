// PlayerSpectatorSwitchComponent.h

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerSpectatorSwitchComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UPlayerSpectatorSwitchComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UPlayerSpectatorSwitchComponent();

protected:
    virtual void BeginPlay() override;

public:
    // Function to toggle between player and spectator
    void ToggleSpectatorMode();

    // Expose Global Time Dilation to the editor
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Dilation")
    float GlobalTimeDilationValue;

    // Expose Custom Time Dilation for the spectator pawn to the editor
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Dilation")
    float CustomSpectatorTimeDilationValue;

private:
    TWeakObjectPtr<APawn> OriginalPlayerPawn;
    bool bIsInSpectatorMode;
};
