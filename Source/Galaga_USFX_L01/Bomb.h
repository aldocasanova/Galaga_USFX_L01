// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bomb.generated.h"
class UstaticMeshComponent;

UCLASS()
class GALAGA_USFX_L01_API ABomb : public AActor
{
	GENERATED_BODY()
private:
	float velocidad;
	float danio;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BombMesh;
	UPROPERTY(VisibleAnywhere);

	float TiempoExplosion = 0;
public:	
	ABomb();

	FORCEINLINE float GetVelocidad() const { return velocidad; }
	FORCEINLINE void SetVelocidad(float _velocidad) { velocidad = _velocidad; }
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Mover(float DeltaTime);
	void Desaparecer(float TiempoExplosion);
};
