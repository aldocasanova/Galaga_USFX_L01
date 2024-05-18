// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ModeloCanon.h"
#include "CanonBala.h"
#include "CanonLazer.h"
#include "CanonBomba.h"
#include "CanonHielo.h"
#include "FacadeCanon.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AFacadeCanon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFacadeCanon();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SpawnCanons(int32 Nivel);

private:
	void SpawnCanon(TSubclassOf<AModeloCanon> CanonClass, FVector Location);
	void CleanUpCanones();


	FVector TopLeftCorner;
	FVector TopRightCorner;
	FVector DownLeftCorner;
	FVector DownRightCorner;

	// Nivel actual de los cañones
	int32 NivelInicial;

	// Intervalo de tiempo para aumentar el nivel de los cañones
	float  IntervaloNivel;
	float TiempoSpawn;
	// TimerHandle para el temporizador
	FTimerHandle  IntervaloNivelimerHandle;

	// Función para incrementar el nivel de los cañones
	void IncreaseNivel();

	TArray<AModeloCanon*> ExistingCanons;


	// Máximo nivel permitido
	int32 MaxNivel;

};
