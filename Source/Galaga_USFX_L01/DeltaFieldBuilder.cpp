// Fill out your copyright notice in the Description page of Project Settings.


#include "DeltaFieldBuilder.h"

// Sets default values
ADeltaFieldBuilder::ADeltaFieldBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADeltaFieldBuilder::BeginPlay()
{
	Super::BeginPlay();
	
	//trabajo 3
	FormacionCanones = GetWorld()->SpawnActor<AFacadeCanon>();
	FormacionCanones->SpawnCanons(1);
	FormacionCanones->IncreaseNivel();
}

// Called every frame
void ADeltaFieldBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADeltaFieldBuilder::BuildObstacles()
{
	x = 1 + rand() % (15);
	for (int i = 0; i < x; i++)
	{
		FVector SpawnLocation = FVector(FMath::RandRange(-1600.0f, 1600.0f), FMath::RandRange(-1600.0f, 1600.0f), 250.0f);
		AObstaculo* NewObstacle = GetWorld()->SpawnActor<AObstaculo>(AObstaculo::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMObstaclesAndPowerUps.Add(SpawnLocation, NewObstacle);
	}

}

void ADeltaFieldBuilder::BuildEnemies()
{

	for (int i = 0; i < 30; i++) {
		FVector SpawnLocation = FVector(FMath::RandRange(-1600.0f, 1600.0f), FMath::RandRange(-1600.0f, 1600.0f), 250.0f);		
		x = 1 + rand() % (12);
		switch (x) {
		case 1:
		{
			AMyNaveEnemigaEspiaNv1* NaveEnemigaEspiaNv1Temporal = GetWorld()->SpawnActor<AMyNaveEnemigaEspiaNv1>(AMyNaveEnemigaEspiaNv1::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMNavesEnemigas.Add(SpawnLocation, NaveEnemigaEspiaNv1Temporal);
			break;
		}
		case 2:
		{
			AMyNaveEnemigaEspiaNv2* NaveEnemigaEspiaNv2Temporal = GetWorld()->SpawnActor<AMyNaveEnemigaEspiaNv2>(AMyNaveEnemigaEspiaNv2::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMNavesEnemigas.Add(SpawnLocation, NaveEnemigaEspiaNv2Temporal);
			break;
		}
		case 3:
		{
			AMyNaveEnemigaCazaX* NaveEnemigaCazaXTemporal = GetWorld()->SpawnActor<AMyNaveEnemigaCazaX>(AMyNaveEnemigaCazaX::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMNavesEnemigas.Add(SpawnLocation, NaveEnemigaCazaXTemporal);
			break;
		}
		case 4:
		{
			AMyNaveEnemigaCazaY* NaveEnemigaCazaYTemporal = GetWorld()->SpawnActor<AMyNaveEnemigaCazaY>(AMyNaveEnemigaCazaY::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMNavesEnemigas.Add(SpawnLocation, NaveEnemigaCazaYTemporal);
			break;
		}
		case 5:
		{
			ANaveEnemigaTransporteAttack* NaveEnemigaTATemporal = GetWorld()->SpawnActor<ANaveEnemigaTransporteAttack>(ANaveEnemigaTransporteAttack::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMNavesEnemigas.Add(SpawnLocation, NaveEnemigaTATemporal);
			break;
		}
		case 6:
		{
			ANaveEnemigaTransporteSupport* NaveEnemigaTSTemporal = GetWorld()->SpawnActor<ANaveEnemigaTransporteSupport>(ANaveEnemigaTransporteSupport::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMNavesEnemigas.Add(SpawnLocation, NaveEnemigaTSTemporal);
			break;
		}	
		case 7:
		{
			AMyNaveEnemigaReabastecimientoBal* NaveEnemigaRBATemporal = GetWorld()->SpawnActor<AMyNaveEnemigaReabastecimientoBal>(AMyNaveEnemigaReabastecimientoBal::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMNavesEnemigas.Add(SpawnLocation, NaveEnemigaRBATemporal);
			break;
		}
		case 8:
		{
			AMyNaveEnemigaReabastecimientoBom* NaveEnemigaRBOTemporal = GetWorld()->SpawnActor<AMyNaveEnemigaReabastecimientoBom>(AMyNaveEnemigaReabastecimientoBom::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMNavesEnemigas.Add(SpawnLocation, NaveEnemigaRBOTemporal);
			break;
		}
		case 9:
		{
			AMyNaveEnemigaKamikazeB* NaveEnemigaKATemporal = GetWorld()->SpawnActor<AMyNaveEnemigaKamikazeB>(AMyNaveEnemigaKamikazeB::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMNavesEnemigas.Add(SpawnLocation, NaveEnemigaKATemporal);
			break;
		}
		case 10:
		{
			AMyNaveEnemigaKamikazeA* NaveEnemigaKBTemporal = GetWorld()->SpawnActor<AMyNaveEnemigaKamikazeA>(AMyNaveEnemigaKamikazeA::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMNavesEnemigas.Add(SpawnLocation, NaveEnemigaKBTemporal);
			break;
		}
		case 11:
		{
			AMyNaveEnemigaNodrizaPacheco* NaveEnemigaNPTemporal = GetWorld()->SpawnActor<AMyNaveEnemigaNodrizaPacheco>(AMyNaveEnemigaNodrizaPacheco::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMNavesEnemigas.Add(SpawnLocation, NaveEnemigaNPTemporal);
			break;
		}
		case 12:
		{
			AMyNaveEnemigaNodrizaCoca* NaveEnemigaNCTemporal = GetWorld()->SpawnActor<AMyNaveEnemigaNodrizaCoca>(AMyNaveEnemigaNodrizaCoca::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
			TMNavesEnemigas.Add(SpawnLocation, NaveEnemigaNCTemporal);
			break;
		}
		}
	}
}

void ADeltaFieldBuilder::BuildPowerUps()
{
	x = 1 + rand() % (2);
	for (int i = 0; i < x; i++)
	{
		FVector SpawnLocation = FVector(FMath::RandRange(-400.0f, 0.0f), FMath::RandRange(-1000.0f, 1000.0f), 250.0f);
		APowerUp* NewObstacle = GetWorld()->SpawnActor<APowerUp>(APowerUp::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
		TMObstaclesAndPowerUps.Add(SpawnLocation, NewObstacle);
	}
}

AGalacticField* ADeltaFieldBuilder::GetGalacticField() const
{
	AGalacticField * GalacticField = NewObject<AGalacticField>();
	return GalacticField;
}

