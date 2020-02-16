// Fill out your copyright notice in the Description page of Project Settings.


#include "AUnit.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAUnit::AAUnit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	meshComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AAUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAUnit::PlayRandomSound(bool playerLocation)
{
	int soundListSize = soundList.Num();
	int randomNumber = FMath::RandRange(0, soundListSize - 1);
	USoundBase* playableSound = soundList[randomNumber];

	if (playerLocation) {
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), playableSound, GetActorLocation(), 1.0f, 1.0f, 0.0f, soundAttenuation, soundConcurrency);
	}
	else {
		FVector playerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

		UGameplayStatics::PlaySoundAtLocation(GetWorld(), playableSound, playerLocation, 1.0f, 1.0f, 0.0f, soundAttenuation, soundConcurrency);
	}
}

