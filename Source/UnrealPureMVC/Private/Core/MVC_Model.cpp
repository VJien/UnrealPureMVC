// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/MVC_Model.h"
#include "./Define/UPMDefine.h"
#include "Patterns/Proxy/MVC_Proxy.h"



UMVC_Model::UMVC_Model(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	DefaultProxy = NewObject<UMVC_Proxy>();
}


void UMVC_Model::RegisterProxy_Implementation(UMVC_Proxy* Proxy)
{
	if (Proxy )
	{
		if (!ProxyMap.Contains(Proxy->GetProxyName()))
		{
			ProxyMap.Add(Proxy->GetProxyName(), Proxy);
			UE_LOG(UPM, Log, TEXT("Register Proxy : %s"), *(Proxy->GetProxyName()));
			Proxy->OnRegister();
		}
	}
}

UMVC_Proxy* UMVC_Model::RetrieveProxy_Implementation(const FString& ProxyName) const
{
	return ProxyMap.Contains(ProxyName) ? ProxyMap[ProxyName] : DefaultProxy;
}

bool UMVC_Model::RemoveProxy_Implementation(const FString& ProxyName)
{
	if (ProxyMap.Num()>0)
	{
		if (ProxyMap.Contains(ProxyName))
		{
			UMVC_Proxy* cur = ProxyMap[ProxyName];
			ProxyMap.Remove(ProxyName);
			cur->OnRemove();
			UE_LOG(UPM, Log, TEXT("Remove Proxy : %s"), *ProxyName);
			return true;
		}
	}
	UE_LOG(UPM, Log, TEXT("Remove Proxy Failed!( %s )"), *ProxyName);
	return false;
}

bool UMVC_Model::HasProxy_Implementation(const FString& ProxyName) const
{
	return ProxyMap.Contains(ProxyName);
}
