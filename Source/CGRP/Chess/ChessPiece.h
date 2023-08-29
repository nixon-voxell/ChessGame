#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "PieceItem.h"
#include "PieceMovement.h"
#include "ChessPiece.generated.h"

USTRUCT(Blueprintable)
struct CGRP_API FChessPiece : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<APieceItem> Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(RequiredAssetDataTags = "RowStructure=/Script/CGRP.PieceMovement"))
	UDataTable* MovementTable;

public:
	FChessPiece();
	~FChessPiece();
};
