// Fill out your copyright notice in the Description page of Project Settings.


#include "Ammo.h"
#include "FPSCharacter.h"

// Sets default values
AAmmo::AAmmo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!AmmoMesh)
	{
		AmmoMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AmmoMesh"));
		AmmoMesh->SetupAttachment(CollisionComponent);
	}
}

// Called when the game starts or when spawned
void AAmmo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAmmo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAmmo::OnCollect()
{
	UE_LOG(LogTemp, Warning, TEXT("Coin: OnCollect()"));

	RotationRate = 1500;
	GetWorldTimerManager().SetTimer(DeathTimerHandle, this, &AAmmo::DeathTimerComplete, 0.5f, false);
}

void AAmmo::DeathTimerComplete()
{
	AVGP221Summer2023GameModeBase* GameMode = Cast<AVGP221Summer2023GameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		AFPSCharacter* Player = Cast<AFPSCharacter>(GameMode->Player);
		if (Player)
		{
			Player->Ammo+= ammoPoints;
			if (Player->Ammo > Player->MaxAmmo) Player->Ammo = Player->MaxAmmo;

			GameMode->CurrentWidget->SetAmmo(Player->Ammo, Player->MaxAmmo);
		}
	}

	Destroy();
}

