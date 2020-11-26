// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UnrealPureMVC.h"
#include "Patterns/Facade/MVC_Facade.h"
#include "./Define/UPMDefine.h"

#define LOCTEXT_NAMESPACE "FUnrealPureMVCModule"

void FUnrealPureMVCModule::StartupModule()
{
	
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FUnrealPureMVCModule::ShutdownModule()
{
	
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}


//
//UMVC_Facade* FUnrealPureMVCModule::GetFacade() const
//{
//
//	return Facade;
//}
//
//UMVC_Facade*  FUnrealPureMVCModule::CreateFacade(UObject* WorldContext, TSubclassOf<UMVC_Facade> facadeClass)
//{
//	if (!Facade)
//	{
//		Facade = NewObject<UMVC_Facade>(WorldContext, facadeClass);
//		return Facade;
//	}
//	else
//	{
//		UE_LOG(UPM, Warning, TEXT("Has a Facade! Create Failed!!!"));
//		return Facade;
//	}
//	return nullptr;
//}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUnrealPureMVCModule, UnrealPureMVC)