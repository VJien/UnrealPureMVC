// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealCore/UPM_Actor.h"
#include "./Define/UPMDefine.h"
#include "Lib/Flib_UPM.h"
#include "UObject/UObjectGlobals.h"
#include "UnrealCore/UPM_Mediator.h"

// Sets default values
AUPM_Actor::AUPM_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//ownMediator = Cast<UUPM_Mediator>(UFlib_UPM::CreateMediator(this, UUPM_Mediator::StaticClass(), this, TEXT("")));
	ownMediator = CreateDefaultSubobject<UUPM_Mediator>(TEXT("UPM_Mediator"));
	ownMediator->Init(TEXT(""), this);
	ownMediator->SetWorldContext(this);
	ownMediator->OnRemoved.AddDynamic(this, &AUPM_Actor::OnRemove);
	ownMediator->OnRegistered.AddDynamic(this, &AUPM_Actor::OnRegister);
	ownMediator->OnHandleNotification.AddDynamic(this, &AUPM_Actor::HandleNotification);
	ownMediator->NotificationInterests = Execute_ListNotificationInterests(this);
}

// Called when the game starts or when spawned
void AUPM_Actor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUPM_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UUPM_Mediator* AUPM_Actor::GetOwnMediator_Implementation() const
{
	return ownMediator;
}

void AUPM_Actor::RegisterUPMObject_Implementation(UMVC_Facade* facade)
{
	if (facade)
	{
		facade->RegisterMediator(ownMediator);
		return;
	}
	UE_LOG(UPM, Warning, TEXT("UPM Object Register Failed!! [ No facade]")); 
}

UMVC_Facade* AUPM_Actor::GetOwnFacade_Implementation() const
{
	if (ownMediator)
	{
		return ownMediator->GetFacade();
	}
	return nullptr;
}

UMVC_Proxy* AUPM_Actor::RetrieveProxy_Implementation(const FString& ProxyName)
{
	if (ownMediator)
	{
		return ownMediator->RetrieveProxy(ProxyName);
	}
	return nullptr;
}

FString AUPM_Actor::GetOwnMeditorName_Implementation() const
{
	return ownMediator ? ownMediator->GetMeditorName():this->GetName();
}

TArray<FString> AUPM_Actor::ListNotificationInterests_Implementation() const
{
	return TArray<FString>();
}

void AUPM_Actor::SendNotification_Implementation(const FString& notification, UObject* body)
{
	if (ownMediator)
	{
		ownMediator->SendNotification(notification, body);
	}
}

void AUPM_Actor::HandleNotification_Implementation(UMVC_Notification* notification)
{

}

void AUPM_Actor::OnRemove_Implementation()
{

}

void AUPM_Actor::OnRegister_Implementation()
{

}

