// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.generated.h"

UCLASS(abstract) // declarar clase abstracta
class GALAGA_USFX_L01_API ANaveEnemiga : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* mallaNaveEnemiga;

protected:
	
	float velocidad;
	float resistencia; //Numero de disparos que puede recibir antes de ser destruido. Capas
	FString nombre;
	float danoProducido; //Potencia de cada proyectil que dispara la nave
	float tiempoDisparo; //Tiempo que debe transcurrir entre cada disparo
	FVector posicion; 
	int trayectoria; //Cada valor numerico representa a una funcion que la nave debe asumir para moverse
	int capacidadPasajeros; //Numero de naves que puede transportar	
	int capacidadMunicion; //Numero de disparos que puede realizar antes de recargar
	int tipoNave; //Cada valor numerico representa a un tipo de nave enemiga para el array
	float experiencia; //experiencia que droppea
	float energia; //vida

	float LimiteInferiorX;
	float LimiteInferiorY;
	float LimiteSuperiorY;

	int codigoNave;

	float Vida;
	int NavesEnemigas;

	//no s� si es esto 
	class AGalaga_USFX_L01GameMode* GameMode;
	class ANaveEnemigaManager* EnemigasManager;

public: //leer valores
	FORCEINLINE float GetVelocidad() const { return velocidad; }
	FORCEINLINE float GetResistencia() const { return resistencia; }
	FORCEINLINE FString GetNombre() const { return nombre; }
	FORCEINLINE float GetDanoProducido() const { return danoProducido; }
	FORCEINLINE float GetTiempoDisparo() const { return tiempoDisparo; }
	FORCEINLINE FVector GetPosicion() const { return posicion; }
	FORCEINLINE int GetTrayectoria() const { return trayectoria; }
	FORCEINLINE int GetCapacidadPasajeros() const { return capacidadPasajeros; }
	FORCEINLINE int GetCapacidadMunicion() const { return capacidadMunicion; }
	FORCEINLINE int GetTipoNave() const { return tipoNave; }
	FORCEINLINE float GetExperiencia() const { return experiencia; }
	FORCEINLINE float GetEnergia() const { return energia; }
	

	//reescribir valores
	FORCEINLINE void SetVelocidad(float _velocidad) { velocidad = _velocidad; }
	FORCEINLINE void SetResistencia(float _resistencia) { resistencia = _resistencia; }
	FORCEINLINE void SetNombre(FString _nombre) { nombre = _nombre; }
	FORCEINLINE void SetDanoProducido(float _danoProducido) { danoProducido = _danoProducido; }
	FORCEINLINE void SetTiempoDisparo(float _tiempoDisparo) { tiempoDisparo = _tiempoDisparo; }
	FORCEINLINE void SetPosicion(FVector _posicion) { posicion = _posicion; }
	FORCEINLINE void SetTrayectoria(int _trayectoria) { trayectoria = _trayectoria; }
	FORCEINLINE void SetCapacidadPasajeros(int _capacidadPasajeros) { capacidadPasajeros = _capacidadPasajeros; }
	FORCEINLINE void SetCapacidadMunicion(int _capacidadMunicion) { capacidadMunicion = _capacidadMunicion; }
	FORCEINLINE void SetTipoNave(int _tipoNave) { tipoNave = _tipoNave; }
	FORCEINLINE void SetExperiencia(float _experiencia) { experiencia = _experiencia; }
	FORCEINLINE void SetEnergia(float _energia) { energia = _energia; }
	

public:
	// Sets default values for this actor's properties
	ANaveEnemiga();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//colison
	virtual void RecibirDanio() PURE_VIRTUAL(ANaveEnemiga::RecibirDanio, );
protected:
	virtual void Mover(float DeltaTime) PURE_VIRTUAL(ANaveEnemiga::Mover, );
	//void Mover() PURE_VIRTUAL(ANaveEnemiga::Mover, );
	virtual void Disparar() PURE_VIRTUAL(ANaveEnemiga::Disparar, );
	virtual void Destruirse() PURE_VIRTUAL(ANaveEnemiga::Destruirse, );
	//virtual void Escapar() PURE_VIRTUAL(ANaveEnemiga::Escapar, );
	virtual void Desplazamiento(float DeltaTime) PURE_VIRTUAL(ANaveEnemiga::Desplazamiento, );
	
	

};
