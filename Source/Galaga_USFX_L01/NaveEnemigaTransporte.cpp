// Fill out your copyright notice in the Description page of Project Settings.

#include "NaveEnemigaTransporte.h"
#include "Galaga_USFX_L01GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "NaveEnemigaManager.h"
#include "NaveEnemigaCaza.h"
#include "FieldStragedy.h"
#include "OmegaStragedy.h"
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
		FVector SpawnLocation = GetActorLocation() + FVector(400.0f + i * 200, 0.0f, 0.0f); // Ajusta la posición según tu lógica
		ANaveEnemigaCaza* NewNaveCaza = GetWorld()->SpawnActor<ANaveEnemigaCaza>(ANaveEnemigaCaza::StaticClass(), SpawnLocation, FRotator::ZeroRotator);

		if (NewNaveCaza)
		{
			TScriptInterface<IFieldStragedy> NewStrategy = GetWorld()->SpawnActor<AOmegaStragedy>(AOmegaStragedy::StaticClass());
			NewNaveCaza->SetFieldStrategy(NewStrategy);
		}
	}
}


void ANaveEnemigaTransporte::Mover(float DeltaTime)
{
	ANaveEnemiga::Mover(DeltaTime);
}

void ANaveEnemigaTransporte::Desplazamiento(float DeltaTime)
{
	ANaveEnemiga::Desplazamiento(DeltaTime);
}

void ANaveEnemigaTransporte::RecibirDanio()
{
	Vida -= 5;
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
		if (EnemyTransport && EnemigasManager)
		{
			EnemigasManager->RemoveObserver(EnemyTransport);
		}
	}
}
