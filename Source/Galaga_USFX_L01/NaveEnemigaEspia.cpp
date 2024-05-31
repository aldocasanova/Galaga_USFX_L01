// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspia.h"
#include "NaveEnemigaManager.h"
#include "EngineUtils.h"
// Sets default values
ANaveEnemigaEspia::ANaveEnemigaEspia()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Vida = 20;

}

void ANaveEnemigaEspia::RecibirDanio()
{
	ANaveEnemiga::RecibirDanio();
}

void ANaveEnemigaEspia::Mover(float DeltaTime)
{
	ANaveEnemiga::Mover(DeltaTime);
}

void ANaveEnemigaEspia::Desplazamiento(float DeltaTime)
{
	ANaveEnemiga::Desplazamiento(DeltaTime);
}

// Called every frame
void ANaveEnemigaEspia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

