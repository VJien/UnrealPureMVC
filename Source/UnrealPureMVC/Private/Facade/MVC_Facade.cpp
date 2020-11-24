// Fill out your copyright notice in the Description page of Project Settings.


#include "Facade/MVC_Facade.h"
#include "View/MVC_View.h"
#include "Model/MVC_Model.h"
#include "Controller/MVC_Controller.h"
#include "../Define/UPMDefine.h"
#include "Observer/MVC_Notification.h"






void UMVC_Facade::InitializeFacade_Implementation(UObject* Context)
{
	View = NewObject<UMVC_View>();
	Model = NewObject<UMVC_Model>();
	Controller = NewObject<UMVC_Controller>();

	InitializeMeditorImpl(Context);
	InitializeProxyImpl(Context);
	InitializeCommandImpl(Context);


	UE_LOG(UPM, Log, TEXT("Facade Initializer!!"));
}

void UMVC_Facade::RegisterProxy(UMVC_Proxy* proxy)
{
	if (!Model)
	{
		UE_LOG(UPM, Log, TEXT("No Model!!"));
		return ;
	}
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

void UMVC_Facade::SendNotification(const FString& NotificationName, UObject* body /*= nullptr*/)
{
	UMVC_Notification* noti = NewObject<UMVC_Notification>();
	noti->SetInfo(NotificationName, body);

}
