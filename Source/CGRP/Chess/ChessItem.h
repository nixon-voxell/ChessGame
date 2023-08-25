#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChessItem.generated.h"

UCLASS(Blueprintable)
class CGRP_API AChessItem : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AChessItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 BoardIndex;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
