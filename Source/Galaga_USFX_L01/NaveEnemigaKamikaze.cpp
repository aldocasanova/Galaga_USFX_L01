// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaKamikaze.h"
#include "NaveEnemigaManager.h"
#include "EngineUtils.h"
// Sets default values
ANaveEnemigaKamikaze::ANaveEnemigaKamikaze()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Vida = 10;

}

// Called every frame
void ANaveEnemigaKamikaze::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*if (FieldStrategy)
	{
		FieldStrategy->Mover(this, DeltaTime);
		FieldStrategy->Desplazamiento(this, DeltaTime);
	}
	Disparar();*/
	Mover(DeltaTime);
	Desplazamiento(DeltaTime);
	Disparar();
}

void ANaveEnemigaKamikaze::Mover(float DeltaTime)
{
	if (FieldStrategy)
	{
		FieldStrategy->Mover(this, DeltaTime);
	}
}

void ANaveEnemigaKamikaze::RecibirDanio()
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
	}
}


void ANaveEnemigaKamikaze::Desplazamiento(float DeltaTime)
{
	
	if (FieldStrategy)
	{
		FieldStrategy->Desplazamiento(this, DeltaTime);
	}
}

void ANaveEnemigaKamikaze::Disparar()
{
	if (FieldStrategy)
	{
		FieldStrategy->Disparar(this);
	}
}


