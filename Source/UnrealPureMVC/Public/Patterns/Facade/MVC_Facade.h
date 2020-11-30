// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MVC_Facade.generated.h"

class UMVC_Controller;
class UMVC_View;
class UMVC_Model;
class UMVC_Proxy;
class UMVC_Mediator;

/**
 * 
 */

UCLASS(Blueprintable,BlueprintType)
class UNREALPUREMVC_API UMVC_Facade : public UObject
{
	GENERATED_BODY()


public:



	UFUNCTION(BlueprintCallable,BlueprintNativeEvent, Category = "UnrealPureMVC | Facade")
		void InitializeFacade(UObject* Context);


	/*BP Function*/
	UFUNCTION(BlueprintImplementableEvent,Category="UnrealPureMVC | Facade")
		void  InitializeMeditorImpl(UObject* Context);
	UFUNCTION(BlueprintImplementableEvent, Category = "UnrealPureMVC | Facade")
		void  InitializeProxyImpl(UObject* Context);
	UFUNCTION(BlueprintImplementableEvent, Category = "UnrealPureMVC | Facade")
		void  InitializeCommandImpl(UObject* Context);



	//proxy
	UFUNCTION(BlueprintCallable, Category = "UnrealPureMVC | Facade")
		 void RegisterProxy(UMVC_Proxy* proxy) ;
	UFUNCTION(BlueprintCallable, Category = "UnrealPureMVC | Facade")
		UMVC_Proxy* RetrieveProxy(const FString& ProxyName) const;
	UFUNCTION(BlueprintCallable, Category = "UnrealPureMVC | Facade")
		bool RemoveProxy(const FString& ProxyName);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UnrealPureMVC | Facade")
		bool HasProxy(const FString& ProxyName);

	//Mediator
	UFUNCTION(BlueprintCallable, Category = "UnrealPureMVC | Facade")
		void RegisterMediator(UMVC_Mediator* Mediator) ;
	UFUNCTION(BlueprintCallable, Category = "UnrealPureMVC | Facade")
		UMVC_Mediator* RetrieveMediator(const FString& MediatorName)const;
	UFUNCTION(BlueprintCallable, Category = "UnrealPureMVC | Facade")
		bool RemoveMediator(const FString& MediatorName) ;
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UnrealPureMVC | Facade")
		bool HasMeiator(const FString& MediatorName) ;


	//Command
	UFUNCTION(BlueprintCallable, Category = "UnrealPureMVC | Facade")
		void RegisterCommand(UMVC_Command* command) ;
	UFUNCTION(BlueprintCallable, Category = "UnrealPureMVC | Facade")
		UMVC_Command* RetrieveCommand(const FString& NotificationName)const;
	UFUNCTION(BlueprintCallable, Category = "UnrealPureMVC | Facade")
		bool RemoveCommand(const FString& NotificationName) ;
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UnrealPureMVC | Facade")
		bool HasCommand(const FString& NotificationName) ;



	//Observer
	UFUNCTION(BlueprintCallable, Category = "UnrealPureMVC | Facade")
		void SendNotification(const FString& NotificationName, UObject* body = nullptr);

	
	UMVC_View* GetView()const;


	UPROPERTY(BlueprintReadOnly)
		UObject* WorldContext;
protected:
	UPROPERTY()
		UMVC_Controller* Controller;
	UPROPERTY()
		UMVC_View* View;
	UPROPERTY()
		UMVC_Model* Model;
	


	bool bIsInit;
};
