#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Object.h"
#include "LoadSound.h"
#include "Menu.h"
#include "Draw_Door_Rotation.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Controller g_Pad;
extern Sound g_Snd;

static bool InitFlag = TRUE;//Init関数を通っていいか判定変数/TRUEがいい/FALSEがダメ

int g_SwitchFlag = 0;		//レバーのON、OFF
int g_SwitchWait = 0;		//レバーの待機時間

void Stage5Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 10;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = 4;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	g_SwitchFlag = 0;			//スイッチ初期化

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//ドアの位置
	g_Door.x = 1100;			//扉の左上のx座標
	g_Door.y = 468;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅


}

int Stage5(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage5Init();
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画
	//色ブロック描画

	Change(LIGHTBLUE);
	if ((g_Player.x > 424) & (g_Player.x < 575) & (g_Pad.KEY_B == TRUE)
		& (g_SwitchFlag == 0) & (g_SwitchWait == 0) & (g_Player.NowColor == 4)) { //スイッチフラグがOFFであり待機時間が０でありスイッチと重なってあり
		g_SwitchFlag = 1;														  //レバーの色と主人公が同じである状態でインタラクトを押すと箱が消える
		g_SwitchWait = 10;
		PlaySoundMem(g_Snd.leva, DX_PLAYTYPE_BACK);
	}
	else if ((g_Player.x > 424) & (g_Player.x < 575) & (g_Pad.KEY_B == TRUE)	  //スイッチがONの場合はOFFに切り替える
		& (g_SwitchFlag == 1) & (g_SwitchWait == 0) & (g_Player.NowColor == 4)){  //レバーがONまたはOFFになった場合待機時間が加わる
		g_SwitchFlag = 0;
		g_SwitchWait = 10;
		PlaySoundMem(g_Snd.leva, DX_PLAYTYPE_BACK);
	}

	if (g_SwitchFlag == 0) {													  
		DrawRotaGraph(500, 623, 1.0, 0, g_pic.Reba, TRUE, FALSE);
	}
	else if (g_SwitchFlag == 1) {
		DrawRotaGraph(500, 623, 1.0, 0, g_pic.Reba, TRUE, TRUE);
		Change(WHITE);
		DrawExtendGraph(700, 558, 800, 668, g_pic.Box, TRUE);
	}
	DrawExtendGraph(700, 558, 800, 668, g_pic.Box, TRUE);
	DrawExtendGraph(700, 458, 800, 568, g_pic.Box, TRUE);
	if (g_SwitchWait != 0) {													//待機時間がある場合減らし続ける
		g_SwitchWait--;
	}
	//DrawFormatString(0, 400, 0x000000, "g_SwitchFlag = %d", g_SwitchFlag);
	Door();			//ステージゴール処理
	Lock();

	DoorRotationBox(1);

	ColorReset();

	if (g_Player.PLAYER_MENU == TRUE) {
		Menu_Draw();
		InitFlag = Menu_Update();
	}
	return 0;
}