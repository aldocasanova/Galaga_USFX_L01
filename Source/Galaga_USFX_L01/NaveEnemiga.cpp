// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemiga.h"
#include "Galaga_USFX_L01Projectile.h"
#include "Galaga_USFX_L01GameMode.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProyectilEnemigo.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "FieldStragedy.h"
#include "Engine/World.h"

// Sets default values
ANaveEnemiga::ANaveEnemiga()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	// Create the mesh component
	mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	//mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	mallaNaveEnemiga->SetupAttachment(RootComponent);
	RootComponent = mallaNaveEnemiga;
	//velociades segun escenario
	velocidadOmega = 20.0f;
	velocidadAlfa = 200.0f;
	velocidadDelta = 10.0f;

	LimiteInferiorX = -500.0f;
	LimiteInferiorY = -1800.0f;
	LimiteSuperiorY = 1800.0f;
	//LimiteInferiorY = 0.0f;
	FireRate = rand() % 4 + 1; // Intervalo de tiempo entre disparos en segundos, formula 

	MaxShots = 3; // Cantidad máxima de disparos
	ShotsFired = 0; // Inicializar contador de disparos

	bCanFire = true; // Permitir disparos al principio

	Vida = 30;

}

void ANaveEnemiga::Desplazamiento(float DeltaTime)
{
	if (FieldStrategy)
	{
		FieldStrategy->Desplazamiento(this, DeltaTime);
	}
}

void ANaveEnemiga::Mover(float DeltaTime)
{
	if (FieldStrategy)
	{
		FieldStrategy->Mover(this, DeltaTime);
	}
}

void ANaveEnemiga::Disparar()
{
	if (bCanFire && FieldStrategy)
	{
		FieldStrategy->Disparar(this);
	}
}
void ANaveEnemiga::SetFieldStrategy(TScriptInterface<IFieldStragedy> NewStrategy)
{
	FieldStrategy = NewStrategy;
}

// Called when the game starts or when spawned
void ANaveEnemiga::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ANaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
	Desplazamiento(DeltaTime);
	Disparar();
}

void ANaveEnemiga::FireProjectile()
{
	FVector SpawnLocation = GetActorLocation() + -(GetActorForwardVector() * 1);

	if (bCanFire && ShotsFired < MaxShots)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			AProyectilEnemigo* NewProjectile = World->SpawnActor<AProyectilEnemigo>(SpawnLocation, FRotator::ZeroRotator);
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveEnemiga::ShotTimerExpired, FireRate);
			bCanFire = false;

			ShotsFired++;
			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}
		}
	}
}

void ANaveEnemiga::RecibirDanio()
{
	Vida -= 10;
	if (Vida <= 0)
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
}

