#pragma once
/**********************************************
*ゲーム上の定数の宣言
***********************************************/
const int PLAYERX = 8;			//マップスクロール速度,画面端プレイヤーの移動速度
const int SCREEN_WIDHT = 1280;	//画面の横のサイズ
const int SCREEN_HEIGHT = 768;	//画面の縦のサイズ
const int MAP_WIDHT = SCREEN_WIDHT * 4;	//マップ画像の横のサイズ
const int MAP_HEIGHT = SCREEN_HEIGHT * 2;	//マップ画像の縦のサイズ

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
static int GameState = GAME_TITLE;		//ゲームの状態を格納する変数

