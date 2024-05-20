// Fill out your copyright notice in the Description page of Project Settings.


#include "CanonBala.h"
#include "Galaga_USFX_L01Projectile.h"
#include "Galaga_USFX_L01GameMode.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProyectilEnemigo.h"
#include "Bomb.h"
#include "BalaCanon.h"
#include "Kismet/GameplayStatics.h"

ACanonBala::ACanonBala()
{
	PrimaryActorTick.bCanEverTick = true;

    MaxProjectile = 8;
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

        // Obtener el jugador
        APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
        if (PlayerPawn)
        {
            UltimaPosicionJugador = PlayerPawn->GetActorLocation(); // Guardar la �ltima posici�n del jugador
        }

        // creador de bombas
        UWorld* const World = GetWorld();
        if (World != NULL)
        {
            FVector Location = GetActorLocation();
            FRotator Rotation = GetActorRotation();
            ABalaCanon* Bala = World->SpawnActor<ABalaCanon>(Location, Rotation);
            if (Bala)
            {
                Bala->SetUltimaPosicionJugador(UltimaPosicionJugador); // Pasar la posici�n del jugador al proyectil
            }
            NumberFired++;

            // Establecer el temporizador para el pr�ximo disparo
            FTimerHandle TimerHandle;
            GetWorldTimerManager().SetTimer(TimerHandle, this, &ACanonBala::ResetFire, rand() % 6 + 1, false); //cambiar cada cuantoo habr�n bombas
        }
    }

}

void ACanonBala::ResetFire()
{
    if (NumberFired < MaxProjectile)
    {
        bCanFire = true;  // Permitir el siguiente disparo
        Disparar();         // Disparar autom�ticamente la siguiente bomba
    }
    else
    {
        NumberFired = 0;   // Reiniciar el contador de bombas para el pr�ximo ciclo de disparos reabastecido
        bCanFire = false;
    }
}

