// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine.h"
#include "FixResolution.h"

void UFixResolution::ApplyFixedResolution()
{
    // Set the screen resolution scale to 720p
    SetResolutionScaleNormalized(1280.0f / 720.0f);

    // Apply the resolution settings
    ApplyResolutionSettings(false);

    // Print a message to the screen to confirm that the function was called
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Fixed resolution applied!"));
}