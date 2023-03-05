// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Coins.generated.h"


class UStaticMeshComponent;
class USphereComponent;


UCLASS()
class JOURNEYMANT6_API ACoins : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoins();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditDefaultsOnly, Category = "StaticMesh")
		UStaticMeshComponent* CoinMesh;

	UPROPERTY(VisibleAnywhere, Category = "HitBox")
		USphereComponent* SphereCollision;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TargetActor")
		AActor* TargetActor;

	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditDefaultsOnly, Category = "MovementSpeed")
	float InterpSpeed = 3;

	AActor* OverlappedActor;

	AActor* Parent = nullptr;

	float WaitTime = 1;

};
