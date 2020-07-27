#include"DxLib.h"
#include"LoadSound.h"

extern Sound g_Snd;

int LoadSound(void) {		//音の読み込み
	if ((g_Snd.Suc = LoadSoundMem("Sound/se_maoudamashii_retro03.wav")) == -1)return -1;				//成功
	if ((g_Snd.Mis = LoadSoundMem("Sound/se_maoudamashii_retro04.wav")) == -1)return -1;			//失敗


	if ((g_Snd.Key_Success = LoadSoundMem("Sound/kacha.mp3")) == -1)return -1;			//鍵開け成功
	if ((g_Snd.Key_Miss = LoadSoundMem("Sound/key3.mp3")) == -1)return -1;			//鍵開け失敗

	if ((g_Snd.leva = LoadSoundMem("Sound/lever.mp3")) == -1)return -1;				//レバー
	if ((g_Snd.BoxDrag = LoadSoundMem("Sound/Box_drag.mp3")) == -1)return -1;		//箱を引きずる
	if ((g_Snd.Shower = LoadSoundMem("Sound/shower.mp3")) == -1)return -1;		//シャワー

	return 0;
}