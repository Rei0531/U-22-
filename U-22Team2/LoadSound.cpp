#include"DxLib.h"
#include"LoadSound.h"

extern Sound g_Snd;

int LoadSound(void) {		//音の読み込み
	if ((g_Snd.Suc = LoadSoundMem("Sound/Supoit.mp3")) == -1)return -1;					//成功
	if ((g_Snd.Mis = LoadSoundMem("Sound/Supoit2.mp3")) == -1)return -1;				//失敗


	if ((g_Snd.Key_Success = LoadSoundMem("Sound/kacha.mp3")) == -1)return -1;			//鍵開け成功
	if ((g_Snd.Key_Miss = LoadSoundMem("Sound/key3.mp3")) == -1)return -1;				//鍵開け失敗

	if ((g_Snd.leva = LoadSoundMem("Sound/lever.mp3")) == -1)return -1;					//レバー
	if ((g_Snd.BoxDrag = LoadSoundMem("Sound/Box_drag.mp3")) == -1)return -1;			//箱を引きずる
	if ((g_Snd.Shower = LoadSoundMem("Sound/shower.mp3")) == -1)return -1;				//シャワー

	if ((g_Snd.Walk = LoadSoundMem("Sound/HP回復.mp3")) == -1)return -1;				//回復アイテム取得
	if ((g_Snd.Walk = LoadSoundMem("Sound/Play2.mp3")) == -1)return -1;					//変形オブジェクト作動
	if ((g_Snd.Walk = LoadSoundMem("Sound/footsteps.mp3")) == -1)return -1;				//歩く音
	if ((g_Snd.MenuOpen = LoadSoundMem("Sound/MenuOpen.mp3")) == -1)return -1;			//メニューオープン
	if ((g_Snd.MenuClose = LoadSoundMem("Sound/MenuClose.mp3")) == -1)return -1;		//メニュークローズ
	if ((g_Snd.MenuMove = LoadSoundMem("Sound/MenuMove.mp3")) == -1)return -1;			//メニュー内移動
	if ((g_Snd.Reset = LoadSoundMem("Sound/Reset.mp3")) == -1)return -1;				//リセット時
	if ((g_Snd.Switch = LoadSoundMem("Sound/button.mp3")) == -1)return -1;				//スイッチ
	if ((g_Snd.Warp = LoadSoundMem("Sound/Warp2.mp3")) == -1)return -1;					//ワープ
	if ((g_Snd.Landing = LoadSoundMem("Sound/tyakuti.mp3")) == -1)return -1;			//着地
	if ((g_Snd.Bomb= LoadSoundMem("Sound/Bomb_PON.mp3")) == -1)return -1;				//爆弾
	if ((g_Snd.StageBGM = LoadSoundMem("Sound/StageBGM01.mp3")) == -1)return -1;		//ステージBGM

	return 0;
}