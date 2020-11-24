// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MVC_Notifier.generated.h"

class UMVC_Facade;

/**
 * 
 */
UCLASS()
class UNREALPUREMVC_API UMVC_Notifier : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Notifier")
		void SendNotification(const FString& NotificationName, UObject* body = nullptr) ;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Notifier")
		void SetFacade(UMVC_Facade* facade);



protected:
	UPROPERTY()
		UMVC_Facade* Facade;
};
