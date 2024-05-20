// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bomb.h"
#include "GameFramework/Actor.h"
#include "ProyectilEnemigo.h"
#include "LazerEnemigo.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ALazerEnemigo : public ABomb
{
	GENERATED_BODY()
public:
	ALazerEnemigo();
	virtual void Tick(float DeltaTime) override;
	void Mover(float DeltaTime) override;
	void Desaparecer(float _TiempoExplosion)override ;
	virtual void BeginPlay() override;
	void SetUltimaPosicionJugador(FVector Posicion);

	FVector UltimaPosicionJugador;
	FVector Direction;
	float TiempoExplosion;
	float velocidad;

	bool bInitialized;
};
