#include "DxLib.h"
#include "Controller.h"
#include "LoadPic.h"
#include "constant.h"
#include "Title.h"
#include "LoadSound.h"
#include "StageSelect.h"
#include "Map.h"


extern Sound g_Snd;
static bool Sndflg = FALSE;//音再生フラグ
extern image g_pic;
extern Controller g_Pad;
extern MapCoordinate g_MapC;

void Stage_Update() {

    static bool //二度押し防止
        DOWN = FALSE,//下キー
        UP = FALSE,//上キー
        LEFT = FALSE,//左キー
        RIGHT = FALSE,//右キー
        B = TRUE;//Bボタン

    //if (CheckSoundMem(g_Snd.MenuOpen) == 0 && Sndflg == FALSE) {
    //    PlaySoundMem(g_Snd.MenuOpen, DX_PLAYTYPE_BACK);
    //    Sndflg = TRUE;//音再生フラグをTRUEにして二度再生防止
    //}

    if (g_Pad.KEY_DOWN == TRUE && DOWN == FALSE) {//下キーが押されていたら
        DOWN = TRUE;
        NowStage = (NowStage + 6) % Stage_Num;//選択状態を一つ下げる
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
    }
    if (g_Pad.KEY_UP == TRUE && UP == FALSE) {//上キーが押されていたら
        UP = TRUE;
        NowStage = (NowStage + (Stage_Num - 6)) % Stage_Num;//選択状態を一つ上げる
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
    }
    if (g_Pad.KEY_LEFT == TRUE && LEFT == FALSE) {//下キーが押されていたら
        LEFT = TRUE;
        NowStage = (NowStage + (Stage_Num - 1)) % Stage_Num;//選択状態を一つ上げる
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
    }
    if (g_Pad.KEY_RIGHT == TRUE && RIGHT == FALSE) {//上キーが押されていたら
        RIGHT = TRUE;
        NowStage = (NowStage + 1) % Stage_Num;//選択状態を一つ下げる
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
    }


    DOWN = (g_Pad.KEY_DOWN == TRUE) ? TRUE : FALSE;//下キーが押されていたら

    UP = (g_Pad.KEY_UP == TRUE) ? TRUE : FALSE;//上キーが押されていたら

    LEFT = (g_Pad.KEY_LEFT == TRUE) ? TRUE : FALSE;//左キーが押されていたら

    RIGHT = (g_Pad.KEY_RIGHT == TRUE) ? TRUE : FALSE;//右キーが押されていたら


    if (g_Pad.KEY_B == TRUE && B == FALSE) {//Bボタンが押されたら
        B = TRUE;//再度ボタンが押せる
        Sndflg = FALSE;//メニューオープンのフラグをFALSEにして再度関数に入った時音が鳴るようにする
        g_MapC.StageNumber = NowStage+1;
        GameState = GAME_MAIN;
        //switch (NowStage) {//現在選択中の状態によって処理を分岐
        ////case eTitle_Select://セレクト選択中なら
        ////    //本来はここにセレクト画面以降処理
        ////    GameState = GAME_MAIN;//セレクト画面から行きたい
        ////    break;
        ////case eTitle_SpecialThanks://スペシャルサンクス選択中なら
        ////    GameState = GAME_MAIN;
        ////    break;
        ////case eTitle_End:
        ////    DxLib_End();//終了処理
        ////    break;

        //}
    }

    B = (g_Pad.KEY_B == TRUE) ? TRUE : FALSE;//Bボタンが押されていたら/再度Bボタンが押せるように

}
void Stage_Draw() {
    static int MenuX = 634, MenuY = 200;
    static int BoxX = 0;//選択カーソルのプラスする量の位置;
    //DrawRotaGraph(MenuX, SELECT_Y, 0.5, 0, g_pic.TitleChar[0], TRUE, FALSE);
    //DrawRotaGraph(MenuX, THANKS_Y, 0.5, 0, g_pic.TitleChar[1], TRUE, FALSE);
    //DrawRotaGraph(MenuX, END_Y, 0.5, 0, g_pic.TitleChar[2], TRUE, FALSE);
    //ステージのびょうが　
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            DrawBox(168 + j * 168,26 + i * 156,268 + j * 168,126 + i * 156,0xff0000,TRUE);
        }
    }
    //switch (NowStage) {//現在の選択状態に従って処理を分岐
    //case eTitle_Select://セレクト選択中なら
    //    //y = SELECT_Y;    //セレクトの座標を格納
    //    BoxX = -175;
    //    break;
    //case eTitle_SpecialThanks://リセット選択中なら
    //   // y = THANKS_Y;    //スペシャルサンクスの座標を格納
    //    BoxX = -210;
    //    break;
    //case eTitle_End://終了選択中なら
    //    //y = END_Y;      //終了の座標を格納
    //    BoxX = -70;
    //}

    DrawFormatString(0, 100, 0xff0fff, "NowStage %d ", NowStage+1);
    int
        x = NowStage%6,
        y = NowStage/6;
    DrawBox(168 + x * 168, 26 + y * 156, 268 + x * 168, 126 + y * 156, 0x0000ff, TRUE);
   // DrawRotaGraph(168 +  NowStage * 168 + BoxX, y - 5, 1.0, 0, g_pic.Pin, TRUE, TRUE);
    //DrawBox(168 + j * 168, 156 + i * 156, 268 + j * 168, 256 + i * 156, 0x0000ff, FALSE);
}

int StageSelect(void) {
    //DrawRotaGraph(SCREEN_WIDHT / 2, SCREEN_HEIGHT / 2, 1.0, 0, g_pic.Title, TRUE, FALSE); //タイトル画像描画
    DrawBox(0,0,1280,768,0xffffff,TRUE);//白い背景
    Stage_Update();
    Stage_Draw();
    return 0;
}