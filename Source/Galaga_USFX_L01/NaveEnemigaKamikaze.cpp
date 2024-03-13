// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaKamikaze.h"

// Sets default values
ANaveEnemigaKamikaze::ANaveEnemigaKamikaze()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called every frame
void ANaveEnemigaKamikaze::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaKamikaze::Mover(float DeltaTime)
{
	velocidad = 1; // ir cambiando velocidades
	SetActorLocation(FVector(GetActorLocation().X - velocidad, GetActorLocation().Y, GetActorLocation().Z));

}


void ANaveEnemigaKamikaze::Disparar() {

}

void ANaveEnemigaKamikaze::Destruirse()
{
}


