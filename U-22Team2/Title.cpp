#include "DxLib.h"
#include "Controller.h"
#include "LoadPic.h"
#include "constant.h"
#include "Title.h"
#include "LoadSound.h"
#include "Color.h"


extern Sound g_Snd;

static bool //二度押し防止
DOWN = FALSE,//下キー
UP = FALSE,//上キー
B = FALSE;//Bボタン

int ColorMove = 0;//スポイトするたび色が変わる変数
int CircleRcnt = 0;//円の半径のカウント
int CircleRcnt2 = -200;//円の半径のカウント2
int CircleRcntMax = 1100;//円の半径のカウント

static bool Sndflg = FALSE;//音再生フラグ
extern image g_pic;
extern Controller g_Pad;

void Title_Update() {

    if (CheckSoundMem(g_Snd.MenuOpen) == 0 && Sndflg == FALSE) {
        PlaySoundMem(g_Snd.MenuOpen, DX_PLAYTYPE_BACK);
        Sndflg = TRUE;//音再生フラグをTRUEにして二度再生防止
    }

    if (g_Pad.KEY_DOWN == TRUE && DOWN == FALSE) {//下キーが押されていたら
        DOWN = TRUE;
        NowSelect = (NowSelect + 1) % eTitle_Num;//選択状態を一つ下げる
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
        ColorMove++;
    }
    if (g_Pad.KEY_UP == TRUE && UP == FALSE) {//上キーが押されていたら
        UP = TRUE;
        NowSelect = (NowSelect + (eTitle_Num - 1)) % eTitle_Num;//選択状態を一つ上げる
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
        ColorMove++;
    }


    DOWN = (g_Pad.KEY_DOWN == TRUE) ? TRUE : FALSE;//下キーが押されていたら

    UP = (g_Pad.KEY_UP == TRUE) ? TRUE : FALSE;//上キーが押されていたら

    if (g_Pad.KEY_B == TRUE && B == FALSE) {//Bボタンが押されたら
        B = TRUE;//再度ボタンが押せる
        Sndflg = FALSE;//メニューオープンのフラグをFALSEにして再度関数に入った時音が鳴るようにする
        switch (NowSelect) {//現在選択中の状態によって処理を分岐
        case eTitle_Select://セレクト選択中なら
            //本来はここにセレクト画面以降処理
            GameState = GAME_MENU;//セレクト画面から行きたい
            break;
        case eTitle_SpecialThanks://スペシャルサンクス選択中なら
            GameState = GAME_MAIN;
            break;
        case eTitle_End:
            DxLib_End();//終了処理
            break;

        }
    }

    B = (g_Pad.KEY_B == TRUE) ? TRUE : FALSE;//Bボタンが押されていたら/再度Bボタンが押せるように
}
void Title_Draw() {
    //拡大していく円**********************************************
    CircleRcnt = CircleRcntMax > CircleRcnt ? CircleRcnt += 5 : CircleRcnt = 0;
    CircleRcnt2 = CircleRcntMax > CircleRcnt2 ? CircleRcnt2 += 5 : CircleRcnt2 = 0;

    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);//描画ブレンドモードをアルファブレンドにする
    Change(ColorMove % 7);//タイトル画面を動かすごとに色が変わる
    DrawCircle(SCREEN_WIDHT / 2, SCREEN_HEIGHT / 2, CircleRcnt, 0xffffff, TRUE, TRUE);
    Change(WHITE);//イトル画面を動かすごとに色が変わる
    DrawCircle(SCREEN_WIDHT / 2, SCREEN_HEIGHT / 2, CircleRcnt2, 0xffffff, TRUE, TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);	//描画ブレンドモードをノーブレンドにする
    ColorReset();
    //***********************************************************
    static int MenuX = 634, MenuY = 200;
    static int BoxX = 0;//選択カーソルのプラスする量の位置;
    DrawRotaGraph(MenuX, SELECT_Y,0.5,0,g_pic.TitleChar[0],TRUE,FALSE);
    DrawRotaGraph(MenuX, THANKS_Y, 0.5, 0, g_pic.TitleChar[1], TRUE, FALSE);
    DrawRotaGraph(MenuX, END_Y, 0.5, 0, g_pic.TitleChar[2], TRUE, FALSE);
    int y = 0;
    switch (NowSelect) {//現在の選択状態に従って処理を分岐
    case eTitle_Select://セレクト選択中なら
        y = SELECT_Y;    //セレクトの座標を格納
        BoxX = -175;
        break;
    case eTitle_SpecialThanks://リセット選択中なら
        y = THANKS_Y;    //スペシャルサンクスの座標を格納
        BoxX = -210;
        break;
    case eTitle_End://終了選択中なら
        y = END_Y;      //終了の座標を格納
        BoxX = -70;
    }

    DrawRotaGraph(MenuX + BoxX, y - 5,1.0,0,g_pic.Pin,TRUE,TRUE);//スポイトのやつ


    //タイトル名の表示*****************************************************

    //タイトル名の表示
    for (int i = 0; i < 13; i++) {
        Change((i + ColorMove) % 7);//動かすたびに色が変わる
        DrawRotaGraph(60 + i * 95, 150, 0.8, 0, g_pic.TitleName[i], TRUE, FALSE);
    }
    ColorReset();
    //**********************************************
}

int GameTitle(void) {
    DrawBox(0,0, SCREEN_WIDHT, SCREEN_HEIGHT,0xffffff,TRUE);//白い背景
	//DrawRotaGraph(SCREEN_WIDHT / 2, SCREEN_HEIGHT / 2, 1.0, 0,g_pic.Title, TRUE, FALSE); //タイトル画像描画
    Title_Update();
    Title_Draw();
	return 0;
}