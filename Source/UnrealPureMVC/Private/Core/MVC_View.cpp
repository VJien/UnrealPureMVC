// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/MVC_View.h"
#include "Patterns/Mediator/MVC_Meditor.h"
#include "Patterns/Observer/MVC_Notification.h"

UMVC_View::UMVC_View(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	EmptyMediator = NewObject<UMVC_Mediator>();
}


void UMVC_View::RegisterObserver(const FString& NotificationName, UMVC_Observer* observer)
{
	if (!ObserverMap.Contains(NotificationName))
	{
		ObserverMap.Add(NotificationName, FObserverArray2());
	}
	ObserverMap[NotificationName].Observers.Add(observer);
}

void UMVC_View::RemoveObserver(const FString& NotificationName, UObject* notifyObject)
{
	if (ObserverMap.Contains(NotificationName))
	{
		for (int i = 0 ;i< ObserverMap[NotificationName].Observers.Num(); i++ )
		{
			if (ObserverMap[NotificationName].Observers[i]->CompareNofityObject(notifyObject))
			{
				ObserverMap[NotificationName].Observers.RemoveAt(i);
				break;
			}
		}

		if (ObserverMap[NotificationName].Observers.Num() == 0)
			ObserverMap.Remove(NotificationName);
	}
}

void UMVC_View::NotifyObservers(UMVC_Notification* noitifyCation)
{
	FString name = noitifyCation->GetName();
	if (ObserverMap.Contains(name))
	{
		for (auto cur : ObserverMap[name].Observers)
		{
			cur->NotifyObserver(noitifyCation);
		}
	}
}

void UMVC_View::RegisterMeditor(UMVC_Mediator* mediator)
{
	if (!mediator || MediatorMap.Contains(mediator->GetMeditorName()))
		return;
	MediatorMap.Add(mediator->GetMeditorName(), mediator);
	TArray<FString> notifs = mediator->ListNotificationInterests();
	if (notifs.Num() > 0)
	{
		UMVC_Observer* obs = NewObject<UMVC_Observer>();
		obs->SetInfo(mediator, [mediator](UMVC_Notification* notification) {
			mediator->HandleNotification(notification);
		});

		for (auto cur : notifs)
		{
			RegisterObserver(cur, obs);
		}
	}
	mediator->OnRegister();

}

UMVC_Mediator* UMVC_View::RetrieveMediator(const FString& mediatorName) const
{
	return MediatorMap.Contains(mediatorName) ? MediatorMap[mediatorName] : EmptyMediator;
}

bool UMVC_View::RemoveMediator(const FString& mediatorName)
{
	if (MediatorMap.Contains(mediatorName))
	{
		UMVC_Mediator* cur = MediatorMap[mediatorName];
		MediatorMap.Remove(mediatorName);

		cur->OnRemove();
		return true;
	}
	return false;
}

bool UMVC_View::HasMediator(const FString& mediatorName)
{
	return MediatorMap.Contains(mediatorName);
}
