// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstaculo.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AObstaculo : public AActor
{
	GENERATED_BODY()
private:
	//atributos
	FVector posicion;
	float tiempoSpaw;
	float danioImpacto; 

public:
	//metodos accesores
	FORCEINLINE FVector GetPosicion() const { return posicion; }
	FORCEINLINE float GetTiempoSpaw() const { return tiempoSpaw; }
	FORCEINLINE float GetdanioImpacto() const { return danioImpacto; }

	FORCEINLINE void SetPosicion(FVector _posicion) { posicion = _posicion; }
	FORCEINLINE void SetTiempoSpaw(float _tiempoSpaw) { tiempoSpaw = _tiempoSpaw; }
	FORCEINLINE void SetdanioImpacto(float _danioImpacto) { danioImpacto = _danioImpacto; }

	//metodos de la clase
	void GenerarObstaculo();


public:	
	// Sets default values for this actor's properties
	AObstaculo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};