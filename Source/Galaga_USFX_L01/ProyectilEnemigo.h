// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProyectilEnemigo.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AProyectilEnemigo : public AActor
{
	GENERATED_BODY()
private:
	//atributos
	float velocidad;
	float danioBala; 
	FVector posicion;
public:
	//metodos accesores
	FORCEINLINE float GetVelocidad() const { return velocidad; }
	FORCEINLINE float GetDanioProducido() const { return danioBala; }
	FORCEINLINE FVector GetPosicion() const { return posicion; }

	FORCEINLINE void SetVelocidad(float _velocidad) { velocidad = _velocidad; }
	FORCEINLINE void SetDanioBala(float _danioBala) { danioBala = _danioBala; }
	FORCEINLINE void SetPosicion(FVector _posicion) { posicion = _posicion; }
	//metodos de la clase
	void MovimientoProyectil();
	void Impacto();
public:	
	// Sets default values for this actor's properties
	AProyectilEnemigo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
