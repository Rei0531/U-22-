//#include "DxLib.h"
//#include "Player.h"		//ヘッダファイルの読み込み：プレイヤー処理のプロトタイプ宣言
//#include "Enemy.h"		//ヘッダファイルの読み込み：敵処理のプロトタイプ宣言
#include "LoadPic.h"		//ヘッダファイルの読み込み：構造体での画像の定義
#include "Map.h"			//ヘッダファイルの読み込み：マップ処理のプロトタイプ宣言
#include "Controller.h"
#include "Player.h"
#include "Controller.h"
#include "constant.h"

/************************************************************************

*列挙体の宣言

*************************************************************************/
typedef enum GAME_MODE {		//ゲームの状態
	GAME_TITLE,
	GAME_MENU,
	GAME_INIT,
	GAME_END,
	GAME_MAIN,
	GAME_CLEAR,
	GAME_OVER,
	END = 99
};
/****************************************************************

*変数の宣言

****************************************************************/
int GameState = GAME_TITLE;		//ゲームの状態を格納する変数


Controller g_Pad;
extern Controller g_Pad;


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
	//if (LoadVoice() == -1)return -1;		//音声読み込み関数を呼び出し

	//ゲームループ
	while (ProcessMessage() == 0 && GameState != END) {

		ClearDrawScreen();		//画面の初期化

		//マウスの位置を取得
		GetMousePoint(&g_Pad.MouseX, &g_Pad.MouseY);		//デバッグ用とか、画像配置用にマウス座標取得

		switch (GameState) {
		case GAME_TITLE:
			Main();
			//タイトル処理
			break;
		case GAME_MENU:
			//ゲームメニュー処理
			break;
		case GAME_INIT:
			//ゲーム初期処理
			break;
		case GAME_MAIN:
			//ゲームメイン処理
			break;
		case GAME_CLEAR:
			//ゲームクリア処理
			break;
		case GAME_OVER:
			//ゲームオーバー描画処理
			break;
		case GAME_END:
			//エンド描画処理
			break;
		}

		DrawFormatString(0, 0, 0xff0000, "X %d ", g_Pad.MouseX);
		DrawFormatString(0, 10, 0xff0000, "Y %d ", g_Pad.MouseY);
		DrawFormatString(0, 20, 0xff0000, "NowKey %d ", g_Pad.NowKey);
		ScreenFlip();		//裏画面の内容を表画面に反映
	}
	DxLib_End();			//DXライブラリ使用の終了処理
	return 0;				//ソフトの処理
}
int Title(void) {
	return 0;
}
int Menu(void) {
	return 0;
}
int Init(void) {
	return 0;
}
int Main(void) {
	ControllerVlue();
	Map();
	Player();
	return 0;
}
int Clear(void) {
	return 0;
}
int Over(void) {
	return 0;
}
int End(void) {
	return 0;
}