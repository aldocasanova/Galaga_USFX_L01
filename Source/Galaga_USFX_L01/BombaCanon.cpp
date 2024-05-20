// Fill out your copyright notice in the Description page of Project Settings.


#include "BombaCanon.h"
#include "Kismet/GameplayStatics.h"



// Sets default values
ABombaCanon::ABombaCanon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	velocidad = 9;

	TiempoExplosion = 0.0f;
	TiempoVuelo = 0.0f;
	bInitialized = false;
}

// Called when the game starts or when spawned
void ABombaCanon::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABombaCanon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TiempoExplosion += DeltaTime; // Incremento sincronizado con el tiempo del mundo
	Desaparecer(TiempoExplosion);
	Mover(DeltaTime);

}

void ABombaCanon::Mover(float DeltaTime)
{
	if (!bInitialized)
	{
		FVector StartLocation = GetActorLocation();
		FVector EndLocation = UltimaPosicionJugador;

		float TotalTime = 4.0f; // Tiempo total de vuelo en segundos
		float Gravity = -980.0f; // Aceleración debido a la gravedad (cm/s^2)

		// Calcular la velocidad inicial necesaria
		FVector Direction = (EndLocation - StartLocation);
		FVector HorizontalDirection = FVector(Direction.X, Direction.Y, 0.0f);
		float HorizontalDistance = HorizontalDirection.Size();
		float InitialHorizontalSpeed = HorizontalDistance / TotalTime;

		float VerticalDistance = EndLocation.Z - StartLocation.Z;
		float InitialVerticalSpeed = (VerticalDistance - 0.5f * Gravity * FMath::Square(TotalTime)) / TotalTime;

		InitialVelocity = HorizontalDirection.GetSafeNormal() * InitialHorizontalSpeed;
		InitialVelocity.Z = InitialVerticalSpeed;

		bInitialized = true;
	}
	float Gravity = -980.0f; // Aceleración debido a la gravedad (cm/s^2
	// Actualizar la posición del proyectil
	FVector NewLocation = GetActorLocation();
	NewLocation += InitialVelocity * DeltaTime;
	InitialVelocity.Z += Gravity * DeltaTime; // Aplicar gravedad a la velocidad vertical

	SetActorLocation(NewLocation);
}

void ABombaCanon::Desaparecer(float _TiempoExplosion)
{
	if (_TiempoExplosion >= 12.0f)
	{
		Destroy();
	}

}

void ABombaCanon::SetUltimaPosicionJugador(FVector Posicion)
{
	UltimaPosicionJugador = Posicion;
}

