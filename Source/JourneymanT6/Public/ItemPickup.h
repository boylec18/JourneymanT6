// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemPickup.generated.h"

class UStaticMeshComponent;
class USphereComponent;

UCLASS()
class JOURNEYMANT6_API AItemPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemPickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "StaticMesh")
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnyWhere, Category = "HitBox")
		USphereComponent* SphereCollision;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnEventBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
