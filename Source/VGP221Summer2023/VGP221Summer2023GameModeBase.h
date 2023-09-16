// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPSUserWidget.h"
#include "FPSGameOverWidget.h"
#include "FPSGameWonWidget.h"
#include "VGP221Summer2023GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class VGP221SUMMER2023_API AVGP221Summer2023GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	int CurrentEnemies;
	int MaxEnemies;

	UPROPERTY()
		UFPSUserWidget* CurrentWidget;

		ACharacter* Player;

	UFUNCTION()
		void WinGame();

	UFUNCTION()
		void LoseGame();

protected:
	virtual void StartPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<class UFPSUserWidget> StartingWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<class UFPSGameOverWidget> GameOverWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<class UFPSGameWonWidget> GameWonWidgetClass;
};
