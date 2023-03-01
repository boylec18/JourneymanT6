// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/SpeedPotion.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "NiagaraComponent.h"



void ASpeedPotion::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	OverlappedActor = OtherActor;
	b_IsSpeedBoost = true;

}

void ASpeedPotion::SpeedBoost()
{
	if (OverlappedActor->ActorHasTag("Player"))
	{
		UGameplayStatics::PlaySound2D(GetWorld(), PickupSound);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), PickupVFX, GetActorLocation());
		
	}
}

void ASpeedPotion::EndSpeedBoost()
{
	b_IsSpeedBoost = false;
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("CalledEndSpeedBoost"));
}
