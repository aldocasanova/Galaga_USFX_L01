// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodriza.h"

// Sets default values
ANaveEnemigaNodriza::ANaveEnemigaNodriza()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called every frame
void ANaveEnemigaNodriza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaNodriza::Mover(float DeltaTime)
{
	velocidad = 1;
	SetActorLocation(FVector(GetActorLocation().X - velocidad, GetActorLocation().Y, GetActorLocation().Z));

}


void ANaveEnemigaNodriza::Disparar() {

}

void ANaveEnemigaNodriza::Destruirse()
{
}


