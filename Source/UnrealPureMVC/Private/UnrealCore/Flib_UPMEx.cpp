// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealCore/Flib_UPMEx.h"
#include "Patterns/Facade/MVC_Facade.h"
#include "UnrealCore/UPM_Widget.h"

UUPM_Widget* UFlib_UPMEx::CreateUPMWidget(UMVC_Facade* facade, TSubclassOf<UUPM_Widget> umgClass, const FString& specialName)
{
	if (umgClass && facade)
	{
		UUPM_Widget* w = NewObject<UUPM_Widget>(facade->WorldContext, umgClass);
		w->CustomName = specialName;
		w->Execute_RegisterUPMObject(w, facade);
		return w;
	}
	return nullptr;
}
