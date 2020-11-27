// Fill out your copyright notice in the Description page of Project Settings.


#include "Lib/Flib_UPM.h"
#include "UnrealPureMVC.h"
#include "Modules/ModuleManager.h"

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

UMVC_Proxy* UFlib_UPM::CreateProxy(UObject* worldContext, TSubclassOf<UMVC_Proxy> proxyClass, const FString& specialName)
{
	if (proxyClass)
	{
		UMVC_Proxy* p = NewObject<UMVC_Proxy>(worldContext, proxyClass);
		p->SetInfo(specialName.IsEmpty()? proxyClass->GetName() : specialName);
		p->SetWorldContext(worldContext);
		return p;
	}
	return nullptr;
}

UMVC_Mediator* UFlib_UPM::CreateMediator(UObject* worldContext, TSubclassOf<UMVC_Mediator> mediatorClass, UObject* Instance, const FString& specialName)
{
	if (mediatorClass && Instance)
	{
		UMVC_Mediator* m = NewObject<UMVC_Mediator>(worldContext, mediatorClass);
		m->Init(specialName.IsEmpty() ? mediatorClass->GetName() : specialName, Instance);
		m->SetWorldContext(worldContext);
		return m;
	}
	return nullptr;
}

UMVC_Command* UFlib_UPM::CreateCommand(UObject* worldContext, TSubclassOf<UMVC_Command> commandClass)
{
	if (commandClass)
	{
		UMVC_Command* m = NewObject<UMVC_Command>(worldContext, commandClass);
		m->SetWorldContext(worldContext);
		return m;
	}
	return nullptr;
}

UUserWidget* UFlib_UPM::CreateWidgetObject(UObject* worldContext, TSubclassOf<UUserWidget> umgClass)
{
	if (umgClass)
	{
		UUserWidget* m = NewObject<UUserWidget>(worldContext, umgClass);
		return m;
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
