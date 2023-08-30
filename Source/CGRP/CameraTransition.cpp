#include "CameraTransition.h"




// Sets default values
ACameraTransition::ACameraTransition()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    SplineComponent = CreateDefaultSubobject<USplineComponent>("Spline");
    SplineComponent->SetupAttachment(GetRootComponent());

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
    CameraComponent->SetupAttachment(SplineComponent);

}

// Called when the game starts or when spawned
void ACameraTransition::BeginPlay()
{
    Super::BeginPlay();

    const FVector SplineLocation = SplineComponent->GetLocationAtSplinePoint(0, ESplineCoordinateSpace::World);
    CameraComponent->SetWorldLocation(SplineLocation);
    if (bAutoActive)
    {
        MovementTimeline.SetTimelineLengthMode(TL_LastKeyFrame);
        MovementTimeline.PlayFromStart();
    }

    // ...

}

// Called every frame
void ACameraTransition::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);


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


    /*FVector targetLocation = FVector(1400.0, -1150.0, 1600.0);

    APlayerController* playerController = UGameplayStatics::GetPlayerController(this->GetWorld(), 0);
    APawn* pawn = playerController->GetPawn();

    pawn->SetActorLocation(FMath::Lerp(pawn->GetActorLocation(), targetLocation, DeltaTime));
    UE_LOG(LogTemp, Log, TEXT("Actor Location %s"), *pawn->GetActorLocation().ToString());

    FRotator TargetRotation = FRotator(-30.0f, 0.0f, 0.0f);
    float InterpSpeed = 1.5f; // Adjust this to control the speed of the rotation change

    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);

    FRotator CurrentRotation = PlayerController->GetControlRotation();
    FRotator NewRotation = FMath::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, InterpSpeed);

    PlayerController->SetControlRotation(NewRotation);

    UE_LOG(LogTemp, Log, TEXT("Camera Rotation %s"), *NewRotation.ToString());*/
};

// If button was clicked
void ACameraTransition::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    // Bind an action to an input event (button click)
    
};

