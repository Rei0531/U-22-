#include "Controller.h"
#include "Map.h"
#include "constant.h"
#include "Player.h"

extern Controller g_Pad;
Player g_Player;

void ControllerVlue(void) {         //プレイヤーの移動処理関数
    //左入力_____________________________________________________________________________________________________________________
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) != 0)    //画面左側制限
    {
        g_Pad.KEY_LEFT = TRUE;
        if (GameState == GAME_TITLE) { //ゲームがプレイ中だったら//今はタイトルで動かしている
            g_Player.PLAYER_DIRECTION = TRUE;  //プレイヤーの向きフラグを左にする
        }
    }
    else { g_Pad.KEY_LEFT = FALSE; }
    //右入力_____________________________________________________________________________________________________________________
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT) != 0)
    {
        g_Pad.KEY_RIGHT = TRUE;
        if (GameState == GAME_TITLE) { //ゲームがプレイ中だったら//今はタイトルで動かしている
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
        if (GameState == GAME_TITLE) { //ゲームがプレイ中だったら//今はタイトルで動かしている
            g_Player.PLAYER_SQUAT = TRUE;      //プレイヤーのしゃがみフラグ
        }
    }
    else { g_Pad.KEY_DOWN = FALSE; }
    //Bボタン_____________________________________________________________________________________________________________________
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B) != 0)//ジャンプ処理
    {
        g_Pad.KEY_B = TRUE;
        if (GameState == GAME_TITLE && g_Player.PLAYER_JUMP == FALSE) {//ゲームがプレイ中だったら//今はタイトルで動かしている
            g_Player.PLAYER_JUMP = TRUE;
        }
    }
    else { g_Pad.KEY_B = FALSE; }
    //Aボタン_____________________________________________________________________________________________________________________
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A) != 0)
    {
        g_Pad.KEY_A = TRUE;
        if (GameState == GAME_TITLE) { //ゲームがプレイ中だったら//今はタイトルで動かしている
            g_Player.PLAYER_SQUAT = TRUE;      //プレイヤーのしゃがみフラグ
        }
    }
    else { g_Pad.KEY_A = FALSE; }
    //Xボタン_____________________________________________________________________________________________________________________
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_3) != 0)//アクション処理
    {
        g_Pad.KEY_X = TRUE;
        if (GameState == GAME_TITLE) { //ゲームがプレイ中だったら//今はタイトルで動かしている
            g_Player.PLAYER_ACTION = TRUE;      //プレイヤーのアクションフラグ
        }
    }
    else { g_Pad.KEY_X = FALSE; }
    //Yボタン_____________________________________________________________________________________________________________________
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_4) != 0)//オプションボタン    //オプション処理
    {
        g_Pad.KEY_Y = TRUE;
        if (GameState == GAME_TITLE) { //ゲームがプレイ中だったら//今はタイトルで動かしている
            g_Player.PLAYER_MENU = TRUE;      //プレイヤーのメニューフラグ
        }
    }
    else { g_Pad.KEY_Y = FALSE; }
    //L1,R1ボタン_____________________________________________________________________________________________________________________
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_6) != 0 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_5) != 0)//L1,R1ボタン    //ダッシュ処理
    {
        g_Pad.KEY_LR = TRUE;
    }
    else { g_Pad.KEY_LR = FALSE; }

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