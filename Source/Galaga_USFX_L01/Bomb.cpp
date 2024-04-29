#include "Bomb.h"
#include "Galaga_USFX_L01Projectile.h"
#include "Galaga_USFX_L01GameMode.h"
#include "ProyectilEnemigo.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"

// Sets default values
ABomb::ABomb()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BombMeshAsset(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));
	BombMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BombMesh"));
	BombMesh->SetStaticMesh(BombMeshAsset.Object);
	//BombMesh->SetupAttachment(RootComponent);
	RootComponent = BombMesh;
	velocidad;
	BombMesh->SetRelativeScale3D(FVector(3.0f,3.0f,3.0f));
}

// Called when the game starts or when spawned
void ABomb::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TiempoExplosion += GetWorld()->DeltaTimeSeconds; //inremento sincronizado con el tiempo del mundo
	Desaparecer(TiempoExplosion);	
	Mover(DeltaTime);
}

void ABomb::Mover(float DeltaTime)
{
	velocidad = 9; 
	SetActorLocation(FVector(GetActorLocation().X - velocidad, GetActorLocation().Y, GetActorLocation().Z));
}

void ABomb::Desaparecer(float _TiempoExplosion)
{
	if (_TiempoExplosion > 2.8)
	{
		Destroy();
	}
}

/*void ABomb::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		AGalaga_USFX_L01GameMode* GameMode = Cast<AGalaga_USFX_L01GameMode>(UGameplayStatics::GetGameMode(GetWorld()));
		if (GameMode)
		{
			GameMode->TANavesEnemigas.Remove(Cast<ANaveEnemiga>(OtherActor));
			OtherActor->Destroy();
		}
		Destroy();
	}
}*/