#include "Sound.h"

void BackgroundSoundINTRO()
{
	PlaySound(TEXT("electricpercussion.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void SoundEffectATTACK()
{
	PlaySound(TEXT("defaultjump.wav"), NULL, SND_FILENAME);
	PlaySound(TEXT("electricpercussion.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}