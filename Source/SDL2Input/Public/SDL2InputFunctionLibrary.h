// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GenericPlatform/GenericApplicationMessageHandler.h"
#include "SDL2InputFunctionLibrary.generated.h"

#define MAX_SDL2_AXIS 6
#define MAX_SDL2_HAT 1
#define MAX_SDL2_BALL 2
#define MAX_SDL2_BUTTON 20

struct SDL2INPUT_API FSDL2InputKeyNames
{
	static const FGamepadKeyNames::Type SDL2Controller_Axis[MAX_SDL2_AXIS];
	static const FGamepadKeyNames::Type SDL2Controller_Hat[MAX_SDL2_HAT * 2];// x, y
	static const FGamepadKeyNames::Type SDL2Controller_Ball[MAX_SDL2_BALL];
	static const FGamepadKeyNames::Type SDL2Controller_Button[MAX_SDL2_BUTTON];
};

struct SDL2INPUT_API FSDL2InputKeys
{
	static const FKey SDL2Controller_Axis[MAX_SDL2_AXIS];
	static const FKey SDL2Controller_Hat[MAX_SDL2_HAT * 2];
	static const FKey SDL2Controller_Ball[MAX_SDL2_BALL];
	static const FKey SDL2Controller_Button[MAX_SDL2_BUTTON];
};

USTRUCT(BlueprintType)
struct SDL2INPUT_API FRegisteredSDL2DeviceInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="SDL2Input")
	int32 Handle;

	// Integer representation of the vendor ID (e.g. 0xC262 = 49762)
	UPROPERTY(BlueprintReadOnly, Category="SDL2Input")
	int32 VendorID;

	// Integer representation of the product ID (e.g. 0xC262 = 49762)
	UPROPERTY(BlueprintReadOnly, Category="SDL2Input")
	int32 ProductID;

	// Driver supplied device name
	UPROPERTY(BlueprintReadOnly, Category="SDL2Input")
	FString DeviceName;
};

UCLASS()
class SDL2INPUT_API USDL2InputFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="SDL2Input")
	static TArray<FRegisteredSDL2DeviceInfo> GetRegisteredDevices();
};
