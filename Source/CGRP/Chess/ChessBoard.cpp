// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessBoard.h"

// Sets default values
AChessBoard::AChessBoard()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AChessBoard::BeginPlay()
{
	Super::BeginPlay();
	this->ChessPieceBundle.Initialize();
	// TODO: generate chess tiles and chess pieces

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			// instantiate chess pieces
			// FTransform SpawnLocation;
      // GetWorld()->SpawnActor<AMyFirstActor>( AMyFirstActor::StaticClass(), &SpawnLocation);
		}
	}
}

// Called every frame
void AChessBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

