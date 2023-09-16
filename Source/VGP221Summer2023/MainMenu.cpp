// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"

void AMainMenu::StartPlay()
{
	Super::StartPlay();

	if (StartingWidgetClass)
	{
		UFPSMainMenuWidget* CurrentWidget = CreateWidget<UFPSMainMenuWidget>(GetWorld(), StartingWidgetClass);
		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();
		}
	}

	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
}