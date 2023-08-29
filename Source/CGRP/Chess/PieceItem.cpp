#include "PieceItem.h"

void APieceItem::Initialize(int32 Index)
{
	this->BoardIndex = Index;
	this->OriginBoardIndex = Index;
}

bool APieceItem::IsAtOrigin()
{
	return this->BoardIndex == this->OriginBoardIndex;
}

void APieceItem::BeginPlay()
{
	Super::BeginPlay();
}

void APieceItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

APieceItem::APieceItem()
{
	PrimaryActorTick.bCanEverTick = false;
}
