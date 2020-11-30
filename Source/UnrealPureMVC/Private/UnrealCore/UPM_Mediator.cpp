// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealCore/UPM_Mediator.h"

void UUPM_Mediator::OnRemove_Implementation()
{
	Super::OnRemove_Implementation();
	OnRemoved.Broadcast();
}

TArray<FString> UUPM_Mediator::ListNotificationInterests_Implementation() const
{
	return NotificationInterests;
}

void UUPM_Mediator::SendNotification_Implementation(const FString& notification, UObject* body)
{
	Super::SendNotification_Implementation(notification, body);

	OnSendNotification.Broadcast(notification, body);
}

void UUPM_Mediator::HandleNotification_Implementation(UMVC_Notification* notification)
{
	Super::HandleNotification_Implementation(notification);
	OnHandleNotification.Broadcast(notification);
}

void UUPM_Mediator::OnRegister_Implementation()
{
	Super::OnRegister_Implementation();
	OnRegistered.Broadcast();
}
