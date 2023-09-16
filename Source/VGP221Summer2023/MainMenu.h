// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPSMainMenuWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class VGP221SUMMER2023_API AMainMenu : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void StartPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<class UFPSMainMenuWidget> StartingWidgetClass;
};
