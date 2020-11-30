// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "IUPMObj.h"
#include "Patterns/Facade/MVC_Facade.h"
#include "Patterns/Observer/MVC_Notification.h"
#include "UPM_Mediator.h"
#include "UPM_Pawn.generated.h"

UCLASS(Blueprintable,BlueprintType)
class UNREALPUREMVC_API AUPM_Pawn : public APawn, public IIUPMObj
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AUPM_Pawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	/*UPM Interface*/

	virtual void SendNotification_Implementation(const FString& notification, UObject* body) override;

	virtual void HandleNotification_Implementation(UMVC_Notification* notification)override;

	virtual FString GetOwnMeditorName_Implementation()const override;

	virtual UMVC_Proxy* RetrieveProxy_Implementation(const FString& ProxyName)override;

	virtual void OnRegister_Implementation()override;

	virtual void OnRemove_Implementation()override;

	virtual TArray<FString> ListNotificationInterests_Implementation()const override;

	virtual UMVC_Facade* GetOwnFacade_Implementation()const override;

	virtual void RegisterUPMObject_Implementation(UMVC_Facade* facade)override;

	virtual UUPM_Mediator* GetOwnMediator_Implementation()const override;
	/*UPM END*/



protected:
	UPROPERTY()
		UUPM_Mediator* ownMediator;
};
