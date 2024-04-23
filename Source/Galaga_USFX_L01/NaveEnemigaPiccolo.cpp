// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaPiccolo.h"

//StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe_90.Shape_Pipe_90'

ANaveEnemigaPiccolo::ANaveEnemigaPiccolo()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Tube.Shape_Tube'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ANaveEnemigaPiccolo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaPiccolo::Mover(float DeltaTime)
{
	velocidad = 0.85; //0.25
	SetActorLocation(FVector(GetActorLocation().X - velocidad, GetActorLocation().Y, GetActorLocation().Z));

	if (GetActorLocation().X < LimiteInferiorX) {

		SetActorLocation(FVector(800.0f, GetActorLocation().Y, 250.0f));
		//agregar me'todo para que vuelvan a su posicion mediante el movimientyo de entrada

	}

}

void ANaveEnemigaPiccolo::Destruirse()
{
}

void ANaveEnemigaPiccolo::Desplazamiento()
{
}
