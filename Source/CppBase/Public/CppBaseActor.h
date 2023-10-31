// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

//class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EMovementState : uint8 {
	Mobility,
	Static
};

USTRUCT(BlueprintType)
struct FTransformStruct {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurrentRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};


UCLASS()
class CPPBASE_API ACppBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppBaseActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	FString PlayerName = "Vasiliy Pupkin";

	UPROPERTY(EditAnywhere)
	int EnemyNum = 25;

	UPROPERTY(EditDefaultsOnly)
	float CurrentHealth = 57.54687;
	
	UPROPERTY(EditInstanceOnly)
	bool IsAlive = true;

	UPROPERTY(EditDefaultsOnly)
	float Amplitude = 70.0;
	
	UPROPERTY(EditDefaultsOnly)
	float Frequency = 4.0;

	FVector InitialLocation;

	UFUNCTION(BlueprintCallable)
	void ShowInformation();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
	
	UFUNCTION(BlueprintCallable)
	float SinMovement(float time);

private:
	
	void ShowActorInformation();
};
