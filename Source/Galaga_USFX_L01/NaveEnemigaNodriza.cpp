// Fill out your copyright notice in the Description page of Project Settings.

#include "NaveEnemigaNodriza.h"
#include "ProyectilEnemigo.h"
#include "NaveNodrizaState.h"
#include "EstadoDefensivo.h"
#include "EstadoOfensivo.h"
#include "EstadoDebil.h"
#include "NaveEnemigaManager.h"
#include "EngineUtils.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ANaveEnemigaNodriza::ANaveEnemigaNodriza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    GetActorRelativeScale3D();
    SetActorScale3D(FVector(1.2f, 1.2f, 1.2f));

    vida = 150;
}

// Called every frame
void ANaveEnemigaNodriza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Disparar();
	Mover(DeltaTime);
}


void ANaveEnemigaNodriza::BeginPlay()
{
	Super::BeginPlay();

	EstadoDefensivo = GetWorld()->SpawnActor<AEstadoDefensivo>(FVector::ZeroVector, FRotator::ZeroRotator);
	EstadoOfensivo = GetWorld()->SpawnActor<AEstadoOfensivo>(FVector::ZeroVector, FRotator::ZeroRotator);
	EstadoDebil = GetWorld()->SpawnActor<AEstadoDebil>(FVector::ZeroVector, FRotator::ZeroRotator);

	InicializarEstadosNaveNodriza();
}

void ANaveEnemigaNodriza::RecibirDanio()
{
	vida -= 10;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Vida: " + FString::SanitizeFloat(vida)));
	if (vida <= 0)
	{
		Destroy();
		for (TActorIterator<ANaveEnemigaManager> It(GetWorld()); It; ++It)
		{
			EnemigasManager = *It;
			break;
		}
		if (EnemigasManager)
		{
			NavesEnemigas = EnemigasManager->GetNavesEnemigasRestantes();
			NavesEnemigas--;
			EnemigasManager->SetNavesEnemigasRestantes(NavesEnemigas);
		}
	}
	InicializarEstadosNaveNodriza();
}

void ANaveEnemigaNodriza::InicializarEstadosNaveNodriza()
{
	if (vida >= 100)
	{
		EstadoDefensivo->SetNaveNodriza(this);
		EstablecerEstados(EstadoDefensivo);
		CrearEscudo();
	}
	else if (vida >= 50 && vida < 100)
	{
		EstadoOfensivo->SetNaveNodriza(this);
		EstablecerEstados(EstadoOfensivo);
	}
	else
	{
		EstadoDebil->SetNaveNodriza(this);
		EstablecerEstados(EstadoDebil);
	}
}

void ANaveEnemigaNodriza::EstablecerEstados(INaveNodrizaState* _Estado)
{
	Estado = _Estado;

}

void ANaveEnemigaNodriza::Mover(float DeltaTime)
{
	Estado->Mover(DeltaTime);
}

void ANaveEnemigaNodriza::Disparar()
{
	Estado->Disparar();
}

void ANaveEnemigaNodriza::CrearEscudo()
{
	Estado->CrearEscudo();
}

INaveNodrizaState* ANaveEnemigaNodriza::GetEstado()
{
	return Estado;
}

INaveNodrizaState* ANaveEnemigaNodriza::GetEstadoDefensivo()
{
	return EstadoDefensivo;
}

INaveNodrizaState* ANaveEnemigaNodriza::GetEstadoOfensivo()
{
	return EstadoOfensivo;
}

INaveNodrizaState* ANaveEnemigaNodriza::GetEstadoDebil()
{
	return EstadoDebil;
}
