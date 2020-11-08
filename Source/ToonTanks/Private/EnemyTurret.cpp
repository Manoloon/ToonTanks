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
	
	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &AEnemyTurret::CheckFireCondition, FireRate, true);
	PlayerTank = Cast<APlayerTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void AEnemyTurret::CheckFireCondition()
{
	if(!PlayerTank) { return; }
	if(GetDistanceToPlayer()<=FireRange)
	{
		Fire();
	}
}

float AEnemyTurret::GetDistanceToPlayer()
{
	if (!PlayerTank) {return 0.0f;}
	return FVector::Dist(PlayerTank->GetActorLocation(), GetActorLocation());
}

void AEnemyTurret::HandleDestruction()
{
	Super::HandleDestruction();
	// inform game mode 
	Destroy();
}

void AEnemyTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!PlayerTank || GetDistanceToPlayer() > FireRange)
	{
		UE_LOG(LogTemp, Warning, TEXT("no player pawn"));
		return; 
	}
	RotateTurret(PlayerTank->GetActorLocation());
}