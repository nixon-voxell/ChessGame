// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HideUnhideButtons.generated.h"

/**
 * 
 */
UCLASS()
class CGRP_API UHideUnhideButtons : public UUserWidget
{
    GENERATED_BODY()

public:
    // Call this function to select all buttons inside the widget.
    UFUNCTION(BlueprintCallable, Category = "Button Selection")
    void SelectAllButtonsCustom();
};