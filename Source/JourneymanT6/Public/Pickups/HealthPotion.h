// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemPickup.h"
#include "HealthPotion.generated.h"

/**
 * 
 */
UCLASS()
class JOURNEYMANT6_API AHealthPotion : public AItemPickup
{
	GENERATED_BODY()
	

protected:

	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

public:

	UFUNCTION(BlueprintCallable, Category = "Heals")
		void Heal();

protected:

	AActor* OverlappedActor;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
		bool IsHealing;
};
