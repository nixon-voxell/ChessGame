#include "PieceItem.h"

// Called when the game starts or when spawned
void APieceItem::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APieceItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

APieceItem::APieceItem()
{
	PrimaryActorTick.bCanEverTick = false;
}
