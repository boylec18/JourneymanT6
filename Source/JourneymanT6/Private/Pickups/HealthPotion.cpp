// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/HealthPotion.h"
#include "TestingCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"






void AHealthPotion::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnSphereOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	
	OverlappedActor = OtherActor;
	

	if (OverlappedActor->ActorHasTag("Player"))
	{
		if (CurrentHealth < MaxHealth)
		{
			Heal();
			IsHealing = true;
		}
		
	}
	

}

void AHealthPotion::Heal()
{
	
		UGameplayStatics::PlaySound2D(GetWorld(), PickupSound);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), PickupVFX, GetActorLocation());
		IsHealing = false;
		
}
