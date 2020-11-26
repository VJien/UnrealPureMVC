// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MVC_Observer.generated.h"

class UMVC_Notification;

/**
 * 
 */
UCLASS()
class UNREALPUREMVC_API UMVC_Observer : public UObject
{
	GENERATED_BODY()
public:
	void SetInfo(UObject* notifyObject, TFunction<void(UMVC_Notification*)> CallBackFunc);

	void NotifyObserver(UMVC_Notification* Notification);

	bool CompareNofityObject(UObject* obj);


protected:
	TFunction<void(UMVC_Notification*)> NotifyCallBackFunc;

	UPROPERTY()
		UObject* NotifyObject;
};
