// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SSHandAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SHAKESLASH_API USSHandAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HandAnimation)
	float GrabStregth;
	
};
