// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseTank.generated.h"

class UStaticMeshComponent;
class UCapsuleComponent;
class USceneComponent;

UCLASS()
class TOONTANKS_API ABaseTank : public APawn
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	UCapsuleComponent* CapsuleComp;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(EditDefaultsOnly)
	USceneComponent* ProjectilSpawnPoint;

public:
	// Sets default values for this pawn's properties
	ABaseTank();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Fire();

	void RotateTurret(FVector LookAtTarget);

	virtual void HandleDestruction();

};
