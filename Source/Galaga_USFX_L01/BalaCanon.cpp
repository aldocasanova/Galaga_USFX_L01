// Fill out your copyright notice in the Description page of Project Settings.


#include "BalaCanon.h"
#include "Kismet/GameplayStatics.h"


ABalaCanon::ABalaCanon()
{
	PrimaryActorTick.bCanEverTick = true;
	bInitialized = false;
	velocidad = 600.0f; //600
}

void ABalaCanon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TiempoExplosion += DeltaTime;
	Desaparecer(TiempoExplosion);
	Mover(DeltaTime);
}

void ABalaCanon::BeginPlay()
{
	Super::BeginPlay();
}

void ABalaCanon::Mover(float DeltaTime)
{
	if (!bInitialized)
	{
		FVector StartLocation = GetActorLocation();
		FVector EndLocation = UltimaPosicionJugador;

		// Ajustar la altura en Z para mantenerla constante
		StartLocation.Z = 250.0f;
		EndLocation.Z = 250.0f;

		// Calcular la dirección normalizada desde el cañón hasta el jugador
		Direction = (EndLocation - StartLocation).GetSafeNormal();
		bInitialized = true;
	}

	// Mover el proyectil en línea recta hacia el jugador manteniendo constante la altura en Z
	FVector NewLocation = GetActorLocation() + Direction * velocidad * DeltaTime;
	NewLocation.Z = 250.0f; // Mantener constante la altura en Z

	SetActorLocation(NewLocation);
}

void ABalaCanon::Desaparecer(float _TiempoExplosion)
{
	if (_TiempoExplosion > 7.0f)
	{
		Destroy();
	}
}

void ABalaCanon::SetUltimaPosicionJugador(FVector Posicion)
{
	UltimaPosicionJugador = Posicion;
}
