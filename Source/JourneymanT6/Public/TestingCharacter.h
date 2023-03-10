// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TestingCharacter.generated.h"




UCLASS()
class JOURNEYMANT6_API ATestingCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATestingCharacter();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly ,Category = "Survival")
		float CurrentHealth;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly ,Category = "Survival")
		float MaxHealth = 3;

	void HealPlayer();

	


private:

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void OnInteract();

};
