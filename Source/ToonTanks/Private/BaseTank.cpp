// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTank.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ABaseTank::ABaseTank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));
	RootComponent = CapsuleComp;
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh->SetupAttachment(RootComponent);
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	TurretMesh->SetupAttachment(BaseMesh);
 	ProjectilSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectilSpawnPoint"));
 	ProjectilSpawnPoint->SetupAttachment(TurretMesh);
}

// Called when the game starts or when spawned
void ABaseTank::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseTank::Fire()
{
	// get projectilespawnpoint location and rotation and spawn projectile class from that.
}

void ABaseTank::RotateTurret(FVector LookAtTarget)
{
	//TurretMesh->SetWorldRotation(LookAtTarget);
}

void ABaseTank::HandleDestruction()
{
	// play death anim
}

// Called every frame
void ABaseTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

