#include "LoadPic.h"		//ヘッダファイルの読み込み：構造体での画像の定義
#include "Map.h"			//ヘッダファイルの読み込み：マップ処理のプロトタイプ宣言
#include "Controller.h"
#include "Player.h"
#include "constant.h"
#include "Enemy.h"
#include "Title.h"
#include "Lock.h"
#include "LoadSound.h"
#include "Object.h"
#include "LoadSound.h"
#include "StageSelect.h"
#include <math.h>


//デバッグ用のマウス座標取得変数宣言
Controller g_Pad;
Player g_Player;
Sound g_Snd;
Object g_Object;
extern Controller g_Pad;
extern Player g_Player;
extern  int GameState= GAME_TITLE;
extern MapCoordinate g_MapC;
extern Sound g_Snd;

/*****************************************************************************
*FPSの取得、変更
********************************************************************************/
typedef class Fps {
	int mStartTime;         //測定開始時刻
	int mCount;             //カウンタ
	float mFps;             //fps
	static const int N = 60;//平均を取るサンプル数
	static const int FPS = 30;	//設定したFPS

public:
	Fps() {
		mStartTime = 0;
		mCount = 0;
		mFps = 0;
	}

	bool Update() {
		if (mCount == 0) { //1フレーム目なら時刻を記憶
			mStartTime = GetNowCount();
		}
		if (mCount == N) { //60フレーム目なら平均を計算する
			int t = GetNowCount();
			mFps = 1000.f / ((t - mStartTime) / (float)N);
			mCount = 0;
			mStartTime = t;
		}
		mCount++;
		return true;
	}

	void Draw() {
		DrawFormatString(1240, 0, GetColor(0, 0, 0), "%.1f", mFps);
	}

	void Wait() {
		int tookTime = GetNowCount() - mStartTime;	//かかった時間
		int waitTime = mCount * 1000 / FPS - tookTime;	//待つべき時間
		if (waitTime > 0) {
			Sleep(waitTime);	//待機
		}
	}
};


/***************************************************************

*関数プロトタイプの宣言

****************************************************************/
int Main(void);		//メイン処理
int Title(void);	//タイトル処理
int Menu(void);		//メニュー処理
int Init(void);		//初期化処理
int Clear(void);	//クリア処理
int Over(void);		//オーバー処理
int End(void);		//エンド処理
/*******************************
*プログラムの開始
********************************/
//プログラムはWinMainから始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	SetWindowSizeChangeEnableFlag(TRUE, 1);
	if (DxLib_Init() == -1)  return -1;		//DXライブラリ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする
	SetGraphMode(SCREEN_WIDHT, SCREEN_HEIGHT, 32);		//ゲーム画面自体のサイズ

	/*****画像の読み込み*****/
	if (LoadPictue() == -1)return -1;		//画像読み込み関数を呼び出し/失敗したらエラー
	if (LoadSound() == -1)return -1;		//音声読み込み関数を呼び出し

	Fps fps;

	//ゲームループ
	while (ProcessMessage() == 0 && GameState != END) {

		ClearDrawScreen();		//画面の初期化

		//マウスの位置を取得
		GetMousePoint(&g_Pad.MouseX, &g_Pad.MouseY);		//デバッグ用とか、画像配置用にマウス座標取得

		ControllerVlue();//コントローラーの入力状態を取得

		if (CheckSoundMem(g_Snd.StageBGM) == 0) {
			PlaySoundMem(g_Snd.StageBGM, DX_PLAYTYPE_LOOP);
		}

		switch (GameState) {
		case GAME_TITLE:
			Title();
			//タイトル処理
			break;
		case GAME_MENU:
			//ゲームメニュー処理
			Menu();
			break;
		case GAME_INIT:
			//ゲーム初期処理
			break;
		case GAME_MAIN :
			Main();
			//ゲームメイン処理
			break;
		case GAME_CLEAR:
			Clear();
			//ゲームクリア処理
			break;
		case GAME_OVER:
			//ゲームオーバー描画処理
			break;
		case GAME_END:
			//エンド描画処理
			break;
		}
		//DrawFormatString(0, 0, 0xff0fff, "X %d ", g_Pad.MouseX);
		//DrawFormatString(0, 20, 0xff0fff, "Y %d ", g_Pad.MouseY);
		//DrawFormatString(0, 40, 0xff0000, " %dステージ ", g_MapC.StageNumber);
		//DrawFormatString(0, 60, 0xff0fff, "g_Player.x %d ", g_Player.x);
		//DrawFormatString(0, 80, 0xff0fff, "g_Player.y %d ", g_Player.y);

		//DrawFormatString(100, 20, 0xff0fff, "g_Player.PLAYER_MOVEBOX_PULL %d ", g_Player.PLAYER_MOVEBOX_PULL);
		//DrawFormatString(100, 40, 0xff0fff, "g_Player.PLAYER_MOVEBOX_PUSH %d ", g_Player.PLAYER_MOVEBOX_PUSH);

		fps.Update();	//更新
		fps.Draw();		//描画
		ScreenFlip();
		fps.Wait();		//待機
	}
	DxLib_End();			//DXライブラリ使用の終了処理
	return 0;				//ソフトの処理
}
int Title(void) {
	GameTitle();
	return 0;
}
int Menu(void) {
	StageSelect();
	return 0;
}
int Init(void) {
	return 0;
}
int Main(void) {
	Map();
	PlayerDraw();
	return 0;
}
int Clear(void) {
	Goal();
	return 0;
}
int Over(void) {
	return 0;
}
int End(void) {
	return 0;
}