#include "Menu.h"

static bool DOWN = FALSE,//下キー
            UP = FALSE;//上キー

//更新
bool Menu_Update() {

    if (g_Pad.KEY_DOWN == TRUE && DOWN == FALSE) {//下キーが押されていたら
        DOWN = TRUE;
        NowSelect = (NowSelect + 1) % eMenu_Num;//選択状態を一つ下げる
    }
    if (g_Pad.KEY_UP == TRUE && UP == FALSE) {//上キーが押されていたら
        UP = TRUE;
        NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//選択状態を一つ上げる
    }

    DOWN = (g_Pad.KEY_DOWN == TRUE) ? TRUE : FALSE;//下キーが押されていたら

    UP = (g_Pad.KEY_UP == TRUE) ? TRUE : FALSE;//上キーが押されていたら

    if (g_Pad.KEY_B == TRUE) {//Bボタンが押されたら
        switch (NowSelect) {//現在選択中の状態によって処理を分岐
        case eMenu_Select://セレクト選択中なら
            //本来はここにセレクト画面以降処理
            GameState = GAME_MAIN;//シーンをセレクト画面に変更
            g_Player.PLAYER_MENU = FALSE;//メニューを開くフラグをFALSEにする
            break;
        case eMenu_Reset://リセット選択中なら
            g_Player.PLAYER_MENU = FALSE;//メニューを開くフラグをFALSEにする
            g_Player.PLAYER_RESET = TRUE;  //リセットした処理をTRUEにする
            return TRUE;    //ステージ処理をリセットする処理のフラグをTRUEにする
            break;
        case eMenu_End:
            g_Player.PLAYER_MENU = FALSE;//メニューを開くフラグをFALSEにする
            break;

        }
    }
    return FALSE;
}

//描画
void Menu_Draw() {
    static int MenuX = 440, MenuY = 200;
    DrawBox(MenuX, 200, MenuX+400, MenuY+400,GetColor(200,200,200),TRUE);
    DrawString(MenuX + 100, MenuY + 100, "メニュー画面です。", GetColor(0, 0, 0));
    DrawString(MenuX + 150, GAME_Y, "ステージセレクト", GetColor(0, 0, 0));
    DrawString(MenuX + 150, RESET_Y, "リセット", GetColor(0, 0, 0));
    DrawString(MenuX + 150, END_Y, "終了", GetColor(0, 0, 0));
    int y = 0;
    switch (NowSelect) {//現在の選択状態に従って処理を分岐
    case eMenu_Select://セレクト選択中なら
        y = GAME_Y;    //セレクトの座標を格納
        break;
    case eMenu_Reset://リセット選択中なら
        y = RESET_Y;    //リセットの座標を格納
        break;
    case eMenu_End://終了選択中なら
        y = END_Y;      //終了の座標を格納
    }
    DrawString(MenuX + 120, y, "■", GetColor(0, 0, 0));
}