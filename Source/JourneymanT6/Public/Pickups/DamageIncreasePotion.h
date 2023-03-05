// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemPickup.h"
#include "DamageIncreasePotion.generated.h"

/**
 * 
 */
UCLASS()
class JOURNEYMANT6_API ADamageIncreasePotion : public AItemPickup
{
	GENERATED_BODY()

		virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
	AActor* OverlappedPlayer;

};
