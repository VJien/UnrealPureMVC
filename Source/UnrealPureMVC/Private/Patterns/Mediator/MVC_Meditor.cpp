// Fill out your copyright notice in the Description page of Project Settings.


#include "Patterns/Mediator/MVC_Meditor.h"
#include "Define/UPMDefine.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Patterns/Observer/MVC_Notifier.h"

void UMVC_Mediator::Init_Implementation(const FString& mediatorName, UObject* viewInstance)
{
	MediatorName = mediatorName;
	ViewInstance = viewInstance;
	UE_LOG(UPM, Log, TEXT("Meditor [%s, %s] Init "), *mediatorName,viewInstance?*(UKismetSystemLibrary::GetDisplayName(viewInstance)):TEXT(" NONE "));
}

void UMVC_Mediator::OnRegister_Implementation()
{
	UE_LOG(UPM, Log, TEXT("Meditor [%s] Register "), *(UKismetSystemLibrary::GetDisplayName(this)));
}

void UMVC_Mediator::OnRemove_Implementation()
{
	UE_LOG(UPM, Log, TEXT("Meditor [%s] Remove "), *(UKismetSystemLibrary::GetDisplayName(this)));
}

TArray<FString> UMVC_Mediator::ListNotificationInterests_Implementation() const
{
	return TArray<FString>();
}

void UMVC_Mediator::HandleNotification_Implementation(UMVC_Notification* notification)
{

}

UMVC_Proxy* UMVC_Mediator::RetrieveProxy(const FString& ProxyName)
{
	return Facade->RetrieveProxy(ProxyName);
}
