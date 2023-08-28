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
	bool IsDirection = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 XOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 YOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool FirstStepOnly = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsCapture = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsMovement = true;

	FPieceMovement();
	~FPieceMovement();
};
