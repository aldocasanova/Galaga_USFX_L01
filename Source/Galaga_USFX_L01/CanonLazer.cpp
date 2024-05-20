// Fill out your copyright notice in the Description page of Project Settings.


#include "CanonLazer.h"
#include "Galaga_USFX_L01Projectile.h"
#include "Galaga_USFX_L01GameMode.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProyectilEnemigo.h"
#include "Bomb.h"
#include "LazerEnemigo.h"
#include "Kismet/GameplayStatics.h"

ACanonLazer::ACanonLazer()
{
    PrimaryActorTick.bCanEverTick = true;

    MaxProjectile = 4;
    NumberFired = 0;

    bCanFire = true; // Permitir disparos al principio
}

void ACanonLazer::Disparar()
{
    if (bCanFire && NumberFired < MaxProjectile)
    {
        bCanFire = true;  // Prevenir nuevos disparos hasta que el temporizador expire

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
            ALazerEnemigo* Lazer = World->SpawnActor<ALazerEnemigo>(Location, Rotation);
            if (Lazer)
            {
                Lazer->SetUltimaPosicionJugador(UltimaPosicionJugador); // Pasar la posición del jugador al proyectil
            }
            NumberFired++;

            // Establecer el temporizador para el próximo disparo
            FTimerHandle TimerHandle;
            GetWorldTimerManager().SetTimer(TimerHandle, this, &ACanonLazer::ResetFire, rand() % 6 + 1, false); //cambiar cada cuantoo habrán bombas
        }
    }
}

void ACanonLazer::ResetFire()
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

void ACanonLazer::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Disparar();
}


