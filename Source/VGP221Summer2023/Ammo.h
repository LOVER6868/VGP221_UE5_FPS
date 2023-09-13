// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Collectable.h"
#include "Kismet/GameplayStatics.h"
#include "VGP221Summer2023GameModeBase.h"
#include "Ammo.generated.h"

UCLASS()
class VGP221SUMMER2023_API AAmmo : public ACollectable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmmo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnCollect() override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* AmmoMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationRate = 100;

	FTimerHandle DeathTimerHandle;

	void DeathTimerComplete();

	int ammoPoints = 5;
};
