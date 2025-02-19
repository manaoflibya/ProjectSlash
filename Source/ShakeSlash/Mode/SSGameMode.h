// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "SSGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SHAKESLASH_API ASSGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ASSGameMode();
	
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void EnableVR();
};
