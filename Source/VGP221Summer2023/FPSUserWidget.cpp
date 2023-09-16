// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSUserWidget.h"

void UFPSUserWidget::NativeConstruct()
{
	SetHealthBar(1.0);
	SetScore(0);
	SetAmmo(10,10);
	SetEnemyBar(1.0);

	/*if (ButtonWidgetRef)
	{
		for (int i = 0; i < 4; i++)
		{
			UUserWidget* widget = CreateWidget(this, ButtonWidgetRef);
			VerticalBox->AddChildToVerticalBox(widget);
			UButtonWidget* button = Cast<UButtonWidget>(widget);
			button->SetText(i);
		}
	}*/
}

void UFPSUserWidget::SetHealthBar(float percetnage)
{
	if (!HealthBar) return;

	HealthBar->SetPercent(percetnage);
}

void UFPSUserWidget::SetEnemyBar(float percetnage)
{
	if (!EnemyBar) return;

	EnemyBar->SetPercent(percetnage);
}

void UFPSUserWidget::SetScore(int scoreAmount)
{
	if (!Score) return;

	UIScore += scoreAmount;
	Score->SetText(FText::FromString("Score :" + FString::FromInt(UIScore)));
}

void UFPSUserWidget::SetAmmo(int ammo, int maxAmmo)
{
	if (!Ammo) return;

	Ammo->SetText(FText::FromString("Ammo :" + FString::FromInt(ammo) + "/" + FString::FromInt(maxAmmo)));
}
