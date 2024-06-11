// Fill out your copyright notice in the Description page of Project Settings.


#include "Jungla.h"
#include "Pilar.h"
#include "Arbusto.h"
// Sets default values
AJungla::AJungla()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AJungla::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJungla::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AJungla::Spawn(UWorld* World, FVector SpawnLocation)
{
	for (auto& Pair : Elementos)
	{
		Pair.Key->Spawn(World, Pair.Value);
	}
}

void AJungla::AgregarElemento(IFieldElement* Elemento, FVector Position)
{
	Elementos.Add(TPair<IFieldElement*, FVector>(Elemento, Position));
}


