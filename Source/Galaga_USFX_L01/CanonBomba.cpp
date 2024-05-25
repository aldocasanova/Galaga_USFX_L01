// Fill out your copyright notice in the Description page of Project Settings.


#include "CanonBomba.h"
#include "Galaga_USFX_L01Projectile.h"
#include "Galaga_USFX_L01GameMode.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProyectilEnemigo.h"
#include "Bomb.h"
#include "BombaCanon.h"
#include "Kismet/GameplayStatics.h"

ACanonBomba::ACanonBomba()
{
    PrimaryActorTick.bCanEverTick = true;

    MaxProjectile = 10;
    NumberFired = 0;

    bCanFire = true; // Permitir disparos al principio

	TiempoDisparo = 4.0f;
}

void ACanonBomba::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Disparar();
}

void ACanonBomba::Disparar()
{
    if (bCanFire && NumberFired < MaxProjectile)
    {
        bCanFire = false;  // Prevenir nuevos disparos hasta que el temporizador expire

        // Obtener el jugador
        APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
        if (PlayerPawn)
        {
            UltimaPosicionJugador = PlayerPawn->GetActorLocation(); // Guardar la última posición del jugador
        }

        // creador de bombas
        UWorld* const World = GetWorld();
        if (World != NULL)
        {
            FVector Location = GetActorLocation();
            FRotator Rotation = GetActorRotation();
            ABombaCanon* Bomba = World->SpawnActor<ABombaCanon>(Location, Rotation);
            if (Bomba)
            {
                Bomba->SetUltimaPosicionJugador(UltimaPosicionJugador); // paso la posición del jugador al proyectil
            }
            NumberFired++;

            // Establecer el temporizador para el próximo disparo
            FTimerHandle TimerHandle;
            GetWorldTimerManager().SetTimer(TimerHandle, this, &ACanonBomba::ResetFire, TiempoDisparo, false); //cambiar cada cuantoo habrán bombas
        }
    }

}

void ACanonBomba::ResetFire()
{
    if (NumberFired < MaxProjectile)
    {
        bCanFire = true;  // paso siguiente disparo
        Disparar();         // disparar automáticamente la siguiente bomba
    }
    else
    {
        NumberFired = 0;   // reininiciar el contador de bombas para el próximo ciclo de disparos reabastecido
        bCanFire = false;
    }
}

void ACanonBomba::BeginPlay()
{
	Super::BeginPlay();
}
