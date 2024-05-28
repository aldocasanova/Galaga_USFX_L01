// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaReabastecimiento.h"
#include "NaveEnemigaManager.h"
#include "EngineUtils.h"

// Sets default values
ANaveEnemigaReabastecimiento::ANaveEnemigaReabastecimiento()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Vida = 40;

	GetActorRelativeScale3D();
	SetActorScale3D(FVector(0.5f, 0.5f, 0.5f));

}

void ANaveEnemigaReabastecimiento::RecibirDanio()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("NaveTransporte::RecibirDanio"));
	Vida -= 5;
	if (Vida <= 0)
	{
		Destroy();
		/*for (TActorIterator<ANaveEnemigaManager> It(GetWorld()); It; ++It)
		{
			EnemigasManager = *It;
			break;
		}*/
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

// Called every frame
void ANaveEnemigaReabastecimiento::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaReabastecimiento::Mover(float DeltaTime)
{
	velocidad = 0.35; // 1
	SetActorLocation(FVector(GetActorLocation().X - velocidad, GetActorLocation().Y, GetActorLocation().Z));

	if (GetActorLocation().X < LimiteInferiorX) {

		SetActorLocation(FVector(800.0f, GetActorLocation().Y, 215.0f));

	}

}

void ANaveEnemigaReabastecimiento::Destruirse()
{
}


void ANaveEnemigaReabastecimiento::Desplazamiento(float DeltaTime)
{
}


