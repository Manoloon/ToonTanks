// Fill out your copyright notice in the Description page of Project Settings.


#include "TanksGameModeBase.h"
#include "PlayerTank.h"
#include "EnemyTurret.h"
#include "Kismet/GameplayStatics.h"

void ATanksGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	HandleGameStart();
}

void ATanksGameModeBase::ActorDied(AActor* DeadActor)
{
	if (DeadActor == PlayerTank)
	{
		PlayerTank->HandleDestruction();
		GameOver(false);
	}
	else if (AEnemyTurret* DestroyedTurret = Cast<AEnemyTurret>(DeadActor))
	{
		DestroyedTurret->HandleDestruction();
		if(--TargetTurret <=0)
		{
			GameOver(true);
		}
	}
}

void ATanksGameModeBase::HandleGameStart()
{
	TargetTurret = GetTargetTurretCount();
	PlayerTank = Cast<APlayerTank>(UGameplayStatics::GetPlayerPawn(this, 0));
	GameStart();
}

void ATanksGameModeBase::HandleGameOver(bool PlayerWon)
{
	GameOver(PlayerWon);
}

int32 ATanksGameModeBase::GetTargetTurretCount()
{
	TArray<AActor*>TurretActor;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyTurret::StaticClass(), TurretActor);
	return TurretActor.Num();
}

