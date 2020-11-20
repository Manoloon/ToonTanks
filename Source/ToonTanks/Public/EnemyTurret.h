// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTank.h"
#include "EnemyTurret.generated.h"

class APlayerTank;
/**
 * 
 */
UCLASS()
class TOONTANKS_API AEnemyTurret : public ABaseTank
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
		float FireRate = 2.0f;
	UPROPERTY(EditDefaultsOnly)
		float FireRange = 520.0f;

	APlayerTank* PlayerTank;

public:
	// Sets default values for this pawn's properties
	AEnemyTurret();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle FireRateTimerHandle;
	void CheckFireCondition();

	float GetDistanceToPlayer();

	

};
