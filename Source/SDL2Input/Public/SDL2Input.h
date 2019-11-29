// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "IInputDeviceModule.h"
#include "IInputDevice.h"

#include "SDL2InputLibrary/include/SDL.h"

class ISDL2Input : public IInputDevice
{
public:
	ISDL2Input(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler);
	virtual ~ISDL2Input();

	virtual void SetMessageHandler(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler){ m_MessageHandler = InMessageHandler; }
	
	virtual void Tick(float DeltaTime) override{}
	virtual void SendControllerEvents() override;
	virtual void SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value) override {}
	virtual void SetChannelValues(int32 ControllerId, const FForceFeedbackValues& Values) override {}
	virtual bool Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) override { return false; }

protected:

	/** Delegate to allow for manual parsing of HID data. */
	//FRawInputDataDelegate DataReceivedHandler;

	/** Handler to send all messages to. */
	TSharedRef<FGenericApplicationMessageHandler> m_MessageHandler;

private:
	TArray<SDL_Joystick *> m_Joysticks;
};

class FSDL2InputModule : public IInputDeviceModule
{
	virtual TSharedPtr< class IInputDevice > CreateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) override;
	
	TSharedPtr<class ISDL2Input> m_pSDL2InputDevice;
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	/** Handle to the test dll we will load */
	void *m_pSDLHandle;
};
