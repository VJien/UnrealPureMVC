// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Flib_UPMEx.generated.h"

class UUPM_Widget;
class UMVC_Facade;

/**
 * 
 */
UCLASS()
class UNREALPUREMVC_API UFlib_UPMEx : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "UnrealPureMVC", meta = (WorldContext = "worldContext", CallableWithoutWorldContext))
		static UUPM_Widget* CreateUPMWidget(UMVC_Facade* facade, TSubclassOf<UUPM_Widget> umgClass, const FString& specialName);
};
