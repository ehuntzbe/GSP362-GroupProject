#pragma comment(lib, "winmm.lib")
#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <MMSystem.h>

using namespace std;

void BackgroundSoundCITY();
void BackgroundSoundBIZARRE();
void BackgroundSoundFOREST();
void BackgroundSoundSOFTWALKING();
void BackgroundSoundHARDWALKIING();

void BackgroundSoundINTRO();
void BackgroundSoundBATTLE();

void SoundEffectMALEINJURED();
void SoundEffectFEMALEINJURED();
void SoundEffectITEMEQUIP();
void SoundEffectLEVELUP();
void SoundEffectATTACK();
void SoundEffectVICTORY();
void SoundEffectMALEDEATH();
void SoundEffectFEMALEDEATH();