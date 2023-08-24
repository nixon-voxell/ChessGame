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

	FTransform spawnLocation = FTransform::Identity;
	spawnLocation.SetLocation(FVector(x, y, this->ChessPieceElevation));
	if (isBlack)
	{
		spawnLocation.SetRotation(this->BlackRotation);
	}
	else
	{
		spawnLocation.SetRotation(this->WhiteRotation);
	}

	// Spawn chess piece
	AChessItem* spawnedPiece = this->GetWorld()->SpawnActor<AChessItem>(chessPiece->GetClass(), spawnLocation);
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
		}
	}
}

void AChessBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
