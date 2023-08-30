#include "CameraMovement.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

void UCameraMovement::MoveCameraToLocation(APlayerController* PlayerController, FVector TargetLocation, float TransitionDuration)
{
    if (PlayerController)
    {
        APlayerCameraManager* CameraManager = PlayerController->PlayerCameraManager;

        if (CameraManager)
        {
            CameraManager->StartCameraFade(0.0f, 1.0f, TransitionDuration, FLinearColor::Black, false, true);

            FViewTargetTransitionParams TransitionParams;
            TransitionParams.BlendTime = TransitionDuration;

            FMinimalViewInfo NewViewInfo;
            NewViewInfo.Location = TargetLocation;

            //CameraManager->SetViewTarget(PlayerController, NewViewInfo, TransitionParams);
            CameraManager->StartCameraFade(1.0f, 0.0f, TransitionDuration, FLinearColor::Black, false, true);
        }
    }
}
