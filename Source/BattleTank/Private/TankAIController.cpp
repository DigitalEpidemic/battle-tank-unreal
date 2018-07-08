// Copyright 2018 Jeffrey Polasz. All Rights Reserved.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }
		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO Check if radius is in cm

		// Aim towards the player
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		AimingComponent->Fire(); // TODO Limit firing rate
}
