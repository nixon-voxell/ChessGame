#include "CameraTransition.h"
#include "Blueprint/UserWidget.h"




// Sets default values
ACameraTransition::ACameraTransition()
{


}

// Called when the game starts or when spawned
void ACameraTransition::BeginPlay()
{
    Super::BeginPlay();

};

// Called every frame
void ACameraTransition::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

};


void ACameraTransition::CameraMovement1(float DeltaTime)
{
    FVector targetLocation = FVector(1400.0, -1150.0, 1600.0);

    APlayerController* playerController = UGameplayStatics::GetPlayerController(this->GetWorld(), 0);
    APawn* pawn = playerController->GetPawn();

    pawn->SetActorLocation(FMath::Lerp(pawn->GetActorLocation(), targetLocation, DeltaTime));
    UE_LOG(LogTemp, Log, TEXT("Actor Location %s"), *pawn->GetActorLocation().ToString());

    FRotator TargetRotation = FRotator(-30.0f, 90.0f, 0.0f);
    float InterpSpeed = 1.5f; // Adjust this to control the speed of the rotation change

    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);

    FRotator CurrentRotation = PlayerController->GetControlRotation();
    FRotator NewRotation = FMath::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, InterpSpeed);

    PlayerController->SetControlRotation(NewRotation);

    UE_LOG(LogTemp, Log, TEXT("Camera Rotation %s"), *NewRotation.ToString());
}

void ACameraTransition::CameraMovement2(float DeltaTime)
{
    FVector targetLocation = FVector(1400.0, 4000.0, 1600.0);

    APlayerController* playerController = UGameplayStatics::GetPlayerController(this->GetWorld(), 0);
    APawn* pawn = playerController->GetPawn();

    pawn->SetActorLocation(FMath::Lerp(pawn->GetActorLocation(), targetLocation, DeltaTime));
    UE_LOG(LogTemp, Log, TEXT("Actor Location %s"), *pawn->GetActorLocation().ToString());

    FRotator TargetRotation = FRotator(-30.0f, -90.0f, 0.0f);
    float InterpSpeed = 1.5f; // Adjust this to control the speed of the rotation change

    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);

    FRotator CurrentRotation = PlayerController->GetControlRotation();
    FRotator NewRotation = FMath::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, InterpSpeed);

    PlayerController->SetControlRotation(NewRotation);

    UE_LOG(LogTemp, Log, TEXT("Camera Rotation %s"), *NewRotation.ToString());
}


