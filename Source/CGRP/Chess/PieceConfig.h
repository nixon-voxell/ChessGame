#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "PieceConfig.generated.h"

USTRUCT(BlueprintType)
struct CGRP_API FPieceConfig : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FQuat Rotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMaterial* Material;

	FPieceConfig();
	~FPieceConfig();
};
