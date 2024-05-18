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
	TArray<AModeloCanon*> FormacionCanones;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void SpawnCanons(int32 Nivel);
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	void SpawnCanon(TSubclassOf<AModeloCanon> CanonClass, FVector Location);


	FVector TopLeftCorner;
	FVector TopRightCorner;
	FVector DownLeftCorner;
	FVector DownRightCorner;

	// Nivel actual de los cañones
	int32 NivelInicial;

	// Intervalo de tiempo para aumentar el nivel de los cañones
	float  IntervaloNivel;

	// TimerHandle para el temporizador
	FTimerHandle  IntervaloNivelimerHandle;

	// Función para incrementar el nivel de los cañones
	void IncreaseNivel();

	// Máximo nivel permitido
	int32 MaxNivel;
	int32 Nivel;
};
