// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Observer/MVC_Notifier.h"
#include "MVC_Proxy.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class UNREALPUREMVC_API UMVC_Proxy : public UMVC_Notifier
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Proxy")
		void SetInfo(const FString& Name);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Proxy")
		void OnRegister();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Proxy")
		void OnRemove();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Proxy")
		FString GetProxyName()const;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Proxy")
		void SetData(UObject* Data);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Proxy")
		UObject* GetProxyData()const;

public:
	




protected:
	UPROPERTY()
		UObject* ProxyData;
	UPROPERTY()
		FString ProxyName;
};
