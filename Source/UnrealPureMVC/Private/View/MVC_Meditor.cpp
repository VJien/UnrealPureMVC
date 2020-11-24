// Fill out your copyright notice in the Description page of Project Settings.


#include "View/MVC_Meditor.h"
#include "../Define/UPMDefine.h"
#include "Kismet/KismetSystemLibrary.h"

void UMVC_Meditor::Init_Implementation(const FString& mediatorName, UObject* viewInstance)
{
	MediatorName = mediatorName;
	ViewInstance = viewInstance;
	UE_LOG(UPM, Log, TEXT("Meditor [%s, %s] Init "), *mediatorName,viewInstance?*(UKismetSystemLibrary::GetDisplayName(viewInstance)):TEXT(" NONE "));
}

void UMVC_Meditor::OnRegister_Implementation()
{
	UE_LOG(UPM, Log, TEXT("Meditor [%s] Register "), *(UKismetSystemLibrary::GetDisplayName(this)));
}

void UMVC_Meditor::OnRemove_Implementation()
{
	UE_LOG(UPM, Log, TEXT("Meditor [%s] Remove "), *(UKismetSystemLibrary::GetDisplayName(this)));
}

TArray<FString> UMVC_Meditor::ListNotificationInterests_Implementation() const
{
	return TArray<FString>();
}

void UMVC_Meditor::HandleNotification_Implementation(UMVC_Notification* notification)
{

}

UMVC_Proxy* UMVC_Meditor::RetrieveProxy(const FString& ProxyName)
{

	return nullptr;
}
