// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MVC_Notification.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPUREMVC_API UMVC_Notification : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "UnrealPureMVC | Notification")
		void SetInfo(const FString& name, UObject* body = nullptr);

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Notification")
		FString GetName() const ;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Notification")
		UObject* GetBody() const ;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Notification")
		FString ToString() const ;

protected:
	UPROPERTY()
		UObject* Body;

	FString Name;
};
