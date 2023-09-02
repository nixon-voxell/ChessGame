#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/PlayerCameraManager.h"
#include <iostream>

#include "Camera/CameraComponent.h"
#include <Components/Button.h>

#include "CameraTransition.generated.h"


UCLASS()
class CGRP_API ACameraTransition : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACameraTransition();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:
	virtual void Tick(float DeltaTime) override;
	/**
	 * Move the camera using CameraMovement1 logic.
	 * @param DeltaTime The time elapsed since the last frame.
	 */
	UFUNCTION(BlueprintCallable, Category = "My Widget")
	void CameraMovement1(float DeltaTime);

	/**
	 * Move the camera using CameraMovement2 logic.
	 * @param DeltaTime The time elapsed since the last frame.
	 */
	UFUNCTION(BlueprintCallable, Category = "My Widget")
	void CameraMovement2(float DeltaTime);

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spline", meta = (AllowPrivateAccess = "True"))
	UCameraComponent* CameraComponent;



};