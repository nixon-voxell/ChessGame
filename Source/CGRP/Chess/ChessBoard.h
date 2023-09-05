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
#include "../Audio/MusicManager.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	AMusicManager* MusicManager;

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

	// Keep track of captured count
	int32 CapturedWhiteCount;
	int32 CapturedBlackCount;

	// functions
	APieceItem* SpawnChessPiece(int32 x, int32 y, FChessBoardLayout* BoardLayout);
	AChessItem* SpawnChessTile(int32 x, int32 y);

	void HoverUpdate();
	void MouseLeftClicked();
	void ShowPieceNextMovement(APieceItem* PieceItem);
	void AcceptBoardIndex(int32 Index, UMaterial* Material);
	void CapturePiece(APieceItem* CapturedPiece);
	void Win();

	UFUNCTION(BlueprintCallable, Category = "CPP ChessBoard")
	void StartWhiteTurn();

	UFUNCTION(BlueprintCallable, Category = "CPP ChessBoard")
	void StartBlackTurn();

	UFUNCTION(BlueprintCallable, Category = "CPP ChessBoard")
	void WhiteWin();

	UFUNCTION(BlueprintCallable, Category = "CPP ChessBoard")
	void BlackWin();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "CPP ChessBoard")
	void OnStartWhiteTurn();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "CPP ChessBoard")
	void OnStartBlackTurn();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "CPP ChessBoard")
	void OnWhiteWin();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "CPP ChessBoard")
	void OnBlackWin();

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	AChessBoard();
};
