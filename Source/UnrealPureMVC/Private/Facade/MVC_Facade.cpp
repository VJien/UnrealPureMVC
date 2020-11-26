// Fill out your copyright notice in the Description page of Project Settings.


#include "Facade/MVC_Facade.h"
#include "View/MVC_View.h"
#include "Model/MVC_Model.h"
#include "Controller/MVC_Controller.h"
#include "Define/UPMDefine.h"
#include "Observer/MVC_Notification.h"
#include "View/MVC_Meditor.h"
#include "Controller/MVC_Command.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Model/MVC_Proxy.h"






void UMVC_Facade::InitializeFacade_Implementation(UObject* Context)
{
	if (bIsInit)
	{
		UE_LOG(UPM, Warning, TEXT("Already  initialized!!"));
		return;
	}
	bIsInit = true;
	View = NewObject<UMVC_View>();
	Model = NewObject<UMVC_Model>();
	Controller = NewObject<UMVC_Controller>();
	Controller->Init(View);		//controller need view
	WorldContext = Context;
	
	InitializeProxyImpl(Context);
	InitializeCommandImpl(Context);
	InitializeMeditorImpl(Context);

	UE_LOG(UPM, Log, TEXT("Facade Initializer!!"));
}

void UMVC_Facade::RegisterProxy(UMVC_Proxy* proxy)
{
	if (!Model || !proxy)
	{
		UE_LOG(UPM, Log, TEXT("RegisterProxy Failed"));
		return ;
	}
	proxy->SetFacade(this);
	Model->RegisterProxy(proxy);

}

UMVC_Proxy* UMVC_Facade::RetrieveProxy(const FString& ProxyName) const
{
	if (!Model)
	{
		UE_LOG(UPM, Log, TEXT("No Model!!"));
		return nullptr;
	}
	return Model->RetrieveProxy(ProxyName);
}

bool UMVC_Facade::RemoveProxy(const FString& ProxyName)
{
	if (!Model)
	{
		UE_LOG(UPM, Log, TEXT("No Model!!"));
		return false;
	}

	return Model->RemoveProxy(ProxyName);
}

bool UMVC_Facade::HasProxy(const FString& ProxyName)
{
	if (!Model)
	{
		UE_LOG(UPM, Log, TEXT("No Model!!"));
		return false;
	}
	return Model->HasProxy(ProxyName);
}

void UMVC_Facade::RegisterMediator(UMVC_Mediator* Mediator)
{
	if (!Mediator || !View)
	{
		UE_LOG(UPM, Log, TEXT("RegisterMediator Failed"));
		return;
	}
	Mediator->SetFacade(this);
	View->RegisterMeditor(Mediator);
}

UMVC_Mediator* UMVC_Facade::RetrieveMediator(const FString& MediatorName)const
{
	return View->RetrieveMediator(MediatorName);
}

bool UMVC_Facade::RemoveMediator(const FString& MediatorName)
{
	return View->RemoveMediator(MediatorName);
}

bool UMVC_Facade::HasMeiator(const FString& MediatorName)
{
	return View->HasMediator(MediatorName);
}

void UMVC_Facade::RegisterCommand(UMVC_Command* command)
{
	if (!command || !Controller)
	{
		UE_LOG(UPM, Log, TEXT("RegisterMediator Failed"));
		return;
	}
	command->SetFacade(this);
	Controller->RegisterCommand(command->GetName(), command);
}

UMVC_Command* UMVC_Facade::RetrieveCommand(const FString& NotificationName)const
{
	return Controller->RetrieveCommand(NotificationName);
}

bool UMVC_Facade::RemoveCommand(const FString& NotificationName)
{
	return Controller->RemoveCommand(NotificationName);
}

bool UMVC_Facade::HasCommand(const FString& NotificationName)
{
	return Controller->HasCommand(NotificationName);
}

void UMVC_Facade::SendNotification(const FString& NotificationName, UObject* body /*= nullptr*/)
{
	UE_LOG(UPM, Log, TEXT("SendNotification [NotificationName = [%s], Body = [%s]]"),*NotificationName, body?*(UKismetSystemLibrary::GetDisplayName(body)):TEXT("NONE"));
	UMVC_Notification* noti = NewObject<UMVC_Notification>();
	noti->SetInfo(NotificationName, body);
	View->NotifyObservers(noti);
}

UMVC_View* UMVC_Facade::GetView() const
{
	return View;
}
