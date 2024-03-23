// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProyectilEnemigo.generated.h"
class UstaticMeshComponent;
UCLASS()
class GALAGA_USFX_L01_API AProyectilEnemigo : public AActor
{
	GENERATED_BODY()
private:
	// Sets default values for this actor's properties
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ProyectilEnemyMesh;
	float velocidad;
	float danio;
public:
	//metodos accesores
	FORCEINLINE float GetVelocidad() const { return velocidad; }

	FORCEINLINE void SetVelocidad(float _velocidad) { velocidad = _velocidad; }
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
	void Mover();

};
