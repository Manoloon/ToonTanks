// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTank.h"
#include "PlayerTank.generated.h"


class USpringArmComponent;
class UCameraComponent;
/**
 * 
 */
UCLASS()
class TOONTANKS_API APlayerTank : public ABaseTank
{
	GENERATED_BODY()

public:
	APlayerTank();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	UPROPERTY(EditDefaultsOnly)
		USpringArmComponent* SpringArmComp;
	UPROPERTY(EditDefaultsOnly)
		UCameraComponent* CameraComp;
};
