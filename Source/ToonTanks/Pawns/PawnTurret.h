// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTurret.generated.h"

/**
 * 
 */

class APawnTank;

UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "True"))
	float FireRate = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "True"))
	float AttackDistance = 500.0f;
	float DistanceToPlayer();
	void CheckFireCondition();
	FTimerHandle FireRateTimerHandle;
	APawnTank* PlayerPawn;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called when the game starts or when spawned
protected:
	virtual void BeginPlay() override;

	
};
