// Fill out your copyright notice in the Description page of Project Settings.


#include "Galaxia.h"

// Sets default values
AGalaxia::AGalaxia()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGalaxia::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGalaxia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGalaxia::Spawn(UWorld* World, FVector SpawnLocation)
{
	for (auto& Pair : Elementos)
	{
		Pair.Key->Spawn(World, Pair.Value);
	}
}

void AGalaxia::AgregarElemento(IFieldElement* Elemento, FVector Position)
{
	Elementos.Add(TPair<IFieldElement*, FVector>(Elemento, Position));
}

