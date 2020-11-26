// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Facade/MVC_Facade.h"
#include "Model/MVC_Proxy.h"
#include "View/MVC_Meditor.h"
#include "Controller/MVC_Command.h"
#include "Blueprint/UserWidget.h"
#include "Flib_UPM.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPUREMVC_API UFlib_UPM : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	//will initializer facade
	UFUNCTION(BlueprintCallable ,Category = "UnrealPureMVC", meta=(WorldContext = "worldContext", CallableWithoutWorldContext))
		static UMVC_Facade* CreateFacade(UObject* worldContext, TSubclassOf<UMVC_Facade> facadeClass);
	UFUNCTION(BlueprintCallable , Category = "UnrealPureMVC", meta = (WorldContext = "worldContext", CallableWithoutWorldContext))
		static UMVC_Proxy* CreateProxy(UObject* worldContext, TSubclassOf<UMVC_Proxy> proxyClass, const FString& specialName);
	UFUNCTION(BlueprintCallable, Category = "UnrealPureMVC", meta = (WorldContext = "worldContext", CallableWithoutWorldContext))
		static UMVC_Mediator* CreateMediator(UObject* worldContext, TSubclassOf<UMVC_Mediator> mediatorClass, UObject* Instance, const FString& specialName);
	UFUNCTION(BlueprintCallable, Category = "UnrealPureMVC", meta = (WorldContext = "worldContext", CallableWithoutWorldContext))
		static UMVC_Command* CreateCommand(UObject* worldContext, TSubclassOf<UMVC_Command> commandClass);
	UFUNCTION(BlueprintCallable, Category = "UnrealPureMVC", meta = (WorldContext = "worldContext", CallableWithoutWorldContext))
		static UUserWidget* CreateWidgetObject(UObject* worldContext, TSubclassOf<UUserWidget> umgClass);


	UFUNCTION(BlueprintCallable, BlueprintPure ,Category = "UnrealPureMVC", meta = (WorldContext = "worldContext", CallableWithoutWorldContext))
		static FString GetProxyNameByClass(TSubclassOf<UMVC_Proxy> proxyClass);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UnrealPureMVC", meta = (WorldContext = "worldContext", CallableWithoutWorldContext))
		static FString GetMediatorNameByClass(TSubclassOf<UMVC_Mediator> mediatorClass);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UnrealPureMVC", meta = (WorldContext = "worldContext", CallableWithoutWorldContext))
		static FString GetCommandNameByClass(TSubclassOf<UMVC_Command> commandrClass);
};
