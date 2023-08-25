#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "ChessItem.h"
#include "PieceMovement.h"
#include "ChessPiece.generated.h"

USTRUCT(Blueprintable)
struct CGRP_API FChessPiece : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AChessItem> Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPieceMovement> Movements;

public:
	FChessPiece();
	~FChessPiece();
};
