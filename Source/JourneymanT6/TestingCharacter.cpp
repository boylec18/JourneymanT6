// Fill out your copyright notice in the Description page of Project Settings.


#include "TestingCharacter.h"

// Sets default values
ATestingCharacter::ATestingCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestingCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestingCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestingCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Axis Mapping
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATestingCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ATestingCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerYawInput);

	// Action Mapping

}

void ATestingCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector()* AxisValue);
}

void ATestingCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void ATestingCharacter::OnInteract()
{
}

