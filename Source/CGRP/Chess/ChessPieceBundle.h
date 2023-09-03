// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "PieceItem.h"
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

	APieceItem* PieceItems[7];
	FChessPiece* ChessPieces[7];

	void Initialize();
	APieceItem* GetPieceItem(int32 Index);
	FChessPiece* GetChessPiece(int32 Index);

	FChessPieceBundle();
	~FChessPieceBundle();
};
