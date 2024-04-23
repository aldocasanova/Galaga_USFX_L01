#include "NaveEnemigaCaza.h"
#include "Galaga_USFX_L01Projectile.h"
#include "Galaga_USFX_L01GameMode.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProyectilEnemigo.h"

#include "Kismet/GameplayStatics.h"

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));
    mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

    // Cache our sound effect
    static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
    FireSound = FireAudio.Object;

    PrimaryActorTick.bCanEverTick = true;

    //FireRate = 4.0f; // Intervalo de tiempo entre disparos en segundos
    FireRate = rand() % 4 + 1; // Intervalo de tiempo entre disparos en segundos, formula 

    MaxShots = 3; // Cantidad máxima de disparos
    ShotsFired = 0; // Inicializar contador de disparos

    bCanFire = true; // Permitir disparos al principio
}

void ANaveEnemigaCaza::Disparar()
{
    FVector SpawnLocation = GetActorLocation() + -(GetActorForwardVector() * 1);

    if (bCanFire == true && ShotsFired < MaxShots)
    {
        UWorld* World = GetWorld();
        if (World)
        {
            AProyectilEnemigo* NewProjectile = World->SpawnActor<AProyectilEnemigo>(SpawnLocation, FRotator::ZeroRotator);
        }
        World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveEnemigaCaza::ShotTimerExpired, FireRate);
        bCanFire = false; //no todas las balas se disparan seguidas
        
        ShotsFired++;
        if (ShotsFired >= MaxShots)
        {
           bCanFire = false;
           GetWorldTimerManager().ClearTimer(TimerHandle_ShotTimerExpired);
        }
        if (FireSound != nullptr)
        {
            UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
        }
        // If we are pressing fire stick in a direction

    }
}
void ANaveEnemigaCaza::Destruirse()
{
}
void ANaveEnemigaCaza::ShotTimerExpired()
{
    bCanFire = true;
}

void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
    Disparar();
    Desplazamiento(DeltaTime); 
    StartFly();
}

void ANaveEnemigaCaza::Mover(float DeltaTime)
{
	velocidad = 0.65; //0.75
	SetActorLocation(FVector(GetActorLocation().X - velocidad, GetActorLocation().Y, GetActorLocation().Z));

	if (GetActorLocation().X < LimiteInferiorX) 
	{
		//SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, 250.0f));
		SetActorLocation(FVector(800.0f, GetActorLocation().Y, 250.0f));
	}
}



void ANaveEnemigaCaza::Desplazamiento(float DeltaTime)
{
    AmplitudZigzag =1.0f;
	VelocidadZigzag = 5.0f;

    FVector NewLocation = FVector(GetActorLocation().X, GetActorLocation().Y + AmplitudZigzag * FMath::Sin(VelocidadZigzag * GetWorld()->GetTimeSeconds()), GetActorLocation().Z);
    SetActorLocation(NewLocation);
}

void ANaveEnemigaCaza::StartFly()
{
}


