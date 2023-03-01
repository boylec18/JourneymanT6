// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemPickup.h"
#include "Engine/EngineTypes.h"
#include "TimerManager.h"
#include "SpeedPotion.generated.h"

/**
 * 
 */
UCLASS()
class JOURNEYMANT6_API ASpeedPotion : public AItemPickup
{
	GENERATED_BODY()

protected:

	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	AActor* OverlappedActor;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
		bool b_IsSpeedBoost;

	void SpeedBoost();
	void EndSpeedBoost();

	



	
};
