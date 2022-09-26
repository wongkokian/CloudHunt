// Fill out your copyright notice in the Description page of Project Settings.


#include "CLM_Character.h"

// Sets default values
ACLM_Character::ACLM_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACLM_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACLM_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACLM_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool ACLM_Character::CanBeSeenFrom(const FVector& ObserverLocation, FVector& OutSeenLocation, int32& NumberOfLoSChecksPerformed, float& OutSightStrength, const AActor* IgnoreActor, const bool* bWasVisible, int32* UserData) const
{
	FName Name_AILineOfSight = FName(TEXT("TestPawnLineOfSight"));
	FHitResult HitResult; 
	FVector SightTargetLocation = GetMesh()->GetSocketLocation("neck_01");

	bool hit = GetWorld()->LineTraceSingleByChannel(HitResult, ObserverLocation, SightTargetLocation, ECC_Visibility, FCollisionQueryParams(Name_AILineOfSight, true, IgnoreActor));

	if (!hit || IsValid(HitResult.GetActor()) && HitResult.GetActor()->IsOwnedBy(this))
	{
		OutSeenLocation = SightTargetLocation;
		OutSightStrength = 1;
		return true;
	}

	OutSightStrength = 0;
	return false;
}

