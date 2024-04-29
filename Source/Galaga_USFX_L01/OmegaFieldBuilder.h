// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IGalacticFieldBuilder.h"

#include "Obstaculo.h"
#include "PowerUp.h"

#include "MyNaveEnemigaCazaX.h"
#include "NaveEnemigaTransporteSupport.h"
#include "MyNaveEnemigaEspiaNv1.h"
#include "MyNaveEnemigaNodrizaPacheco.h"
#include "MyNaveEnemigaNodrizaCoca.h"
#include "MyNaveEnemigaReabastecimientoBal.h"
#include "MyNaveEnemigaKamikazeB.h"
#include "NaveEnemigaPiccoloZ.h"
#include "NaveEnemigaPiccoloAF.h"

#include "GalacticField.h"
#include "OmegaFieldBuilder.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AOmegaFieldBuilder : public AActor, public IIGalacticFieldBuilder
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOmegaFieldBuilder();

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
	TMap<FVector,ANaveEnemiga*> TMNavesEnemigas;

};