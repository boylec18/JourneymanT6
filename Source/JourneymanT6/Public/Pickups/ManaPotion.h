// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemPickup.h"
#include "ManaPotion.generated.h"

/**
 * 
 */
UCLASS()
class JOURNEYMANT6_API AManaPotion : public AItemPickup
{
	GENERATED_BODY()
	

public:

	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;


	void IncreaseMana();

	AActor* OverlappedActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mana")
		bool B_AddMana;

};
