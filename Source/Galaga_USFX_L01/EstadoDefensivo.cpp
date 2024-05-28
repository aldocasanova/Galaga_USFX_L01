// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoDefensivo.h"
#include "NaveEnemigaNodriza.h"
#include "BombaCanon.h"
#include "Escudo.h"
#include "Kismet/GameplayStatics.h"
#include "Galaga_USFX_L01Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AEstadoDefensivo::AEstadoDefensivo()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    MaxProjectile = 8;
    NumberFired = 0;

    bCanFire = true; // Permitir disparos al principio

    TiempoDisparo = 4.0f;
}

// Called when the game starts or when spawned
void AEstadoDefensivo::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void AEstadoDefensivo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void AEstadoDefensivo::SetNaveNodriza(ANaveEnemigaNodriza* _NaveNodriza)
{
    NaveNodriza = Cast<ANaveEnemigaNodriza>(_NaveNodriza);
    NaveNodriza->EstablecerEstados(NaveNodriza->GetEstadoDefensivo());
    //NaveNodriza->CrearEscudo();
}

void AEstadoDefensivo::Disparar()
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
            FVector Location = NaveNodriza->GetActorLocation();
            FRotator Rotation = NaveNodriza->GetActorRotation();
            ABombaCanon* Bala = World->SpawnActor<ABombaCanon>(Location, Rotation);
            if (Bala)
            {
                Bala->SetUltimaPosicionJugador(UltimaPosicionJugador); // Pasar la posici�n del jugador al proyectil
            }
            NumberFired++;

            // Establecer el temporizador para el pr�ximo disparo
            FTimerHandle TimerHandle;
            GetWorldTimerManager().SetTimer(TimerHandle, this, &AEstadoDefensivo::ResetFire, TiempoDisparo, false); //cambiar cada cuantoo habr�n bombas
        }
    }
}

void AEstadoDefensivo::ResetFire()
{
    bCanFire = true;

}

void AEstadoDefensivo::CrearEscudo()
{
    // Crear un escudo alrededor de la nave nodriza
    UWorld* const World = GetWorld();
    if (World != NULL)
    {
        // Se crean 2 escudos adelante y atras
        FVector Location = NaveNodriza->GetActorLocation();
        Location = Location + FVector(100.0f, 0.0f, 0.0f);
        FRotator Rotation = GetActorRotation();
        for (int i = 0; i < 2; i++)
        {
            AEscudo* Escudo = World->SpawnActor<AEscudo>(Location, Rotation);
            Location = Location + FVector(-200.0f, 0.0f, 0.0f);
        }
        // Se crean 2 escudos de izquierda a derecha
        Location = Location + FVector(300.0f, 100.0f, 0.0f);
        Rotation = FRotator(0.0f, 90.0f, 0.0f);
        for (int i = 0; i < 2; i++)
        {
            AEscudo* Escudo = World->SpawnActor<AEscudo>(Location, Rotation);
            Location = Location + FVector(0.0f, -200.0f, 0.0f);
        }

    }

}









