// Fill out your copyright notice in the Description page of Project Settings.


#include "SSPawn.h"
#include "MotionControllerComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
ASSPawn::ASSPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// VR 카메라 설정
	VRCamera = CreateDefaultSubobject<UCameraComponent>(CameraName);
	VRCamera->SetupAttachment(RootComponent);

	// 왼손 및 오른손 컨츠롤러 추가
	LeftController = CreateDefaultSubobject<UMotionControllerComponent>(LeftControllerName);
	LeftController->SetupAttachment(RootComponent);
	LeftController->SetTrackingSource(EControllerHand::Left);
	RightController = CreateDefaultSubobject<UMotionControllerComponent>(RightControllerName);
	RightController->SetupAttachment(RootComponent);
	RightController->SetTrackingSource(EControllerHand::Right); 
}

// Called when the game starts or when spawned
void ASSPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASSPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASSPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

