// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealCore/UPM_Widget.h"
#include "./Define/UPMDefine.h"
#include "Patterns/Facade/MVC_Facade.h"

UUPM_Widget::UUPM_Widget(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{
}

UUPM_Mediator* UUPM_Widget::GetOwnMediator_Implementation() const
{
	return ownMediator;
}

void UUPM_Widget::RegisterUPMObject_Implementation(UMVC_Facade* facade)
{
	if (facade )
	{
		ownMediator = NewObject<UUPM_Mediator>();
			// CreateDefaultSubobject<UUPM_Mediator>(TEXT("UPM_Mediator"));
		ownMediator->Init(CustomName.IsEmpty()?this->GetName():CustomName, this);
		ownMediator->SetWorldContext(this);
		ownMediator->OnRemoved.AddDynamic(this, &UUPM_Widget::OnRemove);
		ownMediator->OnRegistered.AddDynamic(this, &UUPM_Widget::OnRegister);
		ownMediator->OnHandleNotification.AddDynamic(this, &UUPM_Widget::HandleNotification);
		ownMediator->NotificationInterests = Execute_ListNotificationInterests(this);
		facade->RegisterMediator(ownMediator);
		return;
	}
	UE_LOG(UPM, Warning, TEXT("UPM Object Register Failed!! "));
}

UMVC_Facade* UUPM_Widget::GetOwnFacade_Implementation() const
{
	if (ownMediator)
	{
		return ownMediator->GetFacade();
	}
	return nullptr;
}

UMVC_Proxy* UUPM_Widget::RetrieveProxy_Implementation(const FString& ProxyName)
{
	if (ownMediator)
	{
		return ownMediator->RetrieveProxy(ProxyName);
	}
	return nullptr;
}

FString UUPM_Widget::GetOwnMeditorName_Implementation() const
{
	return ownMediator ? ownMediator->GetMeditorName() : this->GetName();
}

TArray<FString> UUPM_Widget::ListNotificationInterests_Implementation() const
{
	return TArray<FString>();
}

void UUPM_Widget::SendNotification_Implementation(const FString& notification, UObject* body)
{
	if (ownMediator)
	{
		ownMediator->SendNotification(notification, body);
	}
}

void UUPM_Widget::HandleNotification_Implementation(UMVC_Notification* notification)
{

}

void UUPM_Widget::OnRemove_Implementation()
{

}

void UUPM_Widget::OnRegister_Implementation()
{

}

void UUPM_Widget::InitWidget_Implementation()
{
	
}

