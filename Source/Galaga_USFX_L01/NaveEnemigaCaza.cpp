// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCaza.h"

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

	PrimaryActorTick.bCanEverTick = true;
}


void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaCaza::Mover(float DeltaTime)
{
	velocidad = 1.5;
	SetActorLocation(FVector(GetActorLocation().X - velocidad, GetActorLocation().Y, GetActorLocation().Z));
}


void ANaveEnemigaCaza::Disparar() {

}

void ANaveEnemigaCaza::Destruirse()
{
}


