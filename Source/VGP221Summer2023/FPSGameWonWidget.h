// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "FPSGameWonWidget.generated.h"

/**
 * 
 */
UCLASS()
class VGP221SUMMER2023_API UFPSGameWonWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UButton* RetryButton;

	UPROPERTY(meta = (BindWidget))
	UButton* MenuButton;

	UFUNCTION()
	void OnRetryClicked();

	UFUNCTION()
	void OnMenuClicked();
};
