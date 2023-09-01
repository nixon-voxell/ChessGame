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

	// Get origin material
	TArray<UStaticMeshComponent*> meshComps;
	this->GetComponents<UStaticMeshComponent*>(meshComps);
	this->MeshComponent = meshComps[0];

	// Get origin scale
	this->OriginScale = this->GetActorRelativeScale3D();
	this->TargetScale = this->OriginScale;
}

void AChessItem::ScaleByFactor(double Factor)
{
	this->TargetScale = this->OriginScale * Factor;
}


void AChessItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector scale = this->GetActorRelativeScale3D();

	scale = FMath::Lerp(scale, this->TargetScale, DeltaTime * 10);
	FVector diff = scale - this->TargetScale;

	if (diff.Size() < 0.1)
	{
		this->TargetScale = this->OriginScale;
	}
	this->SetActorRelativeScale3D(scale);
}

AChessItem::AChessItem()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}
