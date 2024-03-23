// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodriza.h"
#include "ProyectilEnemigo.h"


// Sets default values
ANaveEnemigaNodriza::ANaveEnemigaNodriza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
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
	velocidad = 0.35; //0.25
	SetActorLocation(FVector(GetActorLocation().X - velocidad, GetActorLocation().Y, GetActorLocation().Z));

	if (GetActorLocation().X < LimiteInferiorX) {

		SetActorLocation(FVector(600.0f, GetActorLocation().Y, 250.0f));

	}

}


void ANaveEnemigaNodriza::Disparar() {

}

void ANaveEnemigaNodriza::Destruirse()
{
}

void ANaveEnemigaNodriza::Escapar()
{
}


