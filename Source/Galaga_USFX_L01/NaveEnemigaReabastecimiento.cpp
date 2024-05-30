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
	Desplazamiento(DeltaTime);
	/*if (FieldStrategy)
	{
		FieldStrategy->Mover(this, DeltaTime);
		FieldStrategy->Desplazamiento(this, DeltaTime);
	}*/
}

void ANaveEnemigaReabastecimiento::Mover(float DeltaTime)
{
	
	if (FieldStrategy)
	{
		FieldStrategy->Mover(this, DeltaTime);
	}
}


void ANaveEnemigaReabastecimiento::Desplazamiento(float DeltaTime)
{
	if (FieldStrategy)
	{
		FieldStrategy->Desplazamiento(this, DeltaTime);
	}
}


