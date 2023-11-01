// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	//ShowInformation();
	ShowActorInformation();

	//InitialLocation = FVector(0.0f, 0.0f, 0.0f);
	InitialLocation = GetActorLocation();
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACppBaseActor::ShowInformation() {
	
	UE_LOG(LogTemp, Display, TEXT("PlayerName: %s"), *PlayerName);

	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Black, PlayerName, true, FVector2D(2.0f, 2.0f));

	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Warning, TEXT("CurrentHealth: %f"), CurrentHealth);
	UE_LOG(LogTemp, Error, TEXT("IsAlive: %i"), IsAlive);

}

void ACppBaseActor::ShowActorInformation() {
	UE_LOG(LogTemp, Display, TEXT("Instance name: %s"), *(this->GetName()));
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
}

void ACppBaseActor::SinMovement(float time) {
	FVector NewLocation;
	NewLocation.X = InitialLocation.X;
	NewLocation.Y = InitialLocation.Y;
	NewLocation.Z = InitialLocation.Z + Amplitude * FMath::Sin(time * Frequency);
	SetActorLocation(NewLocation);
}


