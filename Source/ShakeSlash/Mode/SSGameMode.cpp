// Fill out your copyright notice in the Description page of Project Settings.


#include "SSGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "SSPawn.h"
#include "Utility/SSLog.h"

ASSGameMode::ASSGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass( TEXT("/Script/Engine.Blueprint'/Game/Game/BP_SSPawn.BP_SSPawn_C'"));
	if (PlayerPawnBPClass.Succeeded())
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ASSGameMode::EnableVR()
{
	// HMD 연결되어 있는지 확인
	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	{
		UHeadMountedDisplayFunctionLibrary::EnableHMD(true);
		UE_LOG(SSLogMode, Warning, TEXT("SSGameMode::EnableVR VR Mode Enabled"));
	}
	else
	{
		UE_LOG(SSLogMode, Warning, TEXT("SSGameMode::Enable VR HMD not found, VR Mode Disabled"));
	}
}

void ASSGameMode::BeginPlay()
{
	Super::BeginPlay();

	EnableVR();
}
