#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CameraMovement.generated.h"

UCLASS()
class CGRP_API UCameraMovement : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Camera Functions")
	static void MoveCameraToLocation(APlayerController* PlayerController, FVector TargetLocation, float TransitionDuration);

};