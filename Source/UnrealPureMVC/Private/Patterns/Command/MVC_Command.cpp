// Fill out your copyright notice in the Description page of Project Settings.


#include "Patterns/Command/MVC_Command.h"
#include "Define/UPMDefine.h"
#include "Patterns/Mediator/MVC_Meditor.h"
#include "Patterns/Facade/MVC_Facade.h"
#include "Patterns/Observer/MVC_Notification.h"

void UMVC_Command::Execute_Implementation(UMVC_Notification* notification)
{
	UE_LOG(UPM, Log, TEXT("Execute Command [%s]"), *(notification->GetName()));
}

UMVC_Proxy* UMVC_Command::RetrieveProxy_Implementation(const FString& proxyName) const
{
	return Facade->RetrieveProxy(proxyName);
}

UMVC_Mediator* UMVC_Command::RetrieveMediator_Implementation(const FString& mediatorName) const
{
	return Facade->RetrieveMediator(mediatorName); 
}

FString UMVC_Command::GetName_Implementation() const
{
	return Name;
}

void UMVC_Command::SetInfo_Implementation(const FString& commandName)
{
	Name = commandName;
}
