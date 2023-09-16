// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAICharacter.h"
#include "VGP221Summer2023GameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemyAICharacter::AEnemyAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyAICharacter::BeginPlay()
{
	Super::BeginPlay();
	
	Health = MaxHealth;
}

// Called every frame
void AEnemyAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyAICharacter::TakeDamage(float damage)
{
	Health -= damage;

	if (Health <= 0)
	{
		AVGP221Summer2023GameModeBase* GameMode = Cast<AVGP221Summer2023GameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
		if (GameMode)
		{
			GameMode->CurrentEnemies--;

			GameMode->CurrentWidget->SetEnemyBar(float(GameMode->CurrentEnemies) / float(GameMode->MaxEnemies));

			Destroy();

			if (GameMode->CurrentEnemies <= 0) GameMode->WinGame();
		}
	}
}

