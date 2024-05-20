// Fill out your copyright notice in the Description page of Project Settings.


#include "LazerEnemigo.h"
#include "Kismet/GameplayStatics.h"

ALazerEnemigo::ALazerEnemigo()
{
	PrimaryActorTick.bCanEverTick = true;
	bInitialized = false;
	velocidad = 600.0f; //600
}

void ALazerEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TiempoExplosion += DeltaTime;
	Desaparecer(TiempoExplosion);
	Mover(DeltaTime);
}

void ALazerEnemigo::Mover(float DeltaTime)
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

void ALazerEnemigo::Desaparecer(float _TiempoExplosion)
{
	if (_TiempoExplosion > 7.0f)
	{
		Destroy();
	}
}

void ALazerEnemigo::BeginPlay()
{
	Super::BeginPlay();
}

void ALazerEnemigo::SetUltimaPosicionJugador(FVector Posicion)
{
	UltimaPosicionJugador = Posicion;
}
