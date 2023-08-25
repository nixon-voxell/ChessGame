// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "ChessItem.h"
#include "ChessPiece.h"
#include "ChessPieceBundle.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct CGRP_API FChessPieceBundle : public FTableRowBase
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FChessPiece Pawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FChessPiece Rook;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FChessPiece Knight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FChessPiece BishopPiece;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FChessPiece QueenPiece;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FChessPiece KingPiece;

	AChessItem* Pieces[7];

	void Initialize();

	FChessPieceBundle();
	~FChessPieceBundle();
};
