// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Patterns/Observer/MVC_Notification.h"
#include "Patterns/Proxy/MVC_Proxy.h"
#include "UPM_Mediator.h"
#include "IUPMObj.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIUPMObj : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UNREALPUREMVC_API IIUPMObj
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent, Category = "UnrealPureMVC | UPMObject")
		void SendNotification(const FString& notification,UObject* body);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | UPMObject")
		void HandleNotification(UMVC_Notification* notification);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | UPMObject")
		FString GetOwnMeditorName()const;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | UPMObject")
		UMVC_Proxy* RetrieveProxy(const FString& ProxyName);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | UPMObject")
		void OnRegister();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | UPMObject")
		void OnRemove();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | UPMObject")
		TArray<FString> ListNotificationInterests()const;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | UPMObject")
		UMVC_Facade* GetOwnFacade()const;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | UPMObject")
		UUPM_Mediator* GetOwnMediator()const;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | UPMObject")
		void RegisterUPMObject(UMVC_Facade* facade);
};
