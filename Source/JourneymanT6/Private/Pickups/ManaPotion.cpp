// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/ManaPotion.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

void AManaPotion::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OverlappedActor = OtherActor;
	IncreaseMana();
	B_AddMana = true;

}

void AManaPotion::IncreaseMana()
{
	if (OverlappedActor->ActorHasTag("Player"))
	{
		UGameplayStatics::PlaySound2D(GetWorld(), PickupSound);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), PickupVFX, GetActorLocation());
		B_AddMana = false;
	}

	
}
