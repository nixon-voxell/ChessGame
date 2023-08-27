// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessBoard.h"
#include "../ChessUtil/MovementUtil.h"

AChessItem* AChessBoard::SpawnChessPiece(int32 x, int32 y, FChessBoardLayout* BoardLayout)
{
	int32 boardIndex = x + y * 8;
	int32 pieceIndex = BoardLayout->GetPieceIndex(boardIndex);
	bool isBlack = pieceIndex < 0;
	AChessItem* chessPiece = this->ChessPieceBundle.Pieces[FMath::Abs(pieceIndex)];

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
	AChessItem* spawnedPiece = this->GetWorld()->SpawnActor<AChessItem>(chessPiece->GetClass(), spawnTransform);
	spawnedPiece->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);

	// Assign material
	TArray<UStaticMeshComponent*> meshComps;
	spawnedPiece->GetComponents<UStaticMeshComponent*>(meshComps);
	meshComps[0]->SetMaterial(0, pieceConfig.Material);

	// Assign board index
	spawnedPiece->BoardIndex = boardIndex;
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
	TArray<UStaticMeshComponent*> meshComps;
	spawnedTile->GetComponents<UStaticMeshComponent*>(meshComps);
	if ((x + boardIndex / 8) % 2 == 0)
	{
		meshComps[0]->SetMaterial(0, this->BlackTileMaterial);
	}
	else
	{
		meshComps[0]->SetMaterial(0, this->WhiteTileMaterial);
	}

	// Assign board index
	spawnedTile->BoardIndex = boardIndex;
	return spawnedTile;
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
}

void AChessBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult hitResult;
	if (
		this->Controller->GetHitResultUnderCursor(
			ECollisionChannel::ECC_Visibility,
			false,
			hitResult
		)
	) {
		AActor* hitActor = hitResult.GetActor();

		if (hitActor != NULL)
		{
			UE_LOG(LogTemp, Log, TEXT("%s"), *hitActor->GetName());
		}
	}
}

AChessBoard::AChessBoard()
{
	this->SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(this->SceneComponent);

	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	this->PrimaryActorTick.bCanEverTick = true;
	this->PrimaryActorTick.bStartWithTickEnabled = true;
}
