// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Galaga_USFX_L01GameMode.generated.h"

class ANaveEnemiga; //agrego
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

UCLASS(MinimalAPI)
class AGalaga_USFX_L01GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGalaga_USFX_L01GameMode();

public:
	//ANaveEnemiga* NaveEnemiga01;
	ANaveEnemigaTransporte* NaveEnemigaTransporte01;
	ANaveEnemigaCaza* NaveEnemigaCaza01;

	ANaveEnemigaCazaX* NaveEnemigaCazaX01;
	ANaveEnemigaCazaY* NaveEnemigaCazaY01;
	ANaveEnemigaTransporteAttack* NaveEnemigaTransporteAttack01;
	ANaveEnemigaTransporteSupport* NaveEnemigaTransporteSupport01;
	ANaveEnemigaEspiaNv1* NaveEnemigaEspiaNv101;
	ANaveEnemigaEspiaNv2* NaveEnemigaEspiaNv2l01;
	ANaveEnemigaReabastecimientoBal* NaveEnemigaReabastecimientoBalas01;
	ANaveEnemigaReabastecimientoBom* NaveEnemigaReabastecimientoBombas01;
	ANaveEnemigaNodrizaPacheco* NaveEnemigaNodrizaPachecho01;
	ANaveEnemigaNodrizaCoca* NaveEnemigaNodrizaCoca01;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	void Tick(float DeltaTime) override;
	//14/03
	TArray <ANaveEnemiga*> TANavesEnemigas;
	TArray<ANaveEnemigaCaza*>TANavesEnemigasCaza; //se alamacena direcciones de objetos de nave enemiga caza 
	TArray<ANaveEnemigaTransporte*>TANavesEnemigasTransporte;
	TArray<ANaveEnemigaEspia*>TANavesEnemigasEspia;

	//lo mejor de la abastracta es que puedes ponerla en el array para poner todos 
	// para rescatarlos se debe declarar un propiedad tipo nave en la clase abstracta para digamos 1 sea caza, sea 2 transporte		
private:
	int TiempoTranscurrido = 0;
public:
	TMap<FVector, AActor*> ObstaclesAndPowerUps;
};