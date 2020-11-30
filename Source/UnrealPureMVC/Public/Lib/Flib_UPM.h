// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Patterns/Facade/MVC_Facade.h"
#include "Patterns/Proxy/MVC_Proxy.h"
#include "Patterns/Mediator/MVC_Meditor.h"
#include "Patterns/Command/MVC_Command.h"
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
	//create proxy object and register to PureMVC
	UFUNCTION(BlueprintCallable , Category = "UnrealPureMVC", meta = (WorldContext = "worldContext", CallableWithoutWorldContext))
		static UMVC_Proxy* CreateProxy(UMVC_Facade* facade, TSubclassOf<UMVC_Proxy> proxyClass, const FString& specialName);
	//create Mediator object and register to PureMVC
	UFUNCTION(BlueprintCallable, Category = "UnrealPureMVC", meta = (WorldContext = "worldContext", CallableWithoutWorldContext))
		static UMVC_Mediator* CreateMediator(UMVC_Facade* facade, TSubclassOf<UMVC_Mediator> mediatorClass, UObject* Instance, const FString& specialName);
	//create Command  object and register to PureMVC
	UFUNCTION(BlueprintCallable, Category = "UnrealPureMVC", meta = (WorldContext = "worldContext", CallableWithoutWorldContext))
		static UMVC_Command* CreateCommand(UMVC_Facade* facade, TSubclassOf<UMVC_Command> commandClass);
	//create UserWidget object and Mediator object, then  register to PureMVC
	UFUNCTION(BlueprintCallable, Category = "UnrealPureMVC", meta = (WorldContext = "worldContext", CallableWithoutWorldContext))
		static UUserWidget* CreateWidgetObject(UMVC_Facade* facade, TSubclassOf<UUserWidget> umgClass, TSubclassOf<UMVC_Mediator> mediatorClass, const FString& specialName);



	UFUNCTION(BlueprintCallable, BlueprintPure ,Category = "UnrealPureMVC", meta = (WorldContext = "worldContext", CallableWithoutWorldContext))
		static FString GetProxyClassName(TSubclassOf<UMVC_Proxy> proxyClass);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UnrealPureMVC", meta = (WorldContext = "worldContext", CallableWithoutWorldContext))
		static FString GetMediatorClassName(TSubclassOf<UMVC_Mediator> mediatorClass);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UnrealPureMVC", meta = (WorldContext = "worldContext", CallableWithoutWorldContext))
		static FString GetCommandClassName(TSubclassOf<UMVC_Command> commandrClass);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UnrealPureMVC", meta = (WorldContext = "worldContext", CallableWithoutWorldContext))
		static TArray<FAssetData> FindAllClass(UObject* worldContext, FName Type);

};
