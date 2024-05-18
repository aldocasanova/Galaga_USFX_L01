// Fill out your copyright notice in the Description page of Project Settings.


#include "CanonBala.h"
#include "Galaga_USFX_L01Projectile.h"
#include "Galaga_USFX_L01GameMode.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProyectilEnemigo.h"
#include "Bomb.h"
#include "Kismet/GameplayStatics.h"

ACanonBala::ACanonBala()
{
	PrimaryActorTick.bCanEverTick = true;

    MaxProjectile = 4;
    NumberFired = 0;

    bCanFire = true; // Permitir disparos al principio
}

void ACanonBala::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Disparar();
}

void ACanonBala::Disparar()
{
    if (bCanFire && NumberFired < MaxProjectile)
    {
        bCanFire = false;  // Prevenir nuevos disparos hasta que el temporizador expire

        // creador de bombas
        UWorld* const World = GetWorld();
        if (World != NULL)
        {
            FVector Location = GetActorLocation();
            FRotator Rotation = GetActorRotation();
            World->SpawnActor<ABomb>(Location, Rotation);
            NumberFired++;

            // Establecer el temporizador para el próximo disparo
            FTimerHandle TimerHandle;
            GetWorldTimerManager().SetTimer(TimerHandle, this, &ACanonBala::ResetFire, rand() % 6 + 1, false);
        }
    }
}

void ACanonBala::ResetFire()
{
    if (NumberFired < MaxProjectile)
    {
        bCanFire = true;  // Permitir el siguiente disparo
        Disparar();         // Disparar automáticamente la siguiente bomba
    }
    else
    {
        NumberFired = 0;   // Reiniciar el contador de bombas para el próximo ciclo de disparos reabastecido
        bCanFire = false;
    }
}

