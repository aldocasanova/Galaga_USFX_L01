// Fill out your copyright notice in the Description page of Project Settings.


#include "FacadeCanon.h"
#include "CanonBalaNv1.h"
#include "CanonLazerNv1.h"
#include "CanonBombaNv1.h"
#include "CanonHieloNv1.h"
#include "CanonBalaNv2.h"
#include "CanonLazerNv2.h"
#include "CanonBombaNv2.h"
#include "CanonHieloNv2.h"
#include "CanonBalaNv3.h"
#include "CanonLazerNv3.h"
#include "CanonBombaNv3.h"
#include "CanonHieloNv3.h"

// Sets default values
AFacadeCanon::AFacadeCanon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Inicializar las coordenadas
    TopLeftCorner = FVector(-1000.f, -1000.f, 250.f);
    TopRightCorner = FVector(1000.f, -1000.f, 250.f);
    DownLeftCorner = FVector(-1000.f, 1000.f, 250.f);
    DownRightCorner = FVector(1000.f, 1000.f, 250.f);

    // Inicializar el nivel actual y el intervalo de tiempo
    NivelInicial = 1;
    IntervaloNivel = 5.0f; // Aumentar el nivel cada 60 segundos
    MaxNivel = 3; // Establecer el nivel máximo permitido
}

// Called when the game starts or when spawned
void AFacadeCanon::BeginPlay()
{
	Super::BeginPlay();

	SpawnCanons(NivelInicial);

    // Iniciar el temporizador para aumentar el nivel de los cañones
    GetWorldTimerManager().SetTimer(IntervaloNivelimerHandle, this, &AFacadeCanon::IncreaseNivel, IntervaloNivel, true);
}

void AFacadeCanon::SpawnCanons(int32 Nivel)
{

    TSubclassOf<AModeloCanon> BalaClass;
    TSubclassOf<AModeloCanon> LazerClass;
    TSubclassOf<AModeloCanon> BmbaClass;
    TSubclassOf<AModeloCanon> HieloClass;

    // Determinar las clases de cañones según el nivel
    switch (Nivel)
    {
    case 1:
        BalaClass = ACanonBalaNv1::StaticClass();
        LazerClass = ACanonLazerNv1::StaticClass();
        BmbaClass = ACanonBombaNv1::StaticClass();
        HieloClass = ACanonHieloNv1::StaticClass();
        break;
    case 2:
        BalaClass = ACanonBalaNv2::StaticClass();
        LazerClass = ACanonLazerNv2::StaticClass();
        BmbaClass = ACanonBombaNv2::StaticClass();
        HieloClass = ACanonHieloNv2::StaticClass();
        break;
    case 3:
        BalaClass = ACanonBalaNv3::StaticClass();
        LazerClass = ACanonLazerNv3::StaticClass();
        BmbaClass = ACanonBombaNv3::StaticClass();
        HieloClass = ACanonHieloNv3::StaticClass();
        break;
    default:
        // Nivel por defecto o error
        return;
    }

    // Spawnear los cañones en las ubicaciones correspondientes
    SpawnCanon(BalaClass, TopLeftCorner);
    SpawnCanon(LazerClass, TopRightCorner);
    SpawnCanon(BmbaClass, DownLeftCorner);
    SpawnCanon(HieloClass, DownRightCorner);
}

// Called every frame
void AFacadeCanon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFacadeCanon::SpawnCanon(TSubclassOf<AModeloCanon> CanonClass, FVector Location)
{
 
    if (GetWorld())
    {
        FActorSpawnParameters SpawnParams;
        GetWorld()->SpawnActor<AModeloCanon>(CanonClass, Location, FRotator::ZeroRotator, SpawnParams);
    }

}


void AFacadeCanon::IncreaseNivel()
{
    // Incrementar el nivel de los cañones
    NivelInicial++;

    // Si el nivel alcanza el máximo, reiniciar a 1
    if (NivelInicial > MaxNivel)
    {
        NivelInicial = 1;
    }

    // Spawnear los cañones con el nuevo nivel
    SpawnCanons(NivelInicial);
}

