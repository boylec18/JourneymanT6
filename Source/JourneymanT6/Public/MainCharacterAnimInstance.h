// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class JOURNEYMANT6_API UMainCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

		UPROPERTY(VisibleAnywhere, Category = "MovementSpeed")
		float GroundSpeed;
	
};
