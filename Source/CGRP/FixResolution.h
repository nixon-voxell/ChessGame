// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "FixResolution.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class CGRP_API UFixResolution : public UGameUserSettings
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Resolution")
    void ApplyFixedResolution();
};
