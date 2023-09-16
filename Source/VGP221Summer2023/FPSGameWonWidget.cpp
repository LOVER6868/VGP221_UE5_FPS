// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameWonWidget.h"
#include <Kismet/GameplayStatics.h>

void UFPSGameWonWidget::NativeConstruct()
{
	RetryButton->OnClicked.AddDynamic(this, &UFPSGameWonWidget::OnRetryClicked);
	MenuButton->OnClicked.AddDynamic(this, &UFPSGameWonWidget::OnMenuClicked);
}

void UFPSGameWonWidget::OnRetryClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "FPSMap", true);
}

void UFPSGameWonWidget::OnMenuClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "MainMenu", true);
}
