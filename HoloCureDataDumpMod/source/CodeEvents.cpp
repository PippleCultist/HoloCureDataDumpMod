#include "CommonFunctions.h"
#include "CodeEvents.h"

extern CallbackManagerInterface* callbackManagerInterfacePtr;
extern YYTKInterface* g_ModuleInterface;
extern CInstance* globalInstance;
extern YYRunnerInterface g_RunnerInterface;
extern int objAttackControllerIndex;

void PlayerManagerCreateAfter(std::tuple<CInstance*, CInstance*, CCode*, int, RValue*>& Args)
{
	CInstance* Self = std::get<0>(Args);
	{
		RValue MobsMap = g_ModuleInterface->CallBuiltin("variable_global_get", { "Mobs" });
		RValue mobsArr = g_ModuleInterface->CallBuiltin("ds_map_keys_to_array", { MobsMap });
		int mobsArrLength = static_cast<int>(g_ModuleInterface->CallBuiltin("array_length", { mobsArr }).m_Real);
		callbackManagerInterfacePtr->LogToFile(MODNAME, "mobMap:");
		for (int i = 0; i < mobsArrLength; i++)
		{
			RValue curMobKey = mobsArr[i];
			RValue curMob = g_ModuleInterface->CallBuiltin("ds_map_find_value", { MobsMap, curMobKey });
			callbackManagerInterfacePtr->LogToFile(MODNAME, "%s", curMob.AsString().data());
		}
	}

	{
		RValue FanLettersMap = g_ModuleInterface->CallBuiltin("variable_global_get", { "allFanLetters" });
		RValue fanLettersArr = g_ModuleInterface->CallBuiltin("ds_map_keys_to_array", { FanLettersMap });
		int fanLettersArrLength = static_cast<int>(g_ModuleInterface->CallBuiltin("array_length", { fanLettersArr }).m_Real);
		callbackManagerInterfacePtr->LogToFile(MODNAME, "fanLetters:");
		for (int i = 0; i < fanLettersArrLength; i++)
		{
			RValue key = fanLettersArr[i];
			RValue value = g_ModuleInterface->CallBuiltin("ds_map_find_value", { FanLettersMap, key });
			callbackManagerInterfacePtr->LogToFile(MODNAME, "%s", value.AsString().data());
		}
	}

	{
		RValue StickersMap = g_ModuleInterface->CallBuiltin("variable_instance_get", { Self, "STICKERS" });
		RValue stickersArr = g_ModuleInterface->CallBuiltin("ds_map_keys_to_array", { StickersMap });
		int stickersArrLength = static_cast<int>(g_ModuleInterface->CallBuiltin("array_length", { stickersArr }).m_Real);
		callbackManagerInterfacePtr->LogToFile(MODNAME, "stamps:");
		for (int i = 0; i < stickersArrLength; i++)
		{
			RValue key = stickersArr[i];
			RValue value = g_ModuleInterface->CallBuiltin("ds_map_find_value", { StickersMap, key });
			callbackManagerInterfacePtr->LogToFile(MODNAME, "%s", value.AsString().data());
		}
	}

	{
		RValue ItemsMap = g_ModuleInterface->CallBuiltin("variable_instance_get", { Self, "ITEMS" });
		RValue itemsArr = g_ModuleInterface->CallBuiltin("ds_map_keys_to_array", { ItemsMap });
		int itemsArrLength = static_cast<int>(g_ModuleInterface->CallBuiltin("array_length", { itemsArr }).m_Real);
		callbackManagerInterfacePtr->LogToFile(MODNAME, "items:");
		for (int i = 0; i < itemsArrLength; i++)
		{
			RValue key = itemsArr[i];
			RValue value = g_ModuleInterface->CallBuiltin("ds_map_find_value", { ItemsMap, key });
			callbackManagerInterfacePtr->LogToFile(MODNAME, "%s", value.AsString().data());
		}
	}

	{
		RValue characterDataMap = g_ModuleInterface->CallBuiltin("variable_global_get", { "characterData" });
		RValue characterDataArr = g_ModuleInterface->CallBuiltin("ds_map_keys_to_array", { characterDataMap });
		int characterDataArrLength = static_cast<int>(g_ModuleInterface->CallBuiltin("array_length", { characterDataArr }).m_Real);
		callbackManagerInterfacePtr->LogToFile(MODNAME, "characterData:");
		for (int i = 0; i < characterDataArrLength; i++)
		{
			RValue key = characterDataArr[i];
			RValue value = g_ModuleInterface->CallBuiltin("ds_map_find_value", { characterDataMap, key });
			callbackManagerInterfacePtr->LogToFile(MODNAME, "%s", value.AsString().data());
		}
	}

	{
		RValue attackMap = g_ModuleInterface->CallBuiltin("variable_instance_get", { objAttackControllerIndex, "attackIndex" });
		RValue attackArr = g_ModuleInterface->CallBuiltin("ds_map_keys_to_array", { attackMap });
		int attackArrLength = static_cast<int>(g_ModuleInterface->CallBuiltin("array_length", { attackArr }).m_Real);
		callbackManagerInterfacePtr->LogToFile(MODNAME, "attack:");
		for (int i = 0; i < attackArrLength; i++)
		{
			RValue key = attackArr[i];
			RValue value = g_ModuleInterface->CallBuiltin("ds_map_find_value", { attackMap, key });
			callbackManagerInterfacePtr->LogToFile(MODNAME, "%s", value.AsString().data());
		}
	}
}

void FandomManagerCreateAfter(std::tuple<CInstance*, CInstance*, CCode*, int, RValue*>& Args)
{
	CInstance* Self = std::get<0>(Args);
	RValue fanNames = g_ModuleInterface->CallBuiltin("variable_instance_get", { Self, "fanNames" });
	callbackManagerInterfacePtr->LogToFile(MODNAME, "%s", fanNames.AsString().data());
}

void StageManagerCreateAfter(std::tuple<CInstance*, CInstance*, CCode*, int, RValue*>& Args)
{
	RValue possibleDrops = g_ModuleInterface->CallBuiltin("variable_global_get", { "possibleDrops" });
	callbackManagerInterfacePtr->LogToFile(MODNAME, "%s", possibleDrops.AsString().data());
}

void PlayerManagerStepBefore(std::tuple<CInstance*, CInstance*, CCode*, int, RValue*>& Args)
{
	
}