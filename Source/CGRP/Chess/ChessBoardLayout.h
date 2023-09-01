#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "PieceType.h"
#include "ChessBoardLayout.generated.h"

USTRUCT(BlueprintType)
struct CGRP_API FChessBoardLayout : public FTableRowBase
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Layout")
	TArray<PieceType> Layout;

	void CopyBoardLayout(FChessBoardLayout* Layout);

	int32 GetPieceIndex(int32 BoardIndex);
	void MovePiece(int32 OriginIndex, int32 TargetIndex);

	FChessBoardLayout();
	~FChessBoardLayout();
};
