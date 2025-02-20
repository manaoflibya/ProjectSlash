// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "SSPawn.generated.h"

UENUM(BlueprintType)
enum class EHandState : uint8
{
	Open     UMETA(DisplayName = "Open"),
	Fist     UMETA(DisplayName = "Fist"),
	Grab     UMETA(DisplayName = "Grab"),
	Pointing UMETA(DisplayName = "Pointing")
};


UCLASS()
class SHAKESLASH_API ASSPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASSPawn();


protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VR")
	class USceneComponent* VRRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VR")
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VR")
	class UMotionControllerComponent* LeftController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VR")
	class UMotionControllerComponent* RightController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VR")
	class USkeletalMeshComponent* LeftHandMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VR")
	class USkeletalMeshComponent* RightHandMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VR")
	EHandState LeftHandState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VR")
	EHandState RightHandState;
	
	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "VR")
	float LeftGrabValue;
	
	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "VR")
	float RightGrabValue;
	
	// Enhanced Input 설정
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	class UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	class UInputAction* IA_GrabPressedLeft;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	class UInputAction* IA_GrabPressedRight;
	
	TObjectPtr<class USSHandAnimInstance> LeftHandAnim;
	TObjectPtr<class USSHandAnimInstance> RightHandAnim;
	
	void SetLeftHandState(const FInputActionValue& Value);
	void SetRightHandState(const FInputActionValue& Value);
	
	
private:
	FName CameraName = TEXT("VRCamera");
	FName LeftControllerName = TEXT("LeftController");
	FName RightControllerName = TEXT("RightController");
};

