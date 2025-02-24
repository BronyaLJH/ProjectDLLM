// Copyright Ludens Studio. All Rights Reserved.


#include "ArenaGameplayTags.h"


namespace ArenaGameplayTags
{
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Ability_ActivateFail_ActivationGroup, "Ability.ActivateFail.ActivationGroup", "Ability failed to activate because of its activation group.");
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Move, "InputTag.Move", "Move input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Jump, "InputTag.Jump", "Jump input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_LookMouse, "InputTag.LookMouse", "Look input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Equip, "InputTag.Equip", "Equip input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Drop, "InputTag.Drop", "Drop input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Crouch, "InputTag.Crouch", "Crouch input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Aim, "InputTag.Aim", "Aim input.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Fire, "InputTag.Fire", "Fire input.")
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Sprint, "InputTag.Sprint", "Sprint input.")
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_Walk, "InputTag.Walk", "Walk input.")

	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Ability_Behavior_SurvivesDeath, "Ability.Behavior.SurvivesDeath", "An ability with this type tag should not be canceled due to death.");

	UE_DEFINE_GAMEPLAY_TAG_COMMENT(GameplayEvent_Death, "GameplayEvent.Death", "Event that fires on death. This event only fires on the server.")
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(GameplayEvent_Reset, "GameplayEvent.Reset", "Event that fires once a player reset is executed.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(GameplayEvent_RequestReset, "GameplayEvent.RequestReset", "Event to request a player's pawn to be instantly replaced with a new one at a valid spawn location.");
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Status_Death, "Status.Death", "Target has the death status.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Status_Death_Dying, "Status.Death.Dying", "Target has begun the death process.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Status_Death_Dead, "Status.Death.Dead", "Target has finished the death process.");

	UE_DEFINE_GAMEPLAY_TAG_COMMENT(DamageType_Grenade_AOE, "DamageType.Grenade.AOE", "Damage Tag for Grenade AOE damage.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(DamageType_Grenade_DirectHit, "DamageType.Grenade.DirectHit", "Damage Tag for Grenade Direct Hit damage.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(DamageType_Grenade_Effect, "DamageType.Grenade.Effect", "Damage Tag for Grenade Effect damage.");

	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Ability_Grenade_Duration_Message, "Ability.Grenade.Duration.Message", "Tag for grenade duration message.");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Ability_Dash_Duration_Message, "Ability.Dash.Duration.Message", "Tag for dash duration message.");
	
	FGameplayTag FindTagByString(const FString& TagString, bool bMatchPartialString)
	{
		const UGameplayTagsManager& Manager = UGameplayTagsManager::Get();
		FGameplayTag Tag = Manager.RequestGameplayTag(FName(*TagString), false);

		if (!Tag.IsValid() && bMatchPartialString)
		{
			FGameplayTagContainer AllTags;
			Manager.RequestAllGameplayTags(AllTags, true);

			for (const FGameplayTag& TestTag : AllTags)
			{
				if (TestTag.ToString().Contains(TagString))
				{
					UE_LOG(LogTemp, Display, TEXT("Could not find exact match for tag [%s] but found partial match on tag [%s]."), *TagString, *TestTag.ToString());
					Tag = TestTag;
					break;
				}
			}
		}

		return Tag;
	}
}
