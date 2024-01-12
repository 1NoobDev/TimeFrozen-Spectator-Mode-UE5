// CustomSpectatorPawn.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpectatorPawn.h"
#include "CustomSpectatorPawn.generated.h"

UCLASS()
class ACustomSpectatorPawn : public ASpectatorPawn
{
    GENERATED_BODY()

public:
    ACustomSpectatorPawn();
    virtual void Tick(float DeltaTime) override;

    void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

    // Function to adjust custom time dilation with mouse wheel  
    void AdjustCustomTimeDilation(float AxisValue);

    // Define minimum and maximum time dilation values  
    static const float MinTimeDilation;
    static const float MaxTimeDilation;
};
