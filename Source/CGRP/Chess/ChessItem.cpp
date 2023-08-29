#include "ChessItem.h"

void AChessItem::SetOriginMaterial(UMaterial* Material)
{
	this->OriginMaterial = Material;
	this->SetMaterial(Material);
}

void AChessItem::SetMaterial(UMaterial* Material)
{
	this->MeshComponent->SetMaterial(0, Material);
}

void AChessItem::ResetMaterial()
{
	this->SetMaterial(this->OriginMaterial);
}

void AChessItem::BeginPlay()
{
	Super::BeginPlay();

	TArray<UStaticMeshComponent*> meshComps;
	this->GetComponents<UStaticMeshComponent*>(meshComps);
	this->MeshComponent = meshComps[0];
}

void AChessItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

AChessItem::AChessItem()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}
