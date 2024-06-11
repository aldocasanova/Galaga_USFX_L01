// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IGalacticFieldBuilder.h"
#include "Obstaculo.h"
#include "Coliseo.h"
#include "PowerUp.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaBomb.h"
#include "NaveEnemigaFactory.h"
#include "NaveEnemigaManager.h"
#include "AlfaFieldBuilder.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AAlfaFieldBuilder : public AActor, public IIGalacticFieldBuilder
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AAlfaFieldBuilder();

	float TiempoSpawn = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void BuildObstacles() override {};
	void BuildEnemies() override;
	void BuildPowerUps() override;
	virtual AGalacticField* GetGalacticField() const override;
	TMap<FVector, AActor*> TMObstaclesAndPowerUps;
	//...
	void BuildElements(AColiseo* ElementosAlfa);
};
