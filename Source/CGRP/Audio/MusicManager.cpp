// Fill out your copyright notice in the Description page of Project Settings.

#include "MusicManager.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"

// Sets default values
AMusicManager::AMusicManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Initialize the AudioComponent
	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));

	// You will manually trigger which sound to play.
	AudioComponent->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AMusicManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMusicManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMusicManager::PlayMainMenuMusic()
{
	// Stop any currently playing sound
	AudioComponent->Stop();
	// Set the main menu music and play it
	AudioComponent->SetSound(MainMenuMusic);
	AudioComponent->Play();
}

void AMusicManager::PlayGameBGM()
{
	// Stop the main menu music
	AudioComponent->Stop();
	// Set the game BGM and play it
	AudioComponent->SetSound(GameBGM);
	AudioComponent->Play();
}

void AMusicManager::PlayWinMusic()
{
	// Play the win music without stopping the game BGM
	UGameplayStatics::PlaySoundAtLocation(this, WinMusic, GetActorLocation());
}

void AMusicManager::PlayMoveChessSound()
{
	// Play the move chess sound without stopping the BGM
	UGameplayStatics::PlaySoundAtLocation(this, MoveChessSound, GetActorLocation());
}