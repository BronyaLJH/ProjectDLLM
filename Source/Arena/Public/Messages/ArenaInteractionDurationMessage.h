// Copyright Ludens Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"

class AArenaCharacter;

#include "ArenaInteractionDurationMessage.generated.h"

UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_INTERACTION_DURATION_MESSAGE);

USTRUCT(BlueprintType)
struct FArenaInteractionDurationMessage
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<AArenaCharacter> Instigator = nullptr;
	
	UPROPERTY(BlueprintReadWrite)
	float Duration = 0;

	UPROPERTY(BlueprintReadWrite)
	FGameplayTag CooldownTag;
};

