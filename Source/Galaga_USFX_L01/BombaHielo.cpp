// Fill out your copyright notice in the Description page of Project Settings.


#include "BombaHielo.h"
#include "Galaga_USFX_L01Pawn.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"

ABombaHielo::ABombaHielo()
{
	PrimaryActorTick.bCanEverTick = true;
	velocidad = 9;
	TiempoExplosion = 0.0f;
	TiempoVuelo = 0.0f;
	bInitialized = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BombHMeshAsset(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));
	BombHMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BombHMesh"));
	BombHMesh->SetStaticMesh(BombHMeshAsset.Object);
	RootComponent = BombHMesh;

	BombHMesh->SetCollisionProfileName(TEXT("OverlapAllDynamic")); // Usar un perfil de colisión adecuado
	BombHMesh->OnComponentBeginOverlap.AddDynamic(this, &ABombaHielo::OnOverlapBegin); // Agregar el evento de colisión

	BombHMesh->SetRelativeScale3D(FVector(5.0f, 5.0f, 5.0f));

}

void ABombaHielo::BeginPlay()
{
	Super::BeginPlay();
}

void ABombaHielo::Mover(float DeltaTime)
{
	if (!bInitialized)
	{
		FVector StartLocation = GetActorLocation();
		FVector EndLocation = UltimaPosicionJugador;

		float TotalTime = 4.0f; // Tiempo total de vuelo en segundos
		float Gravity = -980.0f; // Aceleración debido a la gravedad (cm/s^2)

		// Calcular la velocidad inicial necesaria
		FVector Direction = (EndLocation - StartLocation);
		FVector HorizontalDirection = FVector(Direction.X, Direction.Y, 0.0f);
		float HorizontalDistance = HorizontalDirection.Size();
		float InitialHorizontalSpeed = HorizontalDistance / TotalTime;

		float VerticalDistance = EndLocation.Z - StartLocation.Z;
		float InitialVerticalSpeed = (VerticalDistance - 0.5f * Gravity * FMath::Square(TotalTime)) / TotalTime;

		InitialVelocity = HorizontalDirection.GetSafeNormal() * InitialHorizontalSpeed;
		InitialVelocity.Z = InitialVerticalSpeed;

		bInitialized = true;
	}
	float Gravity = -980.0f; // Aceleración debido a la gravedad (cm/s^2
	// Actualizar la posición del proyectil
	FVector NewLocation = GetActorLocation();
	NewLocation += InitialVelocity * DeltaTime;
	InitialVelocity.Z += Gravity * DeltaTime; // Aplicar gravedad a la velocidad vertical

	SetActorLocation(NewLocation);
}

void ABombaHielo::Desaparecer(float _TiempoExplosion)
{
	if (_TiempoExplosion >= 12.0f)
	{
		Destroy();
	}
}

void ABombaHielo::SetUltimaPosicionJugador(FVector Posicion)
{
	UltimaPosicionJugador = Posicion;

}
void ABombaHielo::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		AGalaga_USFX_L01Pawn* PlayerPawn = Cast<AGalaga_USFX_L01Pawn>(OtherActor);
		if (PlayerPawn)
		{
			PlayerPawn->DisableMovement();
			Destroy(); // Destruye la bomba al impactar
		}
	}
}
void ABombaHielo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TiempoExplosion += DeltaTime; // Incremento sincronizado con el tiempo del mundo
	Desaparecer(TiempoExplosion);
	Mover(DeltaTime);
}