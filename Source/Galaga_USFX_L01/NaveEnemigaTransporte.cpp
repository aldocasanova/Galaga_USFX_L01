// Fill out your copyright notice in the Description page of Project Settings.

#include "NaveEnemigaTransporte.h"
#include "Galaga_USFX_L01GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "NaveEnemigaManager.h"
#include "EngineUtils.h"

ANaveEnemigaTransporte::ANaveEnemigaTransporte()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	Vida = 30;
	mallaNaveEnemiga->SetRelativeScale3D(FVector(2.0f, 2.0f, 2.0f));


} 


void ANaveEnemigaTransporte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
	Desplazamiento(DeltaTime);
}

void ANaveEnemigaTransporte::BeginPlay()
{
	Super::BeginPlay();

	NaveManager = Cast<ANaveEnemigaManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ANaveEnemigaManager::StaticClass()));

	if (NaveManager)
	{
		NaveManager->AddObserver(this);
	}

	
}

void ANaveEnemigaTransporte::OnNaveCountChanged(int NewCount)
{
	if (NewCount < 20)
	{
		SpawnNaveEnemigaCaza();
	}
}

void ANaveEnemigaTransporte::SpawnNaveEnemigaCaza()
{	
	for (int i = 0; i < 3; ++i)
	{
		FVector SpawnLocation = GetActorLocation() + FVector(400.0f + i*200, 0.0f, 0.0f); // Ajusta la posición según tu lógica
		GetWorld()->SpawnActor<ANaveEnemigaCaza>(ANaveEnemigaCaza::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
	}
}


void ANaveEnemigaTransporte::Mover(float DeltaTime)
{
	velocidad = 0.45; //0.35
	SetActorLocation(FVector(GetActorLocation().X - velocidad, GetActorLocation().Y, GetActorLocation().Z));

	if (GetActorLocation().X < LimiteInferiorX) {

		SetActorLocation(FVector(800.0f, GetActorLocation().Y, 215.0f));

	}
}

void ANaveEnemigaTransporte::Disparar()
{
}

void ANaveEnemigaTransporte::Destruirse()
{
}

void ANaveEnemigaTransporte::Escapar()
{
}

void ANaveEnemigaTransporte::Desplazamiento(float DeltaTime)
{
	AmplitudT = 1.0f;
	VelocidadT = 5.0f;

	FVector NewLocation = FVector(GetActorLocation().X, GetActorLocation().Y + AmplitudT * FMath::Sin(VelocidadT * GetWorld()->GetTimeSeconds()), GetActorLocation().Z);
	SetActorLocation(NewLocation);
}

void ANaveEnemigaTransporte::RecibirDanio()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("NaveTransporte::RecibirDanio"));
	Vida -= 5;
	if (Vida <= 0)
	{

		//EnemigasManager->RemoveObserver(EnemyTransport);
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
		if (EnemyTransport && EnemigasManager)
		{
			EnemigasManager->RemoveObserver(EnemyTransport);
		}
	}
}
