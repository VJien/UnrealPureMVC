// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Observer/MVC_Notifier.h"
#include "MVC_Command.generated.h"

class UMVC_Notification;
class UMVC_Proxy;
class UMVC_Mediator;

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class UNREALPUREMVC_API UMVC_Command : public UMVC_Notifier
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Command")
		void Execute(UMVC_Notification* notification);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Command")
		UMVC_Proxy* RetrieveProxy(const FString& proxyName)const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Command")
		UMVC_Mediator* RetrieveMediator(const FString& mediatorName)const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Command")
		FString GetName()const;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Command")
		void SetInfo(const FString& commandName);
protected:
	FString Name;

};
