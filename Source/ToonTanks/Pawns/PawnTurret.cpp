// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::HandleDestruction() 
{
    // Call the base pawn class destruction for shared effects
    Super::HandleDestruction();
    Destroy();
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    if(!PlayerPawn || DistanceToPlayer() > AttackDistance)
    {
        return;
    }
    RotateTurret(PlayerPawn->GetActorLocation());
    Fire();
}

void APawnTurret::CheckFireCondition() 
{
    // If player == null || is Dead then bail !!
    if (!PlayerPawn){
        return;
    }
    // If player Is in range THEN FIRE!!
    if (DistanceToPlayer() <= AttackDistance){
        UE_LOG(LogTemp, Warning, TEXT("FIRING!!!!!"));
        Fire();
    }

    UE_LOG(LogTemp, Warning, TEXT("FIRE CONDITION CHECKED!!!"))
}

void APawnTurret::Destroy() 
{
    
}

float APawnTurret::DistanceToPlayer()
{       
    if (!PlayerPawn){
        return 0.0f;
    }
    return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}

