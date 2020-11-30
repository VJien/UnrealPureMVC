// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "IUPMObj.h"
#include "UPM_Widget.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class UNREALPUREMVC_API UUPM_Widget : public UUserWidget, public IIUPMObj
{
	GENERATED_UCLASS_BODY()

public:
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

	UPROPERTY()
		FString CustomName;

protected:
	UPROPERTY(Instanced)
		UUPM_Mediator* ownMediator;
	

};
