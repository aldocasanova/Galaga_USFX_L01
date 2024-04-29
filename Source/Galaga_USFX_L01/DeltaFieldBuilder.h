// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IGalacticFieldBuilder.h"
#include "Obstaculo.h"
#include "PowerUp.h"
#include "NaveEnemiga.h"

#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaReabastecimiento.h"
#include "NaveEnemigaKamikaze.h"
#include "MyNaveEnemigaCazaX.h"
#include "MyNaveEnemigaCazaY.h"
#include "NaveEnemigaTransporteAttack.h"
#include "NaveEnemigaTransporteSupport.h"
#include "MyNaveEnemigaEspiaNv1.h"
#include "MyNaveEnemigaEspiaNv2.h"
#include "MyNaveEnemigaNodrizaPacheco.h"
#include "MyNaveEnemigaNodrizaCoca.h"
#include "MyNaveEnemigaReabastecimientoBal.h"
#include "MyNaveEnemigaReabastecimientoBom.h"
#include "MyNaveEnemigaKamikazeA.h"
#include "MyNaveEnemigaKamikazeB.h"

#include "DeltaFieldBuilder.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ADeltaFieldBuilder : public AActor, public IIGalacticFieldBuilder
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeltaFieldBuilder();
	int x;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void BuildObstacles() override;
	void BuildEnemies() override;
	void BuildPowerUps() override;
	virtual AGalacticField* GetGalacticField() const override;


	TMap<FVector, AActor*> TMObstaclesAndPowerUps;
	TMap<FVector, ANaveEnemiga*> TMNavesEnemigas;
};
