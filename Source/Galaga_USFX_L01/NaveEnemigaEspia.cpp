// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspia.h"

// Sets default values
ANaveEnemigaEspia::ANaveEnemigaEspia()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ANaveEnemigaEspia::Mover(float DeltaTime)
{
	velocidad = 1;
	SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z));
}

void ANaveEnemigaEspia::Destruirse()
{
}

// Called every frame
void ANaveEnemigaEspia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

