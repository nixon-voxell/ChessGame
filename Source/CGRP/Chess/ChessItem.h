#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChessItem.generated.h"

UCLASS()
class CGRP_API AChessItem : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AChessItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess")
	int32 BoardIndex;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
