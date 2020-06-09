#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"
#include "Map.h"


/************************************************************************

*列挙体の宣言

*************************************************************************/
typedef enum GAME_MODE {
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
int GameState = GAME_TITLE;


/***************************************************************

*関数プロトタイプの宣言

****************************************************************/
int Main(void);

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
	SetGraphMode(1280, 768, 32);		//ゲーム画面自体のサイズ

	/*****画像の読み込み*****/
	//if (LoadImages() == -1)return -1;		//画像読み込み関数を呼び出し
	//if (LoadVoice() == -1)return -1;		//音声読み込み関数を呼び出し

	//ゲームループ
	while (ProcessMessage() == 0 && GameState != END) {

		ClearDrawScreen();		//画面の初期化

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
		case GAME_END:
			//エンド描画処理
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
		}
		ScreenFlip();		//裏画面の内容を表画面に反映
	}
	DxLib_End();			//DXライブラリ使用の終了処理
	return 0;				//ソフトの処理
}

int Main(void) {

	Map();

	WaitKey();					//キー入力待ち

	return 0;
}