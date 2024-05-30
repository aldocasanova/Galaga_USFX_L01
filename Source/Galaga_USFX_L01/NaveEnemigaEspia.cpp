// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspia.h"
#include "NaveEnemigaManager.h"
#include "EngineUtils.h"
// Sets default values
ANaveEnemigaEspia::ANaveEnemigaEspia()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Vida = 20;

}

void ANaveEnemigaEspia::RecibirDanio()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("NaveTransporte::RecibirDanio"));
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

void ANaveEnemigaEspia::Mover(float DeltaTime)
{
	if (FieldStrategy)
	{
		FieldStrategy->Mover(this, DeltaTime);
	}
}

void ANaveEnemigaEspia::Desplazamiento(float DeltaTime)
{
	if (FieldStrategy)
	{
		FieldStrategy->Desplazamiento(this, DeltaTime);
	}
}

// Called every frame
void ANaveEnemigaEspia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*if (FieldStrategy)
	{
		FieldStrategy->Mover(this, DeltaTime);
		FieldStrategy->Desplazamiento(this, DeltaTime);
	}*/
	Mover(DeltaTime);
	Desplazamiento(DeltaTime);
}

