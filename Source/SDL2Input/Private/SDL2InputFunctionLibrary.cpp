// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "SDL2InputFunctionLibrary.h"

const FGamepadKeyNames::Type FSDL2InputKeyNames::SDL2Controller_Axis[] = {
	"SDL2Controller_Axis1",
	"SDL2Controller_Axis2",
	"SDL2Controller_Axis3",
	"SDL2Controller_Axis4"};
	
const FGamepadKeyNames::Type FSDL2InputKeyNames::SDL2Controller_Hat[] = {
	"SDL2Controller_Hat1_AxisX",
	"SDL2Controller_Hat1_AxisY"};

const FGamepadKeyNames::Type FSDL2InputKeyNames::SDL2Controller_Ball[] = {
	"SDL2Controller_Ball1",
	"SDL2Controller_Ball2"};

const FGamepadKeyNames::Type FSDL2InputKeyNames::SDL2Controller_Button[] = {
	"SDL2Controller_Button1",
	"SDL2Controller_Button2",
	"SDL2Controller_Button3",
	"SDL2Controller_Button4",
	"SDL2Controller_Button5",
	"SDL2Controller_Button6",
	"SDL2Controller_Button7",
	"SDL2Controller_Button8",
	"SDL2Controller_Button9",
	"SDL2Controller_Button10",
	"SDL2Controller_Button11",
	"SDL2Controller_Button12",
	"SDL2Controller_Button13",
	"SDL2Controller_Button14",
	"SDL2Controller_Button15",
	"SDL2Controller_Button16",
	"SDL2Controller_Button17",
	"SDL2Controller_Button18",
	"SDL2Controller_Button19",
	"SDL2Controller_Button20"};

// USB controller (Wheels, flight stick etc)
const FKey FSDL2InputKeys::SDL2Controller_Axis[] = {
	FSDL2InputKeyNames::SDL2Controller_Axis[0],
	FSDL2InputKeyNames::SDL2Controller_Axis[1],
	FSDL2InputKeyNames::SDL2Controller_Axis[2],
	FSDL2InputKeyNames::SDL2Controller_Axis[3]};

const FKey FSDL2InputKeys::SDL2Controller_Hat[] = {
	FSDL2InputKeyNames::SDL2Controller_Hat[0],
	FSDL2InputKeyNames::SDL2Controller_Hat[1]};

const FKey FSDL2InputKeys::SDL2Controller_Ball[] = {
	FSDL2InputKeyNames::SDL2Controller_Ball[0],
	FSDL2InputKeyNames::SDL2Controller_Ball[1]};

const FKey FSDL2InputKeys::SDL2Controller_Button[] = {
	FSDL2InputKeyNames::SDL2Controller_Button[0],
	FSDL2InputKeyNames::SDL2Controller_Button[1],
	FSDL2InputKeyNames::SDL2Controller_Button[2],
	FSDL2InputKeyNames::SDL2Controller_Button[3],
	FSDL2InputKeyNames::SDL2Controller_Button[4],
	FSDL2InputKeyNames::SDL2Controller_Button[5],
	FSDL2InputKeyNames::SDL2Controller_Button[6],
	FSDL2InputKeyNames::SDL2Controller_Button[7],
	FSDL2InputKeyNames::SDL2Controller_Button[8],
	FSDL2InputKeyNames::SDL2Controller_Button[9],
	FSDL2InputKeyNames::SDL2Controller_Button[10],
	FSDL2InputKeyNames::SDL2Controller_Button[11],
	FSDL2InputKeyNames::SDL2Controller_Button[12],
	FSDL2InputKeyNames::SDL2Controller_Button[13],
	FSDL2InputKeyNames::SDL2Controller_Button[14],
	FSDL2InputKeyNames::SDL2Controller_Button[15],
	FSDL2InputKeyNames::SDL2Controller_Button[16],
	FSDL2InputKeyNames::SDL2Controller_Button[17],
	FSDL2InputKeyNames::SDL2Controller_Button[18],
	FSDL2InputKeyNames::SDL2Controller_Button[19]};

TArray<FRegisteredSDL2DeviceInfo> USDL2InputFunctionLibrary::GetRegisteredDevices()
{
	TArray<FRegisteredSDL2DeviceInfo> RegisteredDevices;

	/*FSDL2Input* RawInput = static_cast<FRawInputWindows*>(static_cast<FRawInputPlugin*>(&FRawInputPlugin::Get())->GetRawInputDevice().Get());

	RegisteredDevices.Reserve(RawInput->RegisteredDeviceList.Num());
	for (const TPair<int32, FRawWindowsDeviceEntry>& RegisteredDevice : RawInput->RegisteredDeviceList)
	{
		const FRawWindowsDeviceEntry& DeviceEntry = RegisteredDevice.Value;
		if (DeviceEntry.bIsConnected)
		{
			RegisteredDevices.Add(RawInput->GetDeviceInfo(RegisteredDevice.Key));
		}
	}*/

	return RegisteredDevices;
}