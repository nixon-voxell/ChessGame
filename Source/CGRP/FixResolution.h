// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "Engine/GameViewportClient.h"
#include "FixResolution.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class CGRP_API UFixResolution : public UGameUserSettings
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure)
    FIntPoint GetResolutionCustom();

    UFUNCTION(BlueprintPure)
    int32 GetNumberCustom();

    UFUNCTION(BlueprintCallable)
    static UFixResolution* GetGameUserSettingsCustom();

protected:
    UPROPERTY(Config)
    int32 ResolutionX;
    int32 ResolutionY;

};
