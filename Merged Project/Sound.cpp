#include "Sound.h"

void BackgroundSound(LPTSTR filename)
{
	PlaySound(filename, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void SoundEffect(LPTSTR filename, LPTSTR backgroundfilename)
{
	PlaySound(filename, NULL, SND_FILENAME);
	PlaySound(backgroundfilename, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}