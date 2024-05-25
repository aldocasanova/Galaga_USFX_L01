// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoOfensivo.h"

// Sets default values
AEstadoOfensivo::AEstadoOfensivo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstadoOfensivo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoOfensivo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoOfensivo::EstadoOfensivo()
{
}

void AEstadoOfensivo::EstadoDefensivo()
{
}

void AEstadoOfensivo::EstadoDebil()
{
}

void AEstadoOfensivo::SetNaveNodrizaState(NaveNodriza* NaveNodriza)
{
}

