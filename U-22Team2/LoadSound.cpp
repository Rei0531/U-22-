#include"DxLib.h"
#include"LoadSound.h"

extern Sound g_Snd;

int LoadSound(void) {		//���̓ǂݍ���
	if ((g_Snd.Suc = LoadSoundMem("Sound/se_maoudamashii_retro03.wav")) == -1)return -1;				//����
	if ((g_Snd.Mis = LoadSoundMem("Sound/se_maoudamashii_retro04.wav")) == -1)return -1;			//���s
	return 0;
}