#include "Menu.h"
#include "LoadSound.h"


extern Sound g_Snd;
extern image g_pic;

static bool DOWN = FALSE,//下キー
            UP = FALSE,//上キー
            B = FALSE;//Bボタン

static bool Sndflg = FALSE;//音再生フラグ

//更新
bool Menu_Update() {

    if (CheckSoundMem(g_Snd.MenuOpen) == 0 && Sndflg == FALSE) {
        PlaySoundMem(g_Snd.MenuOpen, DX_PLAYTYPE_BACK);
        Sndflg = TRUE;//音再生フラグをTRUEにして二度再生防止
    }

    if (g_Pad.KEY_DOWN == TRUE && DOWN == FALSE) {//下キーが押されていたら
        DOWN = TRUE;
        NowSelect = (NowSelect + 1) % eMenu_Num;//選択状態を一つ下げる
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
    }
    if (g_Pad.KEY_UP == TRUE && UP == FALSE) {//上キーが押されていたら
        UP = TRUE;
        NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//選択状態を一つ上げる
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
    }

    DOWN = (g_Pad.KEY_DOWN == TRUE) ? TRUE : FALSE;//下キーが押されていたら

    UP = (g_Pad.KEY_UP == TRUE) ? TRUE : FALSE;//上キーが押されていたら

    if (g_Pad.KEY_B == TRUE && B == FALSE) {//Bボタンが押されたら
        Sndflg = FALSE;//メニューオープンのフラグをFALSEにして再度関数に入った時音が鳴るようにする
        switch (NowSelect) {//現在選択中の状態によって処理を分岐
        case eMenu_Select://セレクト選択中なら
            //本来はここにセレクト画面以降処理
            GameState = GAME_TITLE;//シーンをセレクト画面に変更
            g_Player.PLAYER_MENU = FALSE;//メニューを開くフラグをFALSEにする
            g_Player.InitFlag = TRUE;//ステージInit処理のフラグをTRUEにする
            g_Player.PLAYER_RESET = TRUE;//リセット処理をTRUEにする
            break;
        case eMenu_Reset://リセット選択中なら
            g_Player.PLAYER_MENU = FALSE;//メニューを開くフラグをFALSEにする
            g_Player.PLAYER_RESET = TRUE;  //リセットした処理をTRUEにする
            PlaySoundMem(g_Snd.Reset, DX_PLAYTYPE_BACK);
            return TRUE;    //ステージ処理をリセットする処理のフラグをTRUEにする
            break;
        case eMenu_End:
            g_Player.PLAYER_MENU = FALSE;//メニューを開くフラグをFALSEにする
            PlaySoundMem(g_Snd.MenuClose, DX_PLAYTYPE_BACK);//メニューを閉じたときの音
            break;

        }
    }

    B = (g_Pad.KEY_B == TRUE) ? TRUE : FALSE;//Bボタンが押されていたら/再度Bボタンが押せるように

    return FALSE;
}

//描画
void Menu_Draw() {

    static int MenuX = 440, MenuY = 200;	

    //メニュー画面の描画
    DrawExtendGraph(MenuX, MenuY, MenuX + 400, MenuY + 400,g_pic.Menu,TRUE);
    DrawRotaGraph(MenuX + 200, GAME_Y, 0.3, 0, g_pic.MenuChar[0], TRUE, FALSE);
    DrawRotaGraph(MenuX + 200, RESET_Y, 0.3, 0, g_pic.MenuChar[1], TRUE, FALSE);
    DrawRotaGraph(MenuX + 200, END_Y, 0.3, 0, g_pic.MenuChar[2], TRUE, FALSE);
    DrawExtendGraph(500, 250, 756, 378, g_pic.MenuBotan, TRUE);

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
    DrawRotaGraph(MenuX + 90, y, 1.0, 0, g_pic.Pin, TRUE, TRUE);
}