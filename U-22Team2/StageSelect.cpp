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
        NowStage = (NowStage + 5) % Stage_Num;//選択状態を5つ下げる
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
    }
    if (g_Pad.KEY_UP == TRUE && UP == FALSE) {//上キーが押されていたら
        UP = TRUE;
        NowStage = (NowStage + (Stage_Num - 5)) % Stage_Num;//選択状態を5つ上げる
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
    }

    B = (g_Pad.KEY_B == TRUE) ? TRUE : FALSE;//Bボタンが押されていたら/再度Bボタンが押せるように

}
void Stage_Draw() {
    static int MenuX = 634, MenuY = 200;
    static double anicnt = 0;//虹色光回転カウント
    static int FreamCnt = 0;
    static int BoxX = 0;//選択カーソルのプラスする量の位置;
    int cnt = 0;
    int
        x = NowStage % 5,
        y = NowStage / 5;

    anicnt += 0.02;//虹色の光回転

    //static int r = 0, g = 0, b = 0;
    //if (FreamCnt % 60 == 0) {
    //    r = GetRand(255);
    //    g = GetRand(255);
    //    b = GetRand(255);
    //}

    DrawRotaGraph(268 + x * 168, 76 + y * 156, 1.5, anicnt, g_pic.Select_Back, TRUE, FALSE);//虹色の背景

    //ステージのびょうが　
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            DrawBox(218 + j * 168, 26 + i * 156, 318 + j * 168, 126 + i * 156, 0xffffff, TRUE);//白い四角
            DrawBox(218 + j * 168, 26 + i * 156, 318 + j * 168, 126 + i * 156, 0x000000 , FALSE);//枠線
            DrawRotaGraph(268 + j * 168, 76 + i * 156,0.5,0, g_pic.StageNum[cnt++ % Stage_Num],TRUE,FALSE);
        }
    }

    //ステージセレクトの大きなる表示
    DrawExtendGraph(218 + x * 168, 26 + y * 156, 318 + x * 168, 126 + y * 156, g_pic.StageNum[NowStage], TRUE);
}

int StageSelect(void) {
    //DrawRotaGraph(SCREEN_WIDHT / 2, SCREEN_HEIGHT / 2, 1.0, 0, g_pic.Title, TRUE, FALSE); //タイトル画像描画
    DrawBox(0,0,1280,768,0xffffff,TRUE);//白い背景
    Stage_Update();
    Stage_Draw();
    return 0;
}