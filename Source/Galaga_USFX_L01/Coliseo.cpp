// Fill out your copyright notice in the Description page of Project Settings.


#include "Coliseo.h"
#include "Escalera.h"
#include "Estatua.h"
// Sets default values
AColiseo::AColiseo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AColiseo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AColiseo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AColiseo::Spawn(UWorld* World, FVector SpawnLocation)
{
    for (auto& Pair : Elementos)
    {
        Pair.Key->Spawn(World, Pair.Value);
    }
}

void AColiseo::AgregarElemento(IFieldElement* Elemento, FVector Position)
{
	Elementos.Add(TPair<IFieldElement*, FVector>(Elemento, Position));
}


