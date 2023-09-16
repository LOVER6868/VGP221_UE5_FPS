// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameOverWidget.h"
#include <Kismet/GameplayStatics.h>

void UFPSGameOverWidget::NativeConstruct()
{
	RetryButton->OnClicked.AddDynamic(this, &UFPSGameOverWidget::OnRetryClicked);
	MenuButton->OnClicked.AddDynamic(this, &UFPSGameOverWidget::OnMenuClicked);
}

void UFPSGameOverWidget::OnRetryClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "FPSMap", true);
}

void UFPSGameOverWidget::OnMenuClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "MainMenu", true);
}
