// Fill out your copyright notice in the Description page of Project Settings.


#include "Lib/Flib_UPM.h"
#include "UnrealPureMVC.h"
#include "Modules/ModuleManager.h"
#include "IAssetTools.h"
#include "AssetData.h"
#include "AssetRegistryModule.h"
#include "Engine/StaticMesh.h"
#include "Engine/Texture.h"
#include "UnrealCore/UPM_Mediator.h"
#include "UnrealCore/UPM_Widget.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"


UMVC_Facade* UFlib_UPM::CreateFacade(UObject* worldContext, TSubclassOf<UMVC_Facade> facadeClass)
{
	if (facadeClass && worldContext)
	{
		
		UMVC_Facade* facade = NewObject<UMVC_Facade>(worldContext, facadeClass);
		facade->InitializeFacade(worldContext);
		
		return facade;
		
	}
	return nullptr;
}

UMVC_Proxy* UFlib_UPM::CreateProxy(UMVC_Facade* facade, TSubclassOf<UMVC_Proxy> proxyClass, const FString& specialName)
{
	if (proxyClass && facade)
	{
		UMVC_Proxy* p = NewObject<UMVC_Proxy>(facade->WorldContext, proxyClass);
		p->SetInfo(specialName.IsEmpty()? proxyClass->GetName() : specialName);
		p->SetWorldContext(facade->WorldContext);
		facade->RegisterProxy(p);
		return p;
	}
	return nullptr;
}

UMVC_Mediator* UFlib_UPM::CreateMediator(UMVC_Facade* facade, TSubclassOf<UMVC_Mediator> mediatorClass, UObject* Instance, const FString& specialName)
{
	if (mediatorClass && Instance && facade)
	{
		UMVC_Mediator* m = NewObject<UMVC_Mediator>(facade->WorldContext, mediatorClass);
		m->Init(specialName.IsEmpty() ? mediatorClass->GetName() : specialName, Instance);
		m->SetWorldContext(facade->WorldContext);
		facade->RegisterMediator(m);
		return m;
	}
	return nullptr;
}

UMVC_Command* UFlib_UPM::CreateCommand(UMVC_Facade* facade, TSubclassOf<UMVC_Command> commandClass)
{
	if (commandClass && facade)
	{
		UMVC_Command* m = NewObject<UMVC_Command>(facade->WorldContext, commandClass);
		m->SetWorldContext(facade->WorldContext);
		facade->RegisterCommand(m);
		return m;
	}
	return nullptr;
}

UUserWidget* UFlib_UPM::CreateWidgetObject(UMVC_Facade* facade, TSubclassOf<UUserWidget> umgClass, TSubclassOf<UMVC_Mediator> mediatorClass, const FString& specialName)
{
	if (umgClass && facade && mediatorClass)
	{
		UUserWidget* w = NewObject<UUserWidget>(facade->WorldContext, umgClass);
		CreateMediator(facade, mediatorClass, w, specialName);
		//facade->RegisterMediator(m);
	
		return w;
	}
	return nullptr;
}


FString UFlib_UPM::GetProxyClassName(TSubclassOf<UMVC_Proxy> proxyClass)
{

	return proxyClass ? proxyClass->GetName() : TEXT("");
}

FString UFlib_UPM::GetMediatorClassName(TSubclassOf<UMVC_Mediator> mediatorClass)
{
	return mediatorClass ? mediatorClass->GetName(): TEXT("");
}

FString UFlib_UPM::GetCommandClassName(TSubclassOf<UMVC_Command> commandrClass)
{
	return commandrClass ? commandrClass->GetName() : TEXT("");
}

TArray<FAssetData> UFlib_UPM::FindAllClass(UObject* worldContext, FName Type)
{
	TArray<UClass*> classList;
	TArray<FAssetData> arrayAssetData;
	FAssetRegistryModule& assetRegistryModule = FModuleManager::GetModuleChecked<FAssetRegistryModule>("AssetRegistry");
	FARFilter filter;
	filter.PackagePaths.Add("/Game");
	filter.ClassNames.Add(Type);
	
	//filter.ClassNames.Add(UStaticMesh::StaticClass()->GetFName());
	filter.bRecursivePaths = true;
	filter.bRecursiveClasses = true;
	assetRegistryModule.Get().GetAssets(filter, arrayAssetData);


	for (int index = 0; index < arrayAssetData.Num(); ++index)
	{
		UE_LOG(LogTemp, Warning, TEXT("asset name is %s"), *arrayAssetData[index].GetFullName());
		/*	FName  className = arrayAssetData[index].AssetClass;
			FName path = arrayAssetData[index].PackageName;
			UObject* obj = LoadObject<UObject>(worldContext, *(path.ToString()));
			if (obj)
			{
				classList.Add(obj->GetClass());
			}*/
		
	}

	return arrayAssetData;
}

