// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/Coins.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ACoins::ACoins()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>("CoinMesh");
	RootComponent = CoinMesh;

	SphereCollision = CreateDefaultSubobject<USphereComponent>("SphereHitBox");
	SphereCollision->SetupAttachment(GetRootComponent());




}


// Called when the game starts or when spawned
void ACoins::BeginPlay()
{
	Super::BeginPlay();


	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ACoins::OnSphereOverlap);

	PickupDelay = 2;

	
}

// Called every frame
void ACoins::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (WaitTime > 0)
	{
		WaitTime -= DeltaTime;
		return;
	}

	if (!TargetActor)
	{return;}

		SetActorLocation(FMath::VInterpTo(GetActorLocation(), TargetActor->GetActorLocation(), DeltaTime, InterpSpeed));

		PickupDelay -= DeltaTime;

}

void ACoins::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OverlappedActor = OtherActor;

	if (PickupDelay <= 0)
	{
		if (OverlappedActor->ActorHasTag("TestingCharacter"))
		{
			Destroy();
		}
	}

	

		
}

