// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FieldStragedy.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.generated.h"

UCLASS(abstract) // declarar clase abstracta
class GALAGA_USFX_L01_API ANaveEnemiga : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* mallaNaveEnemiga;

	void FireProjectile(); // Método para disparar proyectil

	FTimerHandle TimerHandle_ShotTimerExpired;
	void ShotTimerExpired() { bCanFire = true; }
	//void FireProjectile(); // Método para disparar proyectil
protected:
	
	float velocidadOmega; //pongo esto en el constructor o aquí? xd
	float velocidadAlfa; 
	float velocidadDelta; 

	float tiempoDisparo; //Tiempo que debe transcurrir entre cada disparo
	FVector posicion; 
	int trayectoria; //Cada valor numerico representa a una funcion que la nave debe asumir para moverse
	
	float LimiteInferiorX;
	float LimiteInferiorY;
	float LimiteSuperiorY;

	float Vida;
	int NavesEnemigas;
	float FireRate;

	class AGalaga_USFX_L01GameMode* GameMode;
	class ANaveEnemigaManager* EnemigasManager;

	float LastFireTime;
	bool bCanFire;

	int MaxShots;
	int ShotsFired;


public: //leer valores
	FORCEINLINE float GetVelocidadOmega() const { return velocidadOmega; }
	FORCEINLINE float GetVelocidadAlfa() const { return velocidadAlfa; }
	FORCEINLINE float GetVelocidadDelta() const { return velocidadDelta; }

	FORCEINLINE float GetTiempoDisparo() const { return tiempoDisparo; }
	FORCEINLINE FVector GetPosicion() const { return posicion; }
	FORCEINLINE int GetTrayectoria() const { return trayectoria; }
	FORCEINLINE float GetLastFireTime() const { return LastFireTime; }
	//...
	FORCEINLINE void SetVelocidad(float _velocidadOmega) { velocidadOmega = _velocidadOmega; }
	FORCEINLINE void SetVelocidadAlfa(float _velocidadAlfa) { velocidadAlfa = _velocidadAlfa; }
	FORCEINLINE void SetVelocidadDelta(float _velocidadDelta) { velocidadDelta = _velocidadDelta; }

	FORCEINLINE void SetTiempoDisparo(float _tiempoDisparo) { tiempoDisparo = _tiempoDisparo; }
	FORCEINLINE void SetPosicion(FVector _posicion) { posicion = _posicion; }
	FORCEINLINE void SetTrayectoria(int _trayectoria) { trayectoria = _trayectoria; }
	FORCEINLINE void SetLastFireTime(float _LastFireTime) { LastFireTime = _LastFireTime; }

public:
	// Sets default values for this actor's properties
	ANaveEnemiga();
	class USoundBase* FireSound;
	void SetFieldStrategy(TScriptInterface<IFieldStragedy> NewStrategy);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void RecibirDanio();

protected:
	virtual void Desplazamiento(float DeltaTime);
	virtual void Mover(float DeltaTime);
	virtual void Disparar();
	
	TScriptInterface<IFieldStragedy> FieldStrategy;
};
