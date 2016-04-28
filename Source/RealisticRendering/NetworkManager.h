// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "NetworkManager.generated.h"

/**
 *
 */
UCLASS()
class REALISTICRENDERING_API UNetworkManager : public UObject
{
	GENERATED_BODY()

private:
	FSocket* Listener; // TODO: Replace with intelligent pointer here.
	FSocket* ConnectionSocket;
	FTimerManager* WorldTimerManager;
	bool bIsConnected;
	uint32 PortNum = 9000;

public:
	UWorld* World;
	UNetworkManager();
	void SendMessage(FString Message);
	void ListenSocket();
	void WaitConnection();
	void WaitData();
	FString StringFromBinaryArray(const TArray<uint8>& BinaryArray);
	~UNetworkManager();

};
