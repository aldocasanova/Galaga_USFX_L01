// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bomb.h"
#include "GameFramework/Actor.h"
#include "BombaCanon.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ABombaCanon : public ABomb
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABombaCanon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Function to move the bomb
	void Mover(float DeltaTime) override;

	// Function to make the bomb disappear after certain time
	void Desaparecer(float TiempoExplosion) override;

	void SetUltimaPosicionJugador(FVector Posicion);

private:


	//FVector UltimaPosicionJugador;
	//float TiempoExplosion;
	//float velocidad;
	FVector UltimaPosicionJugador;
	FVector InitialVelocity;
	float TiempoExplosion;
	float TiempoVuelo;
	float velocidad;

	bool bInitialized;
};
