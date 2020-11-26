// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/MVC_Controller.h"
#include "Controller/MVC_Command.h"
#include "View/MVC_View.h"
#include "Observer/MVC_Observer.h"
#include "Observer/MVC_Notification.h"

UMVC_Controller::UMVC_Controller(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	EmptyCommand = NewObject<UMVC_Command>();
}

void UMVC_Controller::Init_Implementation(UMVC_View* view)
{
	View = view;
}

void UMVC_Controller::RegisterCommand_Implementation(const FString& notificationName, UMVC_Command* command)
{
	if (CommandMap.Contains(notificationName))
		return;
	CommandMap.Add(notificationName, command);
	UMVC_Observer* obs = NewObject<UMVC_Observer>();
	obs->SetInfo(this, [this](UMVC_Notification* notification)
	{
		ExecuteCommand(notification);
	});
	View->RegisterObserver(notificationName, obs);

}

UMVC_Command* UMVC_Controller::RetrieveCommand_Implementation(const FString& notificationName)
{
	return CommandMap.Contains(notificationName) ? CommandMap[notificationName] : EmptyCommand;
}

void UMVC_Controller::ExecuteCommand_Implementation(UMVC_Notification* notification)
{
	if (CommandMap.Contains(notification->GetName()))
	{
		CommandMap[notification->GetName()]->Execute(notification);
	}
}

bool UMVC_Controller::RemoveCommand_Implementation(const FString& noitificationName)
{
	if (CommandMap.Contains(noitificationName))
	{
		CommandMap.Remove(noitificationName);
		View->RemoveObserver(noitificationName, this);
		return true;
	}
	return false;
}

bool UMVC_Controller::HasCommand_Implementation(const FString& notificationName) const
{
	return CommandMap.Contains(notificationName);
}
