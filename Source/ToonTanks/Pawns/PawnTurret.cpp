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

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APawnTurret::CheckFireCondition() 
{
    // If player == null || is Dead then bail !!
    if (!PlayerPawn){
        return;
    }
    // If player Is in range THEN FIRE!!
    if (DistanceToPlayer() <= AttackDistance){
        UE_LOG(LogTemp, Warning, TEXT("FIRING!!!!!"))    
    }

    UE_LOG(LogTemp, Warning, TEXT("FIRE CONDITION CHECKED!!!"))
}

float APawnTurret::DistanceToPlayer()
{       
    if (!PlayerPawn){
        return 0.0f;
    }
    return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}