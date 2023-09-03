#pragma once

#include "CoreMinimal.h"

#include "PieceItem.h"
#include "PieceType.h"
#include "PieceLayout.generated.h"

USTRUCT(BlueprintType)
struct CGRP_API FPieceLayout
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Layout")
	TArray<APieceItem*> Layout;

	PieceType GetPieceType(int32 BoardIndex);
	void MovePiece(int32 OriginIndex, int32 TargetIndex);
  void SetPiece(int32 BoardIndex, APieceItem* PieceItem);

	FPieceLayout();
	~FPieceLayout();
};
