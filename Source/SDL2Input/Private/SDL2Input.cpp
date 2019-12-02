// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "SDL2Input.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "SDL2InputFunctionLibrary.h"

#include "IInputDeviceModule.h"
#include "IInputDevice.h"

#define LOCTEXT_NAMESPACE "FSDL2InputModule"

#pragma region ISDL2Input
//
// ISDL2Input
//
#define JOYSTICK_DEADZONE 4096
ISDL2Input::ISDL2Input(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler)
	: m_MessageHandler(InMessageHandler)
{
	SDL_InitSubSystem(SDL_INIT_JOYSTICK);

	int32 l_NumJoyStick = SDL_NumJoysticks();
	for( int32 i=0 ; i<l_NumJoyStick ; ++i )
	{
		SDL_Joystick *l_pNewJoyStick = SDL_JoystickOpen(i);
		m_Joysticks.Add(l_pNewJoyStick);
	}

	const FName NAME_SDL2Controller(TEXT("SDL2Controller"));

	EKeys::AddMenuCategoryDisplayInfo(NAME_SDL2Controller, LOCTEXT("SDL2ControllerSubCateogry", "SDL2Controller"), TEXT("GraphEditor.KeyEvent_16x"));

	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Axis[0], LOCTEXT("SDL2Controller_Axis1", "SDL2Controller Axis 1"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Axis[1], LOCTEXT("SDL2Controller_Axis2", "SDL2Controller Axis 2"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Axis[2], LOCTEXT("SDL2Controller_Axis3", "SDL2Controller Axis 3"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Axis[3], LOCTEXT("SDL2Controller_Axis4", "SDL2Controller Axis 4"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Axis[4], LOCTEXT("SDL2Controller_Axis5", "SDL2Controller Axis 5"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Axis[5], LOCTEXT("SDL2Controller_Axis6", "SDL2Controller Axis 6"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Hat[0], LOCTEXT("SDL2Controller_Hat1_X", "SDL2Controller Hat 1 Axis-X"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Hat[1], LOCTEXT("SDL2Controller_Hat1_Y", "SDL2Controller Hat 1 Axis-Y"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Ball[0], LOCTEXT("SDL2Controller_Ball1", "SDL2Controller Ball 1 X Delta"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Ball[1], LOCTEXT("SDL2Controller_Ball2", "SDL2Controller Ball 1 Y Delta"), FKeyDetails::GamepadKey, NAME_SDL2Controller));

	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Button[0], LOCTEXT("SDL2Controller_Button1", "SDL2Controller Button 1"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Button[1], LOCTEXT("SDL2Controller_Button2", "SDL2Controller Button 2"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Button[2], LOCTEXT("SDL2Controller_Button3", "SDL2Controller Button 3"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Button[3], LOCTEXT("SDL2Controller_Button4", "SDL2Controller Button 4"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Button[4], LOCTEXT("SDL2Controller_Button5", "SDL2Controller Button 5"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Button[5], LOCTEXT("SDL2Controller_Button6", "SDL2Controller Button 6"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Button[6], LOCTEXT("SDL2Controller_Button7", "SDL2Controller Button 7"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Button[7], LOCTEXT("SDL2Controller_Button8", "SDL2Controller Button 8"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Button[8], LOCTEXT("SDL2Controller_Button9", "SDL2Controller Button 9"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Button[9], LOCTEXT("SDL2Controller_Button10", "SDL2Controller Button 10"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Button[10], LOCTEXT("SDL2Controller_Button11", "SDL2Controller Button 11"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Button[11], LOCTEXT("SDL2Controller_Button12", "SDL2Controller Button 12"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Button[12], LOCTEXT("SDL2Controller_Button13", "SDL2Controller Button 13"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Button[13], LOCTEXT("SDL2Controller_Button14", "SDL2Controller Button 14"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Button[14], LOCTEXT("SDL2Controller_Button15", "SDL2Controller Button 15"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Button[15], LOCTEXT("SDL2Controller_Button16", "SDL2Controller Button 16"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Button[16], LOCTEXT("SDL2Controller_Button17", "SDL2Controller Button 17"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Button[17], LOCTEXT("SDL2Controller_Button18", "SDL2Controller Button 18"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Button[18], LOCTEXT("SDL2Controller_Button19", "SDL2Controller Button 19"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
	EKeys::AddKey(FKeyDetails(FSDL2InputKeys::SDL2Controller_Button[19], LOCTEXT("SDL2Controller_Button20", "SDL2Controller Button 20"), FKeyDetails::GamepadKey, NAME_SDL2Controller));
}

ISDL2Input::~ISDL2Input()
{
	for( int32 i=0 ; i<m_Joysticks.Num() ; ++i )
	{
		if( SDL_JoystickGetAttached(m_Joysticks[i]) ) SDL_JoystickClose(m_Joysticks[i]);
	}
	m_Joysticks.Empty();

	SDL_QuitSubSystem(SDL_INIT_JOYSTICK);
}

void ISDL2Input::SendControllerEvents()
{
	SDL_Event l_Event;
	while( SDL_PollEvent(&l_Event) )
	{
		switch( l_Event.type )
		{
			case SDL_JOYAXISMOTION:{
				int32 l_AxisIdx = l_Event.jaxis.axis;
				if( l_AxisIdx >= MAX_SDL2_AXIS ) continue;

				m_MessageHandler->OnControllerAnalog(FSDL2InputKeyNames::SDL2Controller_Axis[l_AxisIdx], l_Event.jaxis.which, std::abs(l_Event.jaxis.value) <= JOYSTICK_DEADZONE ? 0.0f : l_Event.jaxis.value / 32768.0f);
				}break;

			case SDL_JOYBALLMOTION:
				m_MessageHandler->OnRawMouseMove(l_Event.jball.xrel, l_Event.jball.yrel);
				break;

			case SDL_JOYHATMOTION:{
				int32 l_HatIdx = l_Event.jhat.hat;
				if( l_HatIdx >= MAX_SDL2_HAT ) continue;

				if( 0 != (l_Event.jhat.value & SDL_HAT_LEFT) ) m_MessageHandler->OnControllerAnalog(FSDL2InputKeyNames::SDL2Controller_Hat[l_HatIdx * 2], l_Event.jhat.which, -1.0f);
				else if( 0 != (l_Event.jhat.value & SDL_HAT_RIGHT) ) m_MessageHandler->OnControllerAnalog(FSDL2InputKeyNames::SDL2Controller_Hat[l_HatIdx * 2], l_Event.jhat.which, 1.0f);
				else m_MessageHandler->OnControllerAnalog(FSDL2InputKeyNames::SDL2Controller_Hat[l_HatIdx * 2], l_Event.jhat.which, 0.0f);

				if( 0 != (l_Event.jhat.value & SDL_HAT_UP) ) m_MessageHandler->OnControllerAnalog(FSDL2InputKeyNames::SDL2Controller_Hat[l_HatIdx * 2 + 1], l_Event.jhat.which, 1.0f);
				else if( 0 != (l_Event.jhat.value & SDL_HAT_DOWN) ) m_MessageHandler->OnControllerAnalog(FSDL2InputKeyNames::SDL2Controller_Hat[l_HatIdx * 2 + 1], l_Event.jhat.which, -1.0f);
				else m_MessageHandler->OnControllerAnalog(FSDL2InputKeyNames::SDL2Controller_Hat[l_HatIdx * 2 + 1], l_Event.jhat.which, 0.0f);
				}break;

			case SDL_JOYBUTTONDOWN:{
				int32 l_BtnIdx = l_Event.jbutton.button;
				if( l_BtnIdx >= MAX_SDL2_BUTTON ) continue;

				m_MessageHandler->OnControllerButtonPressed(FSDL2InputKeyNames::SDL2Controller_Button[l_BtnIdx], l_Event.jbutton.which, false);	
				}break;

			case SDL_JOYBUTTONUP:{
				int32 l_BtnIdx = l_Event.jbutton.button;
				if( l_BtnIdx >= MAX_SDL2_BUTTON ) continue;

				m_MessageHandler->OnControllerButtonReleased(FSDL2InputKeyNames::SDL2Controller_Button[l_BtnIdx], l_Event.jbutton.which, false);
				}break;

			//case SDL_JOYDEVICEADDED:	break;
			//case SDL_JOYDEVICEREMOVED:break;
			default:break;
		}
	}
}
#pragma endregion

#pragma region FSDL2InputModule
//
// FSDL2InputModule
//
TSharedPtr< class IInputDevice > FSDL2InputModule::CreateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler)
{
	m_pSDL2InputDevice = MakeShareable(new ISDL2Input(InMessageHandler));
	return m_pSDL2InputDevice;
}

void FSDL2InputModule::StartupModule()
{
	IInputDeviceModule::StartupModule();

	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("SDL2Input")->GetBaseDir();

	// Add on the relative location of the third party dll and load it
	FString LibraryPath;
#if PLATFORM_WINDOWS
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/SDL2InputLibrary/Win64/SDL2.dll"));
#elif PLATFORM_MAC
    LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/SDL2InputLibrary/Mac/Release/SDL2.dylib"));
#endif // PLATFORM_WINDOWS

	m_pSDLHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;
	if( nullptr == m_pSDLHandle )
	{
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "Failed to load example third party library"));
		return;
	}
}

void FSDL2InputModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Free the dll handle
	FPlatformProcess::FreeDllHandle(m_pSDLHandle);
	m_pSDLHandle = nullptr;
}
#pragma endregion

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSDL2InputModule, SDL2Input)
