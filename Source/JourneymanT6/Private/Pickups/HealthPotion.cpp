// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/HealthPotion.h"
#include "TestingCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"






void AHealthPotion::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnSphereOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	ATestingCharacter* Player = Cast<ATestingCharacter>(OtherActor);

	
	if (Player->CurrentHealth <= 2.0f)
	{
		Heal();
		Player->HealPlayer();
	}
	
	

}

void AHealthPotion::Heal()
{
	
	UGameplayStatics::PlaySound2D(GetWorld(), PickupSound);
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), PickupVFX, GetActorLocation());
	Destroy();
}
