#pragma once
#include "ModuleMain.h"
#include <Aurie/shared.hpp>
#include <YYToolkit/shared.hpp>

using menuFunc = void (*)(void);

void PlayerManagerCreateAfter(std::tuple<CInstance*, CInstance*, CCode*, int, RValue*>& Args);
void FandomManagerCreateAfter(std::tuple<CInstance*, CInstance*, CCode*, int, RValue*>& Args);
void PlayerManagerStepBefore(std::tuple<CInstance*, CInstance*, CCode*, int, RValue*>& Args);
void StageManagerCreateAfter(std::tuple<CInstance*, CInstance*, CCode*, int, RValue*>& Args);