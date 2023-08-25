#include "ChessItem.h"

// Sets default values
AChessItem::AChessItem()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AChessItem::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AChessItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
