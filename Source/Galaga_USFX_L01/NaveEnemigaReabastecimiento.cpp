// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaReabastecimiento.h"
#include "NaveEnemigaManager.h"
#include "EngineUtils.h"

// Sets default values
ANaveEnemigaReabastecimiento::ANaveEnemigaReabastecimiento()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Vida = 40;

	GetActorRelativeScale3D();
	SetActorScale3D(FVector(0.5f, 0.5f, 0.5f));

}

void ANaveEnemigaReabastecimiento::RecibirDanio()
{
	ANaveEnemiga::RecibirDanio();
}

// Called every frame
void ANaveEnemigaReabastecimiento::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANaveEnemigaReabastecimiento::Mover(float DeltaTime)
{
	ANaveEnemiga::Mover(DeltaTime);
}


void ANaveEnemigaReabastecimiento::Desplazamiento(float DeltaTime)
{
	ANaveEnemiga::Desplazamiento(DeltaTime);
}


