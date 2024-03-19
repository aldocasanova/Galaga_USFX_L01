// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PowerUp.generated.h"

UCLASS()
class GALAGA_USFX_L01_API APowerUp : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* mallaPowerUp;
private:
	//atributos
	int tipoPUp;
	FVector posicion;
	float tiempoSpaw;
	float tiempoPantalla;
public:
	//metodos acccesores
	FORCEINLINE int GettipoPUP() const { return tipoPUp; }
	FORCEINLINE FVector GetPosicion() const { return posicion; }
	FORCEINLINE float GetTiempoSpaw() const { return tiempoSpaw; }
	FORCEINLINE float GetTiempoPantalla() const { return tiempoPantalla; }

	FORCEINLINE void SettipoPUP(float _tipoPUp) { tipoPUp = _tipoPUp; }
	FORCEINLINE void SetPosicion(FVector _posicion) { posicion = _posicion; }
	FORCEINLINE void SetTiempoSpaw(float _tiempoSpaw) { tiempoSpaw = _tiempoSpaw; }
	FORCEINLINE void SetTiempoPantalla(float _tiempoPantalla) { tiempoPantalla = _tiempoPantalla; }
	//metodos de clase
	void GenerarPowerUp();
public:	
	// Sets default values for this actor's properties
	APowerUp();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
