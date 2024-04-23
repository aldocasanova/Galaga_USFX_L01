// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaKamikaze.h"

// Sets default values
ANaveEnemigaKamikaze::ANaveEnemigaKamikaze()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called every frame
void ANaveEnemigaKamikaze::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
	Desplazamiento(DeltaTime);
}

void ANaveEnemigaKamikaze::Mover(float DeltaTime)
{
	velocidad = 0.85;  //1
	SetActorLocation(FVector(GetActorLocation().X - velocidad, GetActorLocation().Y, GetActorLocation().Z));

	if (GetActorLocation().X < LimiteInferiorX) {

		SetActorLocation(FVector(800.0f, GetActorLocation().Y, 250.0f));

	}

}


void ANaveEnemigaKamikaze::Destruirse()
{
}

void ANaveEnemigaKamikaze::Desplazamiento(float DeltaTime)
{
	AmplitudK = 2.0f;
	VelocidadK = 5.0f;

	FVector NewLocation = FVector(GetActorLocation().X + AmplitudK * FMath::Cos(VelocidadK * GetWorld()->GetTimeSeconds()), GetActorLocation().Y, GetActorLocation().Z);
	SetActorLocation(NewLocation);
}


