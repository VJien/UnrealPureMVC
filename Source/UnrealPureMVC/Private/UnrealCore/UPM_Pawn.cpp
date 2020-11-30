// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealCore/UPM_Pawn.h"
#include "./Define/UPMDefine.h"

// Sets default values
AUPM_Pawn::AUPM_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ownMediator = CreateDefaultSubobject<UUPM_Mediator>(TEXT("UPM_Mediator"));
	ownMediator->Init(TEXT(""), this);
	ownMediator->SetWorldContext(this);
	ownMediator->OnRemoved.AddDynamic(this, &AUPM_Pawn::OnRemove);
	ownMediator->OnRegistered.AddDynamic(this, &AUPM_Pawn::OnRegister);
	ownMediator->OnHandleNotification.AddDynamic(this, &AUPM_Pawn::HandleNotification);
	ownMediator->NotificationInterests = Execute_ListNotificationInterests(this);
}

// Called when the game starts or when spawned
void AUPM_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUPM_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUPM_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UUPM_Mediator* AUPM_Pawn::GetOwnMediator_Implementation() const
{
	return ownMediator;
}

void AUPM_Pawn::RegisterUPMObject_Implementation(UMVC_Facade* facade)
{
	if (facade)
	{
		facade->RegisterMediator(ownMediator);
		return;
	}
	UE_LOG(UPM, Warning, TEXT("UPM Object Register Failed!! [ No facade]"));
}

UMVC_Facade* AUPM_Pawn::GetOwnFacade_Implementation() const
{
	if (ownMediator)
	{
		return ownMediator->GetFacade();
	}
	return nullptr;
}

UMVC_Proxy* AUPM_Pawn::RetrieveProxy_Implementation(const FString& ProxyName)
{
	if (ownMediator)
	{
		return ownMediator->RetrieveProxy(ProxyName);
	}
	return nullptr;
}

FString AUPM_Pawn::GetOwnMeditorName_Implementation() const
{
	return ownMediator ? ownMediator->GetMeditorName() : this->GetName();
}

TArray<FString> AUPM_Pawn::ListNotificationInterests_Implementation() const
{
	return TArray<FString>();
}

void AUPM_Pawn::SendNotification_Implementation(const FString& notification, UObject* body)
{
	if (ownMediator)
	{
		ownMediator->SendNotification(notification, body);
	}
}

void AUPM_Pawn::HandleNotification_Implementation(UMVC_Notification* notification)
{

}

void AUPM_Pawn::OnRemove_Implementation()
{

}

void AUPM_Pawn::OnRegister_Implementation()
{

}
