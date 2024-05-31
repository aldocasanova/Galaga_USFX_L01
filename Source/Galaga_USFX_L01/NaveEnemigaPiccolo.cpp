// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaPiccolo.h"
#include "NaveEnemigaManager.h"
#include "EngineUtils.h"

//StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe_90.Shape_Pipe_90'

ANaveEnemigaPiccolo::ANaveEnemigaPiccolo()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Tube.Shape_Tube'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Vida = 50;
}

void ANaveEnemigaPiccolo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANaveEnemigaPiccolo::Mover(float DeltaTime)
{
	ANaveEnemiga::Mover(DeltaTime);
}


void ANaveEnemigaPiccolo::Desplazamiento(float DeltaTime)
{
	ANaveEnemiga::Desplazamiento(DeltaTime);
}

void ANaveEnemigaPiccolo::RecibirDanio()
{
	ANaveEnemiga::RecibirDanio();
}
