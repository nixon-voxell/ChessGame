#pragma once

#include "CoreMinimal.h"

#include "PieceItem.h"
#include "PieceLayout.generated.h"

USTRUCT(BlueprintType)
struct CGRP_API FPieceLayout
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Layout")
	TArray<APieceItem*> Layout;

  void SetPiece(int32 BoardIndex, APieceItem* PieceItem);
	APieceItem* GetPiece(int32 BoardIndex);
	// Move piece and return captured piece
	APieceItem* MovePiece(int32 OriginIndex, int32 TargetIndex);

	FPieceLayout();
	~FPieceLayout();
};
