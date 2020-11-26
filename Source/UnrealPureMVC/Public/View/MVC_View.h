// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Observer/MVC_Observer.h"
#include "MVC_View.generated.h"

class UMVC_Mediator;

/**
 * 
 */
USTRUCT()
struct FObserverArray2
{
	GENERATED_BODY()

public:
	FObserverArray2()
		:Observers(TArray<UMVC_Observer*>())
	{};

	UPROPERTY()
		TArray<UMVC_Observer*> Observers;
};


UCLASS()
class UNREALPUREMVC_API UMVC_View : public UObject
{
	GENERATED_UCLASS_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | View")
		void RegisterObserver(const FString& NotificationName, UMVC_Observer* observer);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | View")
		void RemoveObserver(const FString& NotificationName, UObject* notifyObject);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | View")
		void NotifyObservers(UMVC_Notification* noitifyCation);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | View")
		void RegisterMeditor(UMVC_Mediator* mediator);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | View")
		UMVC_Mediator* RetrieveMediator(const FString& mediatorName)const;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | View")
		bool RemoveMediator(const FString& mediatorName);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | View")
		bool HasMediator(const FString& mediatorName) ;
protected:
	UPROPERTY()
		TMap<FString, UMVC_Mediator*> MediatorMap;

	UPROPERTY()
		TMap<FString, FObserverArray2> ObserverMap;

	UPROPERTY()
		UMVC_Mediator* EmptyMediator;
};
