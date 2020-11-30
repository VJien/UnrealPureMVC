// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MVC_Controller.generated.h"

class UMVC_Command;
class UMVC_View;
class UMVC_Notification;

/**
 * 
 */
UCLASS()
class UNREALPUREMVC_API UMVC_Controller : public UObject
{
	GENERATED_UCLASS_BODY()
public:
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Controller")
		void Init(UMVC_View* view);
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Controller")
		void RegisterCommand(const FString& notificationName, UMVC_Command* command);
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Controller")
		UMVC_Command* RetrieveCommand(const FString& notificationName);
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Controller")
		void ExecuteCommand(UMVC_Notification* notification);
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Controller")
		bool RemoveCommand(const FString& noitificationName);
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "UnrealPureMVC | Controller")
		bool HasCommand(const FString& notificationName)const;




protected:
	UPROPERTY()
		TMap<FString, UMVC_Command*> CommandMap;
	UPROPERTY()
		UMVC_View* View;
	UPROPERTY()
		UMVC_Command* EmptyCommand;
};
