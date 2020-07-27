#include"DxLib.h"
#include"LoadSound.h"

extern Sound g_Snd;

int LoadSound(void) {		//���̓ǂݍ���
	if ((g_Snd.Suc = LoadSoundMem("Sound/se_maoudamashii_retro03.wav")) == -1)return -1;				//����
	if ((g_Snd.Mis = LoadSoundMem("Sound/se_maoudamashii_retro04.wav")) == -1)return -1;			//���s


	if ((g_Snd.Key_Success = LoadSoundMem("Sound/kacha.mp3")) == -1)return -1;			//���J������
	if ((g_Snd.Key_Miss = LoadSoundMem("Sound/key3.mp3")) == -1)return -1;			//���J�����s

	if ((g_Snd.leva = LoadSoundMem("Sound/lever.mp3")) == -1)return -1;				//���o�[
	if ((g_Snd.BoxDrag = LoadSoundMem("Sound/Box_drag.mp3")) == -1)return -1;		//������������
	if ((g_Snd.Shower = LoadSoundMem("Sound/shower.mp3")) == -1)return -1;		//�V�����[

	return 0;
}