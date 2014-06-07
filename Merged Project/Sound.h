#pragma once
#pragma comment( lib, "Winmm.lib" )
#include <Windows.h>
#include <string>
#include <MMSystem.h>

using namespace std;

void BackgroundSound(LPTSTR filename);
void SoundEffect(LPTSTR filename, LPTSTR backgroundfilename);