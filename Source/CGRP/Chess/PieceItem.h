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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	APieceItem();
};
