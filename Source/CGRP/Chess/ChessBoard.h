// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ChessItem.h"
#include "ChessPieceBundle.h"
#include "ChessBoardLayout.h"
#include "ChessBoard.generated.h"

UCLASS()
class CGRP_API AChessBoard : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess Board")
	FDataTableRowHandle InitBoardLayoutRow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess Board")
	FChessPieceBundle ChessPieceBundle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess Board")
	double ChessPieceElevation = 1.0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Chess Board|White Rotation")
	FQuat WhiteRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Chess Board|Black Rotation")
	FQuat BlackRotation;

protected:
	FChessBoardLayout* InitBoardLayout;

protected:
	void SpawnChessPiece(int32 x, int32 y, FChessBoardLayout* BoardLayout);

	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
