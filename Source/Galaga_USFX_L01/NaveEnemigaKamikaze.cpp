// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaKamikaze.h"
#include "NaveEnemigaManager.h"
#include "EngineUtils.h"
// Sets default values
ANaveEnemigaKamikaze::ANaveEnemigaKamikaze()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Vida = 10;

}

// Called every frame
void ANaveEnemigaKamikaze::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANaveEnemigaKamikaze::Mover(float DeltaTime)
{
	ANaveEnemiga::Mover(DeltaTime);
}

void ANaveEnemigaKamikaze::RecibirDanio()
{
	ANaveEnemiga::RecibirDanio();
}

void ANaveEnemigaKamikaze::Desplazamiento(float DeltaTime)
{
	ANaveEnemiga::Desplazamiento(DeltaTime);
}

void ANaveEnemigaKamikaze::Disparar()
{
	ANaveEnemiga::Disparar();
}


