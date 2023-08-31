#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ChessItem.h"
#include "PieceType.h"
#include "PieceItem.generated.h"

UCLASS(Blueprintable)
class CGRP_API APieceItem : public AChessItem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	PieceType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsBlack;

protected:
	int32 OriginBoardIndex;

	virtual void BeginPlay() override;

public:
	void Initialize(int32 Index, bool Black);
	bool IsAtOrigin();
	virtual void Tick(float DeltaTime) override;

	APieceItem();
};
