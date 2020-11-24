// Fill out your copyright notice in the Description page of Project Settings.


#include "Observer/MVC_Notifier.h"

void UMVC_Notifier::SendNotification_Implementation(const FString& NotificationName, UObject* body /*= nullptr*/)
{
	if (Facade)
	{
		Facade->SendNotification(NotificationName, body);
	}
}

void UMVC_Notifier::SetFacade_Implementation(UMVC_Facade* facade)
{
	Facade = facade;
}
