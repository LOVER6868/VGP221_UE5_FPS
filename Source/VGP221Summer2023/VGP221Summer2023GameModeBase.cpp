// Copyright Epic Games, Inc. All Rights Reserved.


#include "VGP221Summer2023GameModeBase.h"
#include <Kismet/GameplayStatics.h>
#include "EnemyAICharacter.h"

void AVGP221Summer2023GameModeBase::StartPlay()
{
	Super::StartPlay();

	// C asset() <- stop the code here
	check(GEngine != nullptr)
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World! This is FPSGameModeBase!"));

	UE_LOG(LogTemp, Warning, TEXT("Hello World! This is FPSGameModeBase!"));

	// Spawn the starting UI
	// Make sure there's one UI on screen, destroy it
	if (CurrentWidget)
	{
		CurrentWidget->RemoveFromParent();
		CurrentWidget = nullptr;
	}

	// If no UI we gonna spawn one
	if (StartingWidgetClass)
	{
		CurrentWidget = CreateWidget<UFPSUserWidget>(GetWorld(), StartingWidgetClass);
		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();
		}
	}

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyAICharacter::StaticClass(), FoundActors);

	MaxEnemies = FoundActors.Num();
	CurrentEnemies = MaxEnemies;

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Max Enemies: " + FString::FromInt(MaxEnemies)));

	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = false;
}

void AVGP221Summer2023GameModeBase::WinGame()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Won Game"));
	UGameplayStatics::SetGamePaused(UGameplayStatics::GetGameMode(GetWorld()), true);

	if (GameWonWidgetClass)
	{
		UFPSGameWonWidget* GameWonWidget = CreateWidget<UFPSGameWonWidget>(GetWorld(), GameWonWidgetClass);
		if (GameWonWidget)
		{
			GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
			GameWonWidget->AddToViewport();
		}
	}
}

void AVGP221Summer2023GameModeBase::LoseGame()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Loss Game"));
	UGameplayStatics::SetGamePaused(UGameplayStatics::GetGameMode(GetWorld()),true);

	if (GameOverWidgetClass)
	{
		UFPSGameOverWidget* GameOverWidget = CreateWidget<UFPSGameOverWidget>(GetWorld(), GameOverWidgetClass);
		if (GameOverWidget)
		{
			GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
			GameOverWidget->AddToViewport();
		}
	}
}