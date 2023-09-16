// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSMainMenuWidget.h"
#include <Kismet/GameplayStatics.h>

void UFPSMainMenuWidget::NativeConstruct()
{
	PlayButton->OnClicked.AddDynamic(this, &UFPSMainMenuWidget::OnPlayClicked);
	QuitButton->OnClicked.AddDynamic(this, &UFPSMainMenuWidget::OnQuitClicked);
}

void UFPSMainMenuWidget::OnPlayClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "FPSMap", true);
}

void UFPSMainMenuWidget::OnQuitClicked()
{
	UKismetSystemLibrary::QuitGame(GetWorld(),0, EQuitPreference::Quit, false);
}
