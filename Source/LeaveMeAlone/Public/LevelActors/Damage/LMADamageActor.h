// LeaveMeAlone Game by Netologya. All rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"

#include "LMADamageActor.generated.h"

UCLASS()
class LEAVEMEALONE_API ALMADamageActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALMADamageActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USphereComponent* SphereComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float Damage = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float SphereRadius = 100.0f;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};