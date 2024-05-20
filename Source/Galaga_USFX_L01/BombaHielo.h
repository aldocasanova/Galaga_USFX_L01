// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bomb.h"
#include "GameFramework/Actor.h"
#include "BombaHielo.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ABombaHielo : public ABomb
{
	GENERATED_BODY()
public:
	ABombaHielo();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
	void Mover(float DeltaTime) override;
	void Desaparecer(float TiempoExplosion) override;
	void SetUltimaPosicionJugador(FVector Posicion);
private:
	FVector UltimaPosicionJugador;
	FVector InitialVelocity;
	float TiempoExplosion;
	float TiempoVuelo;
	float velocidad;
	bool bInitialized;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
