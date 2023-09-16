// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "FPSMainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class VGP221SUMMER2023_API UFPSMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
		UButton* PlayButton;

	UPROPERTY(meta = (BindWidget))
		UButton* QuitButton;
	
	UFUNCTION()
		void OnPlayClicked();

	UFUNCTION()
		void OnQuitClicked();
};
