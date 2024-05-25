// Copyright Epic Games, Inc. All Rights Reserve

#include "Galaga_USFX_L01Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Galaga_USFX_L01GameMode.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaManager.h"
#include "EngineUtils.h"

#include "Engine/StaticMesh.h"

AGalaga_USFX_L01Projectile::AGalaga_USFX_L01Projectile() 
{
	// Static reference to the mesh to use for the projectile
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));

	// Create mesh component for the projectile sphere
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh0"));
	ProjectileMesh->SetStaticMesh(ProjectileMeshAsset.Object);
	ProjectileMesh->SetupAttachment(RootComponent);
	ProjectileMesh->BodyInstance.SetCollisionProfileName("Projectile");
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AGalaga_USFX_L01Projectile::OnHit);		// set up a notification for when this component hits something
	RootComponent = ProjectileMesh;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement0"));
	ProjectileMovement->UpdatedComponent = ProjectileMesh;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.f; // No gravity

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f; //tiempo de vida de un proyecti
	//creacion de la colision
	Collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision")); 
	Collision->SetupAttachment(RootComponent);
	Collision->InitCapsuleSize(50.f, 100.f);
}

void AGalaga_USFX_L01Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation());
	}



	Destroy();
}

void AGalaga_USFX_L01Projectile::NotifyActorBeginOverlap(AActor* OtherActor) //funcion para detectar colisiones
{
	Super::AActor::NotifyActorBeginOverlap(OtherActor);


	ANaveEnemiga* EnemyShip = Cast<ANaveEnemiga>(OtherActor);
	AGalaga_USFX_L01GameMode* GameMode = Cast<AGalaga_USFX_L01GameMode>(GetWorld()->GetAuthGameMode());


	ANaveEnemigaManager* EnemigasManager = nullptr;
	//ANaveEnemigaTransporte* EnemyTransport = Cast<ANaveEnemigaTransporte>(OtherActor);
	ANaveEnemigaTransporte* EnemyTransport = Cast<ANaveEnemigaTransporte>(OtherActor);  // Aquí se define EnemyTransport
	for (TActorIterator<ANaveEnemigaManager> It(GetWorld()); It; ++It)
	{
		EnemigasManager = *It;
		break;  // Asumiendo que solo hay una instancia de AEnemigasFacade en el nivel
	}

	if (EnemyShip)
	{
	
		EnemyShip->Destroy();
		//danio = 0;
		/*enemigos = GameMode->GetCantidadNavesEnemigas();
		enemigos--;
		GameMode->SetCantidadNavesEnemigas(enemigos);*/

		if (EnemigasManager)
		{
			enemigos = EnemigasManager->GetNavesEnemigasRestantes();
			enemigos--;
			EnemigasManager->SetNavesEnemigasRestantes(enemigos);
		}

		if (EnemyTransport && EnemigasManager)
		{
			EnemigasManager->RemoveObserver(EnemyTransport);
		}



		/*puntaje = GameMode->GetScore();
		puntaje += 10;
		GameMode->SetScore(puntaje);*/

		
		/*FString mensaje = FString::Printf(TEXT("Tu Puntaje es: %d"), puntaje);
		const int32 MessageKey = 0;*/  // Puedes elegir cualquier número que desees para el MessageKey

		//// Imprimir el mensaje en pantalla, reemplazando cualquier mensaje anterior con la misma clave
		//GEngine->AddOnScreenDebugMessage(MessageKey, 5.f, FColor::Green, mensaje);
	

	}

}
	/*if (OtherActor != nullptr && OtherActor != this)
	{
		OtherActor->Destroy();
		Destroy();
	}*/

