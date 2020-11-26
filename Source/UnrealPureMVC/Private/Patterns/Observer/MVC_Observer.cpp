// Fill out your copyright notice in the Description page of Project Settings.


#include "Patterns/Observer/MVC_Observer.h"
#include "Patterns/Observer/MVC_Notification.h"

void UMVC_Observer::SetInfo(UObject* notifyObject, TFunction<void(UMVC_Notification*)> CallBackFunc)
{
	NotifyObject = notifyObject;
	NotifyCallBackFunc = CallBackFunc;
}

void UMVC_Observer::NotifyObserver(UMVC_Notification* Notification)
{
	NotifyCallBackFunc(Notification);
}

bool UMVC_Observer::CompareNofityObject(UObject* obj)
{
	return NotifyObject == obj;
}
