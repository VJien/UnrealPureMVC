// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Patterns/Mediator/MVC_Meditor.h"
#include "UPM_Mediator.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUPMMulDlg);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUPMMulDlgOneParam, UMVC_Notification*, notification);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUPMMulDlgTwoParams, const FString&, notification, UObject*, body);

UCLASS()
class UNREALPUREMVC_API UUPM_Mediator : public UMVC_Mediator
{
	GENERATED_BODY()
public:
	void OnRegister_Implementation()override;
	void OnRemove_Implementation()override;
	TArray<FString> ListNotificationInterests_Implementation()const override;


	void SendNotification_Implementation(const FString& notification, UObject* body) override;

	void HandleNotification_Implementation(UMVC_Notification* notification)override;


	UPROPERTY(BlueprintCallable,BlueprintAssignable)
		FUPMMulDlg OnRegistered;
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
		FUPMMulDlg OnRemoved;
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
		FUPMMulDlgOneParam OnHandleNotification;
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
		FUPMMulDlgTwoParams OnSendNotification;


	UPROPERTY(BlueprintReadWrite,EditAnywhere)
		TArray<FString> NotificationInterests;
	
};
