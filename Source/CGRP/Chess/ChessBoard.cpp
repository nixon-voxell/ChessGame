// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessBoard.h"
#include "../ChessUtil/MovementUtil.h"

APieceItem* AChessBoard::SpawnChessPiece(int32 x, int32 y, FChessBoardLayout* BoardLayout)
{
	int32 boardIndex = x + y * 8;
	int32 pieceIndex = BoardLayout->GetPieceIndex(boardIndex);
	bool isBlack = pieceIndex < 0;
	APieceItem* chessPiece = this->ChessPieceBundle.GetPieceItem(FMath::Abs(pieceIndex));

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

	// Initialize chess piece
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

void AChessBoard::HoverUpdate()
{
	if (this->CurrHoverType == HoverType::None)
	{
		return;
	}

	// Scale hovered item
	FHitResult hitResult;
	if (
		this->Controller->GetHitResultUnderCursor(
			ECollisionChannel::ECC_Visibility,
			false, hitResult
		)
	) {
		AChessItem* item = Cast<AChessItem>(hitResult.GetActor());
		APieceItem* pieceItem = Cast<APieceItem>(item);

		// Ignore if nothing is being hovered
		if (item == NULL)
		{
			return;
		}

		bool canScale = false;

		switch (this->CurrHoverType)
		{
			case HoverType::Tile:
				// Must not be a piece item
				canScale = pieceItem == NULL;
				break;

			case HoverType::WhitePiece:
				// Only white piece
				canScale = pieceItem != NULL && !pieceItem->IsBlack;
				break;

			case HoverType::BlackPiece:
				// Only black piece
				canScale = pieceItem != NULL && pieceItem->IsBlack;
				break;

			default:
				break;
		}

		if (canScale)
		{
			item->ScaleByFactor(this->HoverScaleFactor, this->HoverScaleSpeed);
		}
	}
}

void AChessBoard::MouseLeftClicked()
{
	// Reset all tile materials
	for (int t = 0; t < this->ChessTiles.Num(); t++)
	{
		this->ChessTiles[t]->ResetMaterial();
	}

	// Reset all piece materials
	for (int p = 0; p < this->ChessPieces.Num(); p++)
	{
		this->ChessPieces[p]->ResetMaterial();
	}

	if (this->CurrHoverType == HoverType::None)
	{
		return;
	}

	FHitResult hitResult;
	if (
		this->Controller->GetHitResultUnderCursor(
			ECollisionChannel::ECC_Visibility,
			false, hitResult
		)
	) {
		AChessItem* item = Cast<AChessItem>(hitResult.GetActor());
		APieceItem* pieceItem = Cast<APieceItem>(item);

		// Ignore if nothing is being selected
		// if (item == NULL)
		// {
		// 	return;
		// }

		bool canShowNextMove = false;
		bool canSwitchSide = false;

		switch (this->CurrHoverType)
		{
			case HoverType::Tile:
				// Must not be a piece item
				if (pieceItem == NULL)
				{
					// TODO: Move piece if board index is accepted
					if (this->AcceptedIndices.Contains(item->BoardIndex))
					{
						canSwitchSide = true;
						// Move piece to new location
						this->LastSelectedPiece->SetActorLocation(
							item->GetActorLocation() + FVector(0.0, 0.0, this->ChessPieceElevation)
						);
						APieceItem* capturedPiece = this->PieceLayout.MovePiece(this->LastSelectedPiece->BoardIndex, item->BoardIndex);

						// Capture piece if available
						if (capturedPiece != NULL)
						{
							// TODO
							if (capturedPiece->Type == PieceType::WhiteKing)
							{
								capturedPiece->IsBlack ? this->WhiteWin() : this->BlackWin();
							}
						}
					}
				}
				break;

			case HoverType::WhitePiece:
				// Only white piece
				canShowNextMove = pieceItem != NULL && !pieceItem->IsBlack;
				break;

			case HoverType::BlackPiece:
				// Only black piece
				canShowNextMove = pieceItem != NULL && pieceItem->IsBlack;
				break;

			default:
				break;
		}

		this->AcceptedIndices.Empty();

		if (this->LastSelectedPiece != NULL && this->CurrHoverType == HoverType::Tile)
		{
			if (canSwitchSide)
			{
				this->LastSelectedPiece->IsBlack ? this->StartWhiteTurn() : this->StartBlackTurn();
			}
			else
			{
				this->LastSelectedPiece->IsBlack ? this->StartBlackTurn() : this->StartWhiteTurn();
			}
		}

		if (canShowNextMove)
		{
			pieceItem->SetMaterial(this->SelectionMaterial);
			this->ShowPieceNextMovement(pieceItem);
			this->CurrHoverType = HoverType::Tile;
		}
	}
	else
	{
		this->AcceptedIndices.Empty();

		if (this->LastSelectedPiece != NULL && this->CurrHoverType == HoverType::Tile)
		{
			this->LastSelectedPiece->IsBlack ? this->StartBlackTurn() : this->StartWhiteTurn();
		}
	}
}

void AChessBoard::ShowPieceNextMovement(APieceItem* PieceItem)
{
	this->LastSelectedPiece = PieceItem;

	// Get chess piece table
	PieceType type = PieceItem->Type;
	FChessPiece* chessPiece = this->ChessPieceBundle.GetChessPiece((int32)type);
	UDataTable* table = chessPiece->MovementTable;

	// Get piece movements
	TArray<FPieceMovement*> movements;
	table->GetAllRows(PieceItem->GetName(), movements);

	for (int r = 0; r < movements.Num(); r++)
	{
		FPieceMovement* movement = movements[r];

		int32 loopCount = 0;
		int32 multiplier = PieceItem->IsBlack ? -1 : 1;

		// Enter loop and continue if it is a direction, early exit if not
		// Highest number of loop will be 7 since there is only 8 rows
		while (loopCount < 8)
		{
			loopCount += 1;

			int32 xOffset = movement->XOffset * loopCount * multiplier;
			int32 yOffset = movement->YOffset * loopCount * multiplier;

			int32 offsetIndex = MovementUtil::OffsetFromXY(xOffset, yOffset);

			offsetIndex += PieceItem->BoardIndex;

			// Ignore if offset index off the board
			if (offsetIndex < 0 || offsetIndex > 63)
			{
				break;
			}

			// Ignore if offset index not at supposed y offset
			if (!MovementUtil::CheckYOffsetValidity(
				PieceItem->BoardIndex,
				offsetIndex,
				yOffset)
			) {
				break;
			}

			// Ignore if this movement is for first step only and
			// piece is not at it's origin location
			if (movement->FirstStepOnly && !PieceItem->IsAtOrigin())
			{
				break;
			}

			// Check if anything is blocking
			APieceItem* offsetPiece = this->PieceLayout.GetPiece(offsetIndex);
			if (offsetPiece != NULL)
			{
				bool isEnemy = PieceItem->IsBlack != offsetPiece->IsBlack;

				if (isEnemy && movement->IsCapture)
				{
					this->AcceptBoardIndex(offsetIndex, this->CaptureMaterial);
				}

				// Break anyways since something is blocking us
				break;
			}

			if (movement->IsMovement)
			{
				this->AcceptBoardIndex(offsetIndex, this->MovementMaterial);
			}

			// Break out of loop if it is not a direction
			if (!movement->IsDirection)
			{
				break;
			}
		}
	}
}

void AChessBoard::AcceptBoardIndex(int32 Index, UMaterial* Material)
{
	this->ChessTiles[Index]->SetMaterial(Material);
	this->AcceptedIndices.Add(Index);
}

void AChessBoard::Win()
{
	this->CurrHoverType = HoverType::None;
}

void AChessBoard::StartWhiteTurn()
{
	this->CurrHoverType = HoverType::WhitePiece;
	this->OnStartWhiteTurn();
}

void AChessBoard::StartBlackTurn()
{
	this->CurrHoverType = HoverType::BlackPiece;
	this->OnStartBlackTurn();
}

void AChessBoard::WhiteWin()
{
	this->Win();
	this->OnWhiteWin();
}

void AChessBoard::BlackWin()
{
	this->Win();
	this->OnBlackWin();
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
			int32 boardIndex = x + y * 8;
			APieceItem* chessPiece = this->SpawnChessPiece(x, y, this->InitBoardLayout);

			this->PieceLayout.SetPiece(boardIndex, chessPiece);

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

	this->HoverUpdate();
}

AChessBoard::AChessBoard()
{
	this->SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	SetRootComponent(this->SceneComponent);

	this->PrimaryActorTick.bCanEverTick = true;
	this->PrimaryActorTick.bStartWithTickEnabled = true;

	this->CurrHoverType = HoverType::None;
}
