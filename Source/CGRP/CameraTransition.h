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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double MovementSpeed = 1.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double RotationSpeed = 1.5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config|White")
	FVector WhiteLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config|White")
	FRotator WhiteRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config|Black")
	FVector BlackLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config|Black")
	FRotator BlackRotation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "My Widget")
	void CameraMovement(float DeltaTime, FVector TargetLocation, FRotator TargetRotation);

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spline", meta = (AllowPrivateAccess = "True"))
	UCameraComponent* CameraComponent;
};
