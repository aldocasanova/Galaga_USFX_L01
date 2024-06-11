#include "NaveEnemigaCaza.h"
#include "Galaga_USFX_L01Projectile.h"
#include "Galaga_USFX_L01GameMode.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProyectilEnemigo.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));
    mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

    // Cache our sound effect
    static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
    FireSound = FireAudio.Object;

    PrimaryActorTick.bCanEverTick = true;

    FireRate = 4.0f; // Intervalo de tiempo entre disparos en segundos
    FireRate = rand() % 4 + 1; // Intervalo de tiempo entre disparos en segundos, formula 

    MaxShots = 3; // Cantidad máxima de disparos
    ShotsFired = 0; // Inicializar contador de disparos

    bCanFire = true; // Permitir disparos al principio

    Vida = 30;
}

void ANaveEnemigaCaza::Disparar()
{
    ANaveEnemiga::Disparar();
}

void ANaveEnemigaCaza::RecibirDanio()
{
	ANaveEnemiga::RecibirDanio();
}

void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    /*Mover(DeltaTime);
    Disparar();
    Desplazamiento(DeltaTime);*/
}

void ANaveEnemigaCaza::Mover(float DeltaTime)
{
    ANaveEnemiga::Mover(DeltaTime);
}



void ANaveEnemigaCaza::Desplazamiento(float DeltaTime)
{
    ANaveEnemiga::Desplazamiento(DeltaTime);
}


