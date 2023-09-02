// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MusicManager.generated.h"

UCLASS(Blueprintable)
class CGRP_API AMusicManager : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAudioComponent* AudioComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Music")
	USoundBase* MainMenuMusic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Music")
	USoundBase* GameBGM;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Music")
	USoundBase* WinMusic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Effects")
	USoundBase* MoveChessSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Effects")
	USoundBase* StartButtonSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Effects")
	USoundBase* EndButtonSound;

	// Sets default values for this actor's properties
	AMusicManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Music Control")
	void PlayMainMenuMusic();

	UFUNCTION(BlueprintCallable, Category = "Music Control")
	void PlayGameBGM();

	UFUNCTION(BlueprintCallable, Category = "Music Control")
	void PlayWinMusic();

	UFUNCTION(BlueprintCallable, Category = "Music Control")
	void PlayMoveChessSound();

	UFUNCTION(BlueprintCallable, Category = "Music Control")
	void PlayStartButtonSound();

	UFUNCTION(BlueprintCallable, Category = "Music Control")
	void PlayEndButtonSound();
};