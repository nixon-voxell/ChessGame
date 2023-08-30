#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/PlayerCameraManager.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"
#include "Components/SplineComponent.h"
#include "Components/TimelineComponent.h"
#include "Components/Button.h"
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


public:
	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spline", meta = (AllowPrivateAccess = "True"))
	USplineComponent* SplineComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spline", meta = (AllowPrivateAccess = "True"))
	UCameraComponent* CameraComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spline")
	UCurveFloat* MovementCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spline")
	bool bAutoActive;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spline", meta = (EditCondition = "!bReverseOnEndTimeline"))
	bool bReverseOnEndTimeline;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spline", meta = (EditCondition = "!bRestartOnTimeline"))
	bool bRestartOnTimeline;

};