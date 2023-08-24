// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ChessPieceBundle.h"
#include "ChessItem.h"
#include "ChessBoard.generated.h"

UCLASS()
class CGRP_API AChessBoard : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AChessBoard();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess")
	AChessItem* ChessTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess")
	FChessPieceBundle ChessPieceBundle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
