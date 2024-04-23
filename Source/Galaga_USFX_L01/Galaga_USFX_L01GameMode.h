// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Galaga_USFX_L01GameMode.generated.h"

class ANaveEnemiga; //agrego las clases
class ANaveEnemigaTransporte;
class ANaveEnemigaTransporteAttack;
class ANaveEnemigaTransporteSupport;
class ANaveEnemigaCaza;
class ANaveEnemigaCazaX;
class ANaveEnemigaCazaY;
class ANaveEnemigaEspia;
class ANaveEnemigaEspiaNv1;
class ANaveEnemigaEspiaNv2;
class ANaveEnemigaReabastecimiento;
class ANaveEnemigaReabastecimientoBal;
class ANaveEnemigaReabastecimientoBom;
class ANaveEnemigaNodriza;
class ANaveEnemigaNodrizaPacheco;
class ANaveEnemigaNodrizaCoca;
class ANaveEnemigaKamikaze;
class ANaveEnemigaKamikazeA;
class ANaveEnemigaKamikazeB;
class ANaveEnemigaPiccolo;
class ANaveEnemigaPiccoloZ;
class ANaveEnemigaPiccoloAF;
class ANaveEnemigaBomb;
class AObstaculo;
class APowerUp;
class ABomb;

UCLASS(MinimalAPI)
class AGalaga_USFX_L01GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGalaga_USFX_L01GameMode();

	void Tick(float DeltaTime) override;
	TArray <ANaveEnemiga*> TANavesEnemigas;
	TMap<FVector, AActor*> TMObstaclesAndPowerUps;
	//lo mejor de la abstracta es que puedes ponerla en el array para poner todos

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override; 
private:
	int TiempoTranscurrido = 0;
};