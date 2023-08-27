#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "PieceMovement.generated.h"

USTRUCT(Blueprintable)
struct CGRP_API FPieceMovement : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 XOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 YOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool FirstStepOnly;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool CaptureOnly;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool MovementOnly;

	FPieceMovement();
	~FPieceMovement();
};
