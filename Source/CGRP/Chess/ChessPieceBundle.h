// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "ChessItem.h"
#include "ChessPieceBundle.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct CGRP_API FChessPieceBundle : public FTableRowBase
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess Pieces")
	AChessItem* Pawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess Pieces")
	AChessItem* Rook;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess Pieces")
	AChessItem* Knight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess Pieces")
	AChessItem* BishopPiece;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess Pieces")
	AChessItem* QueenPiece;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess Pieces")
	AChessItem* KingPiece;

	FChessPieceBundle();
	~FChessPieceBundle();
};
