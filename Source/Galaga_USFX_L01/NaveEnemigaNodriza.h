// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveNodrizaState.h"
#include "Escudo.h"
#include "NaveEnemigaNodriza.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaNodriza : public ANaveEnemiga
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ANaveEnemigaNodriza();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Declaramos las caracteristicas de la nave nodriza
public:
	UStaticMeshComponent* NaveNodrizaMesh;

	float vida;

	void RecibirDanio();

	//Declaramos todo lo necesario para hacer trabajar los estados de la nave nodriza
public:
	//Inicializar los estados de la nave nodriza
	void InicializarEstadosNaveNodriza();

	//Declaramos los estados de la nave nodriza
	INaveNodrizaState* EstadoDefensivo;
	INaveNodrizaState* EstadoOfensivo;
	INaveNodrizaState* EstadoDebil;
	INaveNodrizaState* Estado;

	//Funciones para cambiar de estado
	FORCEINLINE void EstablecerEstados(INaveNodrizaState* _Estado);

	virtual void Mover(float DeltaTime) override;
	virtual void Disparar() override;
	void CrearEscudo();
	//void DestruirEscudos();
	//Funciones para obtener los estados
	FORCEINLINE INaveNodrizaState* GetEstado();
	FORCEINLINE INaveNodrizaState* GetEstadoDefensivo();
	FORCEINLINE INaveNodrizaState* GetEstadoOfensivo();
	FORCEINLINE INaveNodrizaState* GetEstadoDebil();

	
};
