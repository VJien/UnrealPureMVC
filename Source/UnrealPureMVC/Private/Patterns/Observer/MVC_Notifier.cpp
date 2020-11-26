// Fill out your copyright notice in the Description page of Project Settings.


#include "Patterns/Observer/MVC_Notifier.h"

void UMVC_Notifier::SendNotification_Implementation(const FString& NotificationName, UObject* body /*= nullptr*/)
{
	if (Facade)
	{
		Facade->SendNotification(NotificationName, body);
	}
}

void UMVC_Notifier::SetFacade(UMVC_Facade* facade)
{
	Facade = facade;

}

void UMVC_Notifier::SetWorldContext(UObject* worldContext)
{
	WorldContext = worldContext;
}
