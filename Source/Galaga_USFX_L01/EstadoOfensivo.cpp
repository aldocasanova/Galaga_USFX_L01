// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoOfensivo.h"
#include "NaveEnemigaNodriza.h"
#include "ProyectilEnemigo.h"
#include "Galaga_USFX_L01Projectile.h"
#include "Galaga_USFX_L01Pawn.h"


// Sets default values
AEstadoOfensivo::AEstadoOfensivo()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GunOffset = FVector(90.f, 0.f, 0.f);
	TiempoDisparo = 0.5f;
	bCanFire = true;
}

// Called when the game starts or when spawned
void AEstadoOfensivo::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AEstadoOfensivo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEstadoOfensivo::SetNaveNodriza(ANaveEnemigaNodriza* _NaveNodriza)
{
	NaveNodriza = Cast<ANaveEnemigaNodriza>(_NaveNodriza);
	NaveNodriza->EstablecerEstados(NaveNodriza->GetEstadoOfensivo());
	//NaveNodriza->DestruirEscudos();

}

void AEstadoOfensivo::Mover(float DeltaTime)
{
	// Definimos las variables necesarias
	static float TiempoTotal = 0.0f; // Variable est�tica para acumular el tiempo
	const float Radio = 300.0f; // Radio del c�rculo
	const float VelocidadAngular = 1.0f; // Velocidad angular (radianes por segundo)

	// Actualizamos el tiempo total acumulado
	TiempoTotal += DeltaTime * VelocidadAngular;

	// Calculamos la nueva posici�n en la circunferencia
	float NuevaPosX = Radio * FMath::Cos(TiempoTotal);
	float NuevaPosY = Radio * FMath::Sin(TiempoTotal);

	// Obtenemos la posici�n actual del objeto
	FVector PosicionActual = NaveNodriza->GetActorLocation();

	// Actualizamos solo las coordenadas X e Y, manteniendo la Z actual
	FVector NuevaPosicion = FVector(NuevaPosX, NuevaPosY, PosicionActual.Z);

	// Establecemos la nueva posici�n del objeto
	NaveNodriza->SetActorLocation(NuevaPosicion);
}

void AEstadoOfensivo::Disparar()
{
	FVector FireDirection = NaveNodriza->GetActorForwardVector();
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				for (int i = 0; i < 8; i++)
				{
					float grado = 360.0f / 8;
					FireDirection = FireDirection.RotateAngleAxis(grado * i, FVector(0.0f, 0.0f, 1.0f));
					const FRotator FireRotation = FireDirection.Rotation();
					const FVector SpawnLocation = NaveNodriza->GetActorLocation() + FireRotation.RotateVector(GunOffset);
					World->SpawnActor<AProyectilEnemigo>(SpawnLocation, FireRotation);
					bCanFire = false;
					World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AEstadoOfensivo::ShotTimerExpired, TiempoDisparo);
				}
			}
			bCanFire = false;
		}
	}
}

void AEstadoOfensivo::ShotTimerExpired()
{
	bCanFire = true;
}

//void AEstadoOfensivo::DestruirEscudos()
//{
//	for (AEscudo* Escudo : Escudos)
//	{
//		if (Escudo)
//		{
//			Escudo->Destroy();
//		}
//	}
//	Escudos.Empty();
//}



