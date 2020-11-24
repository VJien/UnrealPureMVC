// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Observer/MVC_Notifier.h"
#include "MVC_Meditor.generated.h"

class UMVC_Notification;
class UMVC_Proxy;

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class UNREALPUREMVC_API UMVC_Meditor : public UMVC_Notifier
{
	GENERATED_BODY()
public:


	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Meditor")
		void Init(const FString& mediatorName, UObject* viewInstance);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Meditor")
		void OnRegister();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Meditor")
		void OnRemove();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Meditor")
		TArray<FString> ListNotificationInterests()const;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Meditor")
		void HandleNotification(UMVC_Notification* notification);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "MVCFramework|Mediator")
		 UMVC_Proxy* RetrieveProxy(const FString& ProxyName) ;

	UFUNCTION(BlueprintCallable, Category = "UnrealPureMVC | Meditor")
		FString GetMeditorName()const { return MediatorName; };
	UFUNCTION(BlueprintCallable, Category = "UnrealPureMVC | Meditor")
		UObject* GetViewInstance()const { return ViewInstance; };

protected:
	FString MediatorName;

	UPROPERTY(BlueprintReadOnly, Category = "UnrealPureMVC | Meditor")
		UObject* ViewInstance;
};
