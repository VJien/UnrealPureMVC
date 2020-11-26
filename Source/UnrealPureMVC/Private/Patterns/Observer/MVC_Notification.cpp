// Fill out your copyright notice in the Description page of Project Settings.


#include "Patterns/Observer/MVC_Notification.h"

void UMVC_Notification::SetInfo(const FString& name, UObject* body /*= nullptr*/)
{
	Body = body;
	Name = name;
}

FString UMVC_Notification::GetName_Implementation() const
{
	return Name;
}

UObject* UMVC_Notification::GetBody_Implementation() const
{
	return Body;
}

FString UMVC_Notification::ToString_Implementation() const
{
	FString msg = TEXT("Notification Name: ") + Name;
	msg += TEXT("\n Body: ") + (Body == nullptr ? TEXT("null") : Body->GetName());

	return msg;
}
