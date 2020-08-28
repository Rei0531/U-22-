#include "Controller.h"
#include "Map.h"
#include "constant.h"
#include "Player.h"

extern Controller g_Pad;
extern Player g_Player;

void ControllerVlue(void) {         //プレイヤーの移動処理関数
	//左入力_____________________________________________________________________________________________________________________
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) != 0)    //画面左側制限
	{
		g_Pad.KEY_LEFT = TRUE;
		if (GameState == GAME_MAIN && g_Player.PLAYER_MENU == FALSE && g_Player.PLAYER_MOVEOK == TRUE) { //ゲームがプレイ中だったら
			g_Player.PLAYER_DIRECTION = TRUE;  //プレイヤーの向きフラグを左にする
		}
	}
	else { g_Pad.KEY_LEFT = FALSE; }
	//右入力_____________________________________________________________________________________________________________________
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT) != 0)
	{
		g_Pad.KEY_RIGHT = TRUE;
		if (GameState == GAME_MAIN && g_Player.PLAYER_MENU == FALSE && g_Player.PLAYER_MOVEOK == TRUE) { //ゲームがプレイ中だったら
			g_Player.PLAYER_DIRECTION = FALSE;  //プレイヤーの向きフラグを右にする
		}
	}
	else { g_Pad.KEY_RIGHT = FALSE; }
	//上入力_____________________________________________________________________________________________________________________
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP) != 0)
	{
		g_Pad.KEY_UP = TRUE;
	}
	else { g_Pad.KEY_UP = FALSE; }
	//下入力_____________________________________________________________________________________________________________________
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN) != 0)
	{
		g_Pad.KEY_DOWN = TRUE;
	}
	else { g_Pad.KEY_DOWN = FALSE; }
	//Bボタン_____________________________________________________________________________________________________________________
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B) != 0)//アクション処理
	{
		g_Pad.KEY_B = TRUE;
		if ((GameState == GAME_MAIN) & (g_Pad.KEY_FLG_B == TRUE)) { //ゲームがプレイ中だったら
			g_Player.PLAYER_ACTION = TRUE;      //プレイヤーのアクションフラグ
			g_Pad.KEY_FLG_B = FALSE;      //ボタンが離されるまでFLGをFALSEにする
		}
	}
	else {
		g_Pad.KEY_B = FALSE;
		g_Pad.KEY_FLG_B = TRUE;
		g_Player.PLAYER_ACTION = FALSE;      //プレイヤーのアクションフラグ
	}
	//Aボタン_____________________________________________________________________________________________________________________
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A) != 0)
	{
		g_Pad.KEY_A = TRUE;
		if (GameState == GAME_MAIN && g_Player.PLAYER_JUMP == FALSE 
			&& g_Player.PLAYER_MENU == FALSE && g_Player.PLAYER_MOVEOK == TRUE) {//ゲームがプレイ中だったら
			g_Player.PLAYER_JUMP = TRUE;
		}
	}
	else { g_Pad.KEY_A = FALSE; }
	//Xボタン_____________________________________________________________________________________________________________________
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_3) != 0)//アクション処理
	{
		g_Pad.KEY_X = TRUE;
		if ((GameState == GAME_MAIN) & (g_Pad.KEY_FLG == TRUE)) { //ゲームがプレイ中だったら
			g_Player.PLAYER_PICKUP = TRUE;      //プレイヤーのスポイトフラグ
			g_Pad.KEY_FLG = FALSE;      //ボタンが離されるまでFLGをFALSEにする
		}
	}
	else {
		g_Pad.KEY_X = FALSE;
		g_Pad.KEY_FLG = TRUE;
	}
	//STARTボタン_____________________________________________________________________________________________________________________
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_8) != 0)//オプションボタン    //オプション処理
	{
		g_Pad.KEY_Y = TRUE;
		if ((GameState == GAME_MAIN) & (g_Pad.KEY_FLG_Y == TRUE)) { //ゲームがプレイ中だったら
			g_Player.PLAYER_MENU = TRUE;      //プレイヤーのメニューフラグ
			g_Pad.KEY_FLG_Y = FALSE;    //ボタンが離されるまでFLGをFALSEにする
		}
	}
	else {
		g_Pad.KEY_Y = FALSE;
		g_Pad.KEY_FLG_Y = TRUE;
	}
	////L1,R1ボタン_____________________________________________________________________________________________________________________
	//if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_6) != 0 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_5) != 0)//L1,R1ボタン    //ダッシュ処理
	//{
	//	g_Pad.KEY_LR = TRUE;
	//}
	//else { g_Pad.KEY_LR = FALSE; }

	//_____________________________________________________________________________________________________________________
	//if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {          //コントローラーない時はこの処理でキーボードの十字キーで操作
	//    g_MapC.X1 -= PLAYERX;
	//    g_MapC.X2 -= PLAYERX;
	//}
	//if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
	//    g_MapC.X1 += PLAYERX;
	//    g_MapC.X2 += PLAYERX;
	//}
}