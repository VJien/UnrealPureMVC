// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MVC_Model.generated.h"

class UMVC_Proxy;

/**
 * 
 */
UCLASS()
class UNREALPUREMVC_API UMVC_Model : public UObject
{
	GENERATED_UCLASS_BODY()
public:
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Model")
		void RegisterProxy(UMVC_Proxy* Proxy);
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Model")
		UMVC_Proxy* RetrieveProxy(const FString& ProxyName)const;
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Model")
		bool RemoveProxy(const FString& ProxyName);
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Model")
		bool HasProxy(const FString& ProxyName)const;




protected:
	UPROPERTY()
		TMap<FString,UMVC_Proxy*> ProxyMap;
	UPROPERTY()
		UMVC_Proxy* DefaultProxy;
};
