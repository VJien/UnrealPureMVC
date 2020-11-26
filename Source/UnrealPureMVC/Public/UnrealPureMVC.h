// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Patterns/Facade/MVC_Facade.h"

class UMVC_Facade;

class FUnrealPureMVCModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;


public:
	/*UFUNCTION()
		UMVC_Facade* GetFacade()const;

	UFUNCTION()
		UMVC_Facade*  CreateFacade(UObject* WorldContext, TSubclassOf<UMVC_Facade> facadeClass);




	UPROPERTY()
		UMVC_Facade* Facade;*/
};
