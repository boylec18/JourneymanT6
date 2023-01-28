// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_LongRange.h"

// Sets default values
AAI_LongRange::AAI_LongRange()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAI_LongRange::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	
}

// Called every frame
void AAI_LongRange::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI_LongRange::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

