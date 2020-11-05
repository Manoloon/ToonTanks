// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerTank.h"


AEnemyTurret::AEnemyTurret()
{

}

void AEnemyTurret::BeginPlay()
{
	Super::BeginPlay();
	PlayerTank = Cast<APlayerTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void AEnemyTurret::CheckFireCondition()
{
	if(!PlayerTank) { return; }
	if(GetDistanceToPlayer()<=FireRange)
	{
		//FIREEE!
	}
}

float AEnemyTurret::GetDistanceToPlayer()
{
	if (!PlayerTank) { return 0.0f; }
	return FVector::Dist(PlayerTank->GetActorLocation(), GetActorLocation());
}

void AEnemyTurret::HandleDestruction()
{
	Super::HandleDestruction();
	// inform game mode 
	// destroy self
}

void AEnemyTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}