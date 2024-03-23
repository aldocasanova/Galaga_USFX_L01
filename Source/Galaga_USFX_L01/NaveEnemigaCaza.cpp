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
    FireRate = rand() % 12 + 1; // Intervalo de tiempo entre disparos en segundos, formula 

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
        bCanFire = true; //no todas las balas se disparan seguidas
        
        ShotsFired++;
        if (ShotsFired >= MaxShots)
        {
            bCanFire = true;
            GetWorldTimerManager().ClearTimer(TimerHandle_ShotTimerExpired);
        }
        if (FireSound != nullptr)
        {
            UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
        }
        // If we are pressing fire stick in a direction

    }
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
    Desplazamiento(); 
}

void ANaveEnemigaCaza::Mover(float DeltaTime)
{
	velocidad = 0.65; //0.75
	SetActorLocation(FVector(GetActorLocation().X - velocidad, GetActorLocation().Y, GetActorLocation().Z));

	if (GetActorLocation().X < LimiteInferiorX) 
	{
		Desplazamiento();
		//SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, 250.0f));
		SetActorLocation(FVector(400.0f, GetActorLocation().Y, 250.0f));
	}
}



void ANaveEnemigaCaza::Desplazamiento()
{
	AmplitudZigzag = 50.0f;
	VelocidadZigzag = 0.5f;
	// Guarda la posición inicial para calcular el desplazamiento relativo
	FVector PosicionInicial = GetActorLocation();

	// Inicia el movimiento en zigzag
	while (FMath::Abs(GetActorLocation().X - PosicionInicial.X) > 0.1f) // mientras no esté en la posición inicial en X
	{
		// Calcula el desplazamiento en Z usando una función sinusoidal para el movimiento en zigzag
		float DesplazamientoZ = AmplitudZigzag * FMath::Sin((GetActorLocation().X - PosicionInicial.X) / AmplitudZigzag);

		// Mueve la nave en zigzag
		SetActorLocation(FVector(GetActorLocation().X - VelocidadZigzag, GetActorLocation().Y, PosicionInicial.Z + DesplazamientoZ));

		// Espera un pequeño lapso de tiempo para darle fluidez al movimiento (se puede ajustar según la velocidad de juego)
		FPlatformProcess::Sleep(0.02f);
	}
	//DesplazamientoCaza();
}

void ANaveEnemigaCaza::Destruirse()
{
}

/*void ANaveEnemigaCaza::BeginPlay()
{
    Super::BeginPlay();

    // Iniciar el temporizador con un retraso aleatorio para el primer disparo
    float InitialDelay = FMath::RandRange(1.0f, FireRate); // Retraso aleatorio entre 1 y FireRate segundos
    GetWorld()->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveEnemigaCaza::Disparar, InitialDelay, true);
}*/