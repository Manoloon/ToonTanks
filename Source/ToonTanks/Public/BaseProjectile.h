// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseProjectile.generated.h"

class UProjectileMovementComponent;
class UStaticMeshComponent;

UCLASS()
class TOONTANKS_API ABaseProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditDefaultsOnly)
		UProjectileMovementComponent* ProjectileComp;
	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* MeshComp;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UDamageType>DamageType;
	UPROPERTY(EditDefaultsOnly)
		float Damage = 50;
	UPROPERTY(EditDefaultsOnly)
		float MovementSpeed = 1300;




};
