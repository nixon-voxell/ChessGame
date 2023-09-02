// Fill out your copyright notice in the Description page of Project Settings.


#include "FixResolution.h"
#include "Engine/Engine.h"



FIntPoint UFixResolution::GetResolutionCustom()
{
	ResolutionX = 1920;
	ResolutionY = 1080;
	FIntPoint Resolution(ResolutionX, ResolutionY);
	return Resolution;
}

int32 UFixResolution::GetNumberCustom()
{
	ResolutionX = 1920;
	int32 Number(ResolutionX);
	return Number;
}

UFixResolution* UFixResolution::GetGameUserSettingsCustom()
{
	return Cast<UFixResolution>(UGameUserSettings::GetGameUserSettings());
}
