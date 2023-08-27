// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessBoard.h"

void AChessBoard::SpawnChessPiece(int32 x, int32 y, FChessBoardLayout* BoardLayout)
{
	int32 boardIndex = x + y * 8;
	int32 pieceIndex = BoardLayout->GetPieceIndex(boardIndex);
	bool isBlack = pieceIndex < 0;
	AChessItem* chessPiece = this->ChessPieceBundle.Pieces[FMath::Abs(pieceIndex)];

	// NULL indicates that there shouldn't be any chess pieces there
	if (chessPiece == NULL)
	{
		return;
	}

	FTransform spawnTransform = FTransform::Identity;
	FVector location = FVector(-x * this->TileSize, y * this->TileSize, this->ChessPieceElevation);
	spawnTransform.SetLocation(location);

	FPieceConfig pieceConfig = isBlack ? this->BlackConfig : this->WhiteConfig;
	spawnTransform.SetRotation(pieceConfig.Rotation);

	// Spawn chess piece
	AChessItem* spawnedPiece = this->GetWorld()->SpawnActor<AChessItem>(chessPiece->GetClass(), spawnTransform);

	// Assign material
	TArray<UStaticMeshComponent*> meshComps;
	spawnedPiece->GetComponents<UStaticMeshComponent*>(meshComps);
	meshComps[0]->SetMaterial(0, pieceConfig.Material);

	// Assign board index
	spawnedPiece->BoardIndex = boardIndex;
}

void AChessBoard::SpawnChessTile(int32 x, int32 y)
{
	int32 boardIndex = x + y * 8;

	FTransform spawnTransform = FTransform::Identity;
	FVector location = FVector(-x * this->TileSize, y * this->TileSize, 0.0);
	spawnTransform.SetLocation(location);

	// Spawn chess tile
	AChessItem* spawnedTile = this->GetWorld()->SpawnActor<AChessItem>(this->ChessTile.GetDefaultObject()->GetClass(), spawnTransform);

	// Assign material
	TArray<UStaticMeshComponent*> meshComps;
	spawnedTile->GetComponents<UStaticMeshComponent*>(meshComps);
	if ((x + boardIndex / 8) % 2 == 0)
	{
		meshComps[0]->SetMaterial(0, this->BlackTileMaterial);
	}
	else
	{
		meshComps[0]->SetMaterial(0, this->WhiteTileMaterial);
	}

	// Assign board index
	spawnedTile->BoardIndex = boardIndex;
}

void AChessBoard::BeginPlay()
{
	Super::BeginPlay();
	this->ChessPieceBundle.Initialize();
	this->InitBoardLayout = this->InitBoardLayoutRow.GetRow<FChessBoardLayout>(
		this->InitBoardLayoutRow.RowName.ToString()
	);

	// Generate chess tiles and chess pieces
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			this->SpawnChessPiece(x, y, this->InitBoardLayout);
			this->SpawnChessTile(x, y);
		}
	}
}

void AChessBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
