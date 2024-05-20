// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bomb.h"
#include "GameFramework/Actor.h"
#include "BalaCanon.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ABalaCanon : public ABomb
{
	GENERATED_BODY()

public:
	ABalaCanon();
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	void Mover(float DeltaTime) override ;
	void Desaparecer(float _TiempoExplosion) override;

	void SetUltimaPosicionJugador(FVector Posicion);

	FVector UltimaPosicionJugador;
	FVector Direction;
	float TiempoExplosion;
	float velocidad;

	bool bInitialized;

};
