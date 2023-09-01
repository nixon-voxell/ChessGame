// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessBoard.h"
#include "../ChessUtil/MovementUtil.h"

AChessItem* AChessBoard::SpawnChessPiece(int32 x, int32 y, FChessBoardLayout* BoardLayout)
{
	int32 boardIndex = x + y * 8;
	int32 pieceIndex = BoardLayout->GetPieceIndex(boardIndex);
	bool isBlack = pieceIndex < 0;
	AChessItem* chessPiece = this->ChessPieceBundle.GetPieceItem(FMath::Abs(pieceIndex));

	// NULL indicates that there shouldn't be any chess pieces there
	if (chessPiece == NULL)
	{
		return NULL;
	}

	FTransform spawnTransform = FTransform::Identity;
	FVector location = FVector(-x * this->TileSize, y * this->TileSize, this->ChessPieceElevation);
	spawnTransform.SetLocation(location);

	FPieceConfig pieceConfig = isBlack ? this->BlackConfig : this->WhiteConfig;
	spawnTransform.SetRotation(pieceConfig.Rotation);

	// Spawn chess piece
	APieceItem* spawnedPiece = this->GetWorld()->SpawnActor<APieceItem>(chessPiece->GetClass(), spawnTransform);
	spawnedPiece->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);

	// Assign material
	spawnedPiece->SetOriginMaterial(pieceConfig.Material);

	// Assign board index
	spawnedPiece->Initialize(boardIndex, isBlack);
	return spawnedPiece;
}

AChessItem* AChessBoard::SpawnChessTile(int32 x, int32 y)
{
	int32 boardIndex = x + y * 8;

	FTransform spawnTransform = FTransform::Identity;
	FVector location = FVector(-x * this->TileSize, y * this->TileSize, 0.0);
	spawnTransform.SetLocation(location);

	// Spawn chess tile
	AChessItem* spawnedTile = this->GetWorld()->SpawnActor<AChessItem>(
		this->ChessTile.GetDefaultObject()->GetClass(), spawnTransform
	);
	spawnedTile->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);

	// Assign material
	if ((x + boardIndex / 8) % 2 == 0)
	{
		spawnedTile->SetOriginMaterial(this->BlackTileMaterial);
	}
	else
	{
		spawnedTile->SetOriginMaterial(this->WhiteTileMaterial);
	}

	// Assign board index
	spawnedTile->BoardIndex = boardIndex;
	return spawnedTile;
}

void AChessBoard::MouseLeftClicked()
{
	// Reset all tile materials
	for (int t = 0; t < this->ChessTiles.Num(); t++)
	{
		this->ChessTiles[t]->ResetMaterial();
	}

	// Grab chess piece if available
	FHitResult hitResult;
	if (
		this->Controller->GetHitResultUnderCursor(
			ECollisionChannel::ECC_Visibility,
			false, hitResult
		)
	) {
		APieceItem* pieceItem = Cast<APieceItem>(hitResult.GetActor());

		if (pieceItem != NULL)
		{
			// Get chess piece table
			PieceType type = pieceItem->Type;
			FChessPiece* chessPiece = this->ChessPieceBundle.GetChessPiece((int32)type);
			UDataTable* table = chessPiece->MovementTable;

			// Get piece movements
			TArray<FPieceMovement*> movements;
			table->GetAllRows(pieceItem->GetName(), movements);

			UE_LOG(LogTemp, Log, TEXT("row count: %d"), movements.Num());
			UE_LOG(LogTemp, Log, TEXT("board index: %d"), pieceItem->BoardIndex);

			for (int r = 0; r < movements.Num(); r++)
			{
				FPieceMovement* movement = movements[r];

				int32 loopCount = 0;
				int32 multiplier = pieceItem->IsBlack ? -1 : 1;

				// Enter loop and continue if it is a direction, early exit if not
				// Highest number of loop will be 7 since there is only 8 rows
				while (loopCount < 8)
				{
					loopCount += 1;

					int32 xOffset = movement->XOffset * loopCount * multiplier;
					int32 yOffset = movement->YOffset * loopCount * multiplier;

					int32 offsetIndex = MovementUtil::OffsetFromXY(xOffset, yOffset);

					offsetIndex += pieceItem->BoardIndex;

					// Ignore if offset index off the board
					if (offsetIndex < 0 || offsetIndex > 63)
					{
						break;
					}

					// Ignore if offset index not at supposed y offset
					if (!MovementUtil::CheckYOffsetValidity(
						pieceItem->BoardIndex,
						offsetIndex,
						yOffset)
					) {
						break;
					}

					if (movement->IsMovement)
					{
						this->ChessTiles[offsetIndex]->SetMaterial(this->MovementMaterial);
					}

					// Break out of loop if it is not a direction
					if (!movement->IsDirection)
					{
						break;
					}
				}
				// UE_LOG(LogTemp, Log, TEXT("possible board index: %d"), offsetIndex);
			}

			this->LastSelectedPiece = pieceItem;
		}
	}
}

void AChessBoard::BeginPlay()
{
	Super::BeginPlay();

	this->Controller = UGameplayStatics::GetPlayerController(this->GetWorld(), 0);

	this->ChessPieceBundle.Initialize();
	this->InitBoardLayout = this->InitBoardLayoutRow.GetRow<FChessBoardLayout>(
		this->InitBoardLayoutRow.RowName.ToString()
	);

	// Generate chess tiles and chess pieces
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			AChessItem* chessPiece = this->SpawnChessPiece(x, y, this->InitBoardLayout);
			if (chessPiece != NULL)
			{
				this->ChessPieces.Add(chessPiece);
			}

			AChessItem* chessTile = this->SpawnChessTile(x, y);
			if (chessTile != NULL)
			{
				this->ChessTiles.Add(chessTile);
			}
		}
	}

	if (this->Controller->InputComponent != NULL)
	{
		this->Controller->InputComponent->BindAction(
			"MouseLeftClicked", IE_Pressed, this, &AChessBoard::MouseLeftClicked
		);
	}
}

void AChessBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Reset last hover item's material to its origin material
	if (this->LastHoverItem != NULL)
	{
		this->LastHoverItem->ResetMaterial();
	}

	// TODO: scale item instead of changing material
	// Change material on hovered item
	FHitResult hitResult;
	if (
		this->Controller->GetHitResultUnderCursor(
			ECollisionChannel::ECC_Visibility,
			false, hitResult
		)
	) {
		AChessItem* item = Cast<AChessItem>(hitResult.GetActor());

		if (item != NULL)
		{
			// item->SetMaterial(this->HoverMaterial);
			item->ScaleByFactor(this->HoverScaleFactor);
			// this->LastHoverItem = item;
		}
	}
}

AChessBoard::AChessBoard()
{
	this->SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	SetRootComponent(this->SceneComponent);

	this->PrimaryActorTick.bCanEverTick = true;
	this->PrimaryActorTick.bStartWithTickEnabled = true;
}
