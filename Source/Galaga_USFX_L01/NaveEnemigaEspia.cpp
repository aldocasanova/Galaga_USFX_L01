// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspia.h"

// Sets default values
ANaveEnemigaEspia::ANaveEnemigaEspia()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ANaveEnemigaEspia::Mover(float DeltaTime)
{
	velocidad = 0.50; //0.60
	SetActorLocation(FVector(GetActorLocation().X - velocidad, GetActorLocation().Y, GetActorLocation().Z));

	if (GetActorLocation().X< LimiteInferiorX) {

		SetActorLocation(FVector(400.0f, GetActorLocation().Y, 250.0f));

	}
	//FVector(200.0f, -1100.0f, 250.0f);
}

void ANaveEnemigaEspia::Destruirse()
{
}

void ANaveEnemigaEspia::Escapar()
{
}

void ANaveEnemigaEspia::Desplazamiento(float DeltaTime)
{
	
}

// Called every frame
void ANaveEnemigaEspia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
	Desplazamiento(DeltaTime);
}

