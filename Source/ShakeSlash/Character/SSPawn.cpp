#include "SSPawn.h"
#include "Camera/CameraComponent.h"
#include "MotionControllerComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "ShaderPrintParameters.h"
#include "Animation/AnimInstance.h"
#include "AnimInstance/SSHandAnimInstance.h"

ASSPawn::ASSPawn()
{
    PrimaryActorTick.bCanEverTick = true;

    VRRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VRRoot"));
    RootComponent = VRRoot;

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(VRRoot);

    LeftController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("LeftController"));
    LeftController->SetupAttachment(VRRoot);
    LeftController->SetTrackingSource(EControllerHand::Left);

    RightController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("RightController"));
    RightController->SetupAttachment(VRRoot);
    RightController->SetTrackingSource(EControllerHand::Right);

    LeftHandMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("LeftHandMesh"));
    LeftHandMesh->SetupAttachment(LeftController);

    RightHandMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("RightHandMesh"));
    RightHandMesh->SetupAttachment(RightController);
}

void ASSPawn::BeginPlay()
{
    Super::BeginPlay();

    LeftHandAnim = Cast<USSHandAnimInstance>(LeftHandMesh->GetAnimInstance());
    RightHandAnim = Cast<USSHandAnimInstance>(RightHandMesh->GetAnimInstance());
    
    // Enhanced Input 적용
    if (APlayerController* PC = Cast<APlayerController>(GetController()))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
        {
            Subsystem->AddMappingContext(InputMapping, 0);
        }
    }
}

void ASSPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
    if (EnhancedInput)
    {
        EnhancedInput->BindAction(IA_GrabPressedLeft, ETriggerEvent::Triggered, this, &ASSPawn::SetLeftHandState);
        EnhancedInput->BindAction(IA_GrabPressedRight, ETriggerEvent::Triggered, this, &ASSPawn::SetRightHandState);
    }
}

void ASSPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ASSPawn::SetLeftHandState(const FInputActionValue& Value)
{
    float AxisValue = Value.Get<float>();
    
    UE_LOG(LogTemp, Warning, TEXT("yoo Left Hand GRAB Value %f"), AxisValue);
    
    if (IsValid(LeftHandAnim))
    {
        LeftHandAnim->GrabStregth = AxisValue;
    }
}

void ASSPawn::SetRightHandState(const FInputActionValue& Value)
{
    float AxisValue = Value.Get<float>();
    
    UE_LOG(LogTemp, Warning, TEXT("yoo Right Hand GRAB Value %f"), AxisValue);

    if (IsValid(RightHandAnim))
    {
        
    }
}