// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

#include "ChessItem.h"
#include "ChessPieceBundle.h"
#include "ChessBoardLayout.h"
#include "PieceLayout.h"
#include "PieceConfig.h"
#include "PieceType.h"
#include "HoverType.h"
#include "ChessBoard.generated.h"

UCLASS()
class CGRP_API AChessBoard : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AChessItem> ChessTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDataTableRowHandle InitBoardLayoutRow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FChessPieceBundle ChessPieceBundle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double ChessPieceElevation = 100.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double TileSize = 100.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double HoverScaleFactor = 1.2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double HoverScaleSpeed = 10.0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FPieceConfig WhiteConfig;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FPieceConfig BlackConfig;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMaterial* BlackTileMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMaterial* WhiteTileMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMaterial* MovementMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMaterial* SelectionMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMaterial* CaptureMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	HoverType CurrHoverType;

protected:
	// variables
	APlayerController* Controller;
	FChessBoardLayout* InitBoardLayout;

	FPieceLayout PieceLayout;

	TArray<AChessItem*> ChessTiles;
	TArray<APieceItem*> ChessPieces;

	APieceItem* LastSelectedPiece;
	// Board indices that are accepted for movement
	TArray<int32> AcceptedIndices;

	// functions
	APieceItem* SpawnChessPiece(int32 x, int32 y, FChessBoardLayout* BoardLayout);
	AChessItem* SpawnChessTile(int32 x, int32 y);

	void HoverUpdate();
	void MouseLeftClicked();
	void ShowPieceNextMovement(APieceItem* PieceItem);
	void AcceptBoardIndex(int32 Index, UMaterial* Material);

	UFUNCTION(BlueprintCallable, Category = "CPP_ChessBoard")
	void StartWhiteTurn();

	UFUNCTION(BlueprintCallable, Category = "CPP_ChessBoard")
	void StartBlackTurn();

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	AChessBoard();
};
