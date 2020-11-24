// Fill out your copyright notice in the Description page of Project Settings.


#include "Model/MVC_Proxy.h"
#include "../Define/UPMDefine.h"
#include "Kismet/KismetSystemLibrary.h"



void UMVC_Proxy::SetProxyName_Implementation(const FString& Name)
{
	ProxyName = Name;
}

void UMVC_Proxy::OnRegister_Implementation()
{
	UE_LOG(UPM, Log, TEXT("Proxy  [%s] Register "), *(UKismetSystemLibrary::GetDisplayName(this)));
}

void UMVC_Proxy::OnRemove_Implementation()
{
	
	UE_LOG(UPM, Log, TEXT("Proxy  [%s] Remove "), *(UKismetSystemLibrary::GetDisplayName(this)));
}

FString UMVC_Proxy::GetProxyName_Implementation() const
{
	return ProxyName;
}

void UMVC_Proxy::SetData_Implementation(UObject* Data)
{
	ProxyData = Data;
}

UObject* UMVC_Proxy::GetProxyData_Implementation() const
{
	return ProxyData;
}
