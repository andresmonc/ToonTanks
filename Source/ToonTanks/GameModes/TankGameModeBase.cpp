// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"

void ATankGameModeBase::BeginPlay() 
{
    // Get references and game win/lose conditions
    // Call handlegamestart()
}

void ATankGameModeBase::HandleGameStart() 
{
    // Init start countdown, turret activation, pawn check, etc.
    // call gamestart
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon) 
{
    
}

void ATankGameModeBase::ActorDied(AActor* DeadActor) 
{
    // check what actor has been killed
}


