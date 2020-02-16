// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundAttenuation.h"
#include "Components/StaticMeshComponent.h"
#include "AUnit.generated.h"

UCLASS()
class BFMERTESTPROJECT_API AAUnit : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAUnit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY(EditAnywhere, Category = "Components")
		UStaticMeshComponent* meshComponent;

	UPROPERTY(EditAnywhere, Category = "Sounds")
		TArray<USoundBase*> soundList;

	UPROPERTY(EditAnywhere, Category = "Sounds")
		USoundAttenuation* soundAttenuation;

	UPROPERTY(EditAnywhere, Category = "Sounds")
		USoundConcurrency* soundConcurrency;

	UFUNCTION(BlueprintCallable)
		void PlayRandomSound(bool playerLocation);
};
