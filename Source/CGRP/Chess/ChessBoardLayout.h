#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "GameFramework/Character.h"
#include "ChessBoardLayout.generated.h"

USTRUCT(BlueprintType)
struct CGRP_API FChessBoardLayout : public FTableRowBase
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Layout")
	TArray<int32> Layout;

	int32 GetItemIndex(int32 BoardIndex);

	FChessBoardLayout();
	~FChessBoardLayout();
};
