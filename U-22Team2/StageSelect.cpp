#include "DxLib.h"
#include "Controller.h"
#include "LoadPic.h"
#include "constant.h"
#include "Title.h"
#include "LoadSound.h"
#include "StageSelect.h"
#include "Map.h"
#include "Color.h"
#include "Color.h"


extern Sound g_Snd;
static bool Sndflg = FALSE;//音再生フラグ
extern image g_pic;
extern Controller g_Pad;
extern MapCoordinate g_MapC;

extern bool ClearStage[30];


bool //二度押し防止
DOWN = FALSE,//下キー
UP = FALSE,//上キー
LEFT = FALSE,//左キー
RIGHT = FALSE,//右キー
B = TRUE,//Bボタン
A = FALSE,//Aボタン
Y = FALSE;//Yボタン

void Stage_Decision(void);		//ステージセレクト決定演出

int HtPflg = 1;
int stage_decision_flg = 0;	//ステージセレクト決定フラグ
int anicount = 0;			//演出の時間関係の変数

static int ColorMove = 0;//スポイトするたび色が変わる変数
static int CircleRcnt = 0;//円の半径のカウント
static int CircleRcnt2 = -200;//円の半径のカウント2
static int CircleRcntMax = 1100;//円の半径のカウント

void Stage_Update() {

    //if (CheckSoundMem(g_Snd.MenuOpen) == 0 && Sndflg == FALSE) {
    //    PlaySoundMem(g_Snd.MenuOpen, DX_PLAYTYPE_BACK);
    //    Sndflg = TRUE;//音再生フラグをTRUEにして二度再生防止
    //}

    if (g_Pad.KEY_RIGHT == TRUE && RIGHT == FALSE && HtPflg > 0) HtPflg++;  //ウィンドウを開いてる時に→で次のページへ
    if (g_Pad.KEY_LEFT == TRUE && LEFT == FALSE && HtPflg > 1) HtPflg--;    //ウィンドウを開いてる時に←で前のページへ

    if (HtPflg > 7) HtPflg = 0;     //７ページ目で閉じる

    if (HtPflg == 0) {//ウィンドウが開いてない時に移動可能

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
    }


    DOWN = (g_Pad.KEY_DOWN == TRUE) ? TRUE : FALSE;//下キーが押されていたら

    UP = (g_Pad.KEY_UP == TRUE) ? TRUE : FALSE;//上キーが押されていたら

    LEFT = (g_Pad.KEY_LEFT == TRUE) ? TRUE : FALSE;//左キーが押されていたら

    RIGHT = (g_Pad.KEY_RIGHT == TRUE) ? TRUE : FALSE;//右キーが押されていたら

    if (g_Pad.KEY_Y == TRUE && Y == FALSE && HtPflg == 0) {//スタートボタンを押すとウィンドウを開く
        Y = TRUE;
        HtPflg = 1;
    }

    if (g_Pad.KEY_Y == TRUE && Y == FALSE && HtPflg > 0) {//開いている時に押すと閉じる
        Y = TRUE;
        HtPflg = 0;
    }

    Y = (g_Pad.KEY_Y == TRUE) ? TRUE : FALSE;//リーダーのパクり

    if (HtPflg == 0) {//ウィンドウ開いていないなら
        if (g_Pad.KEY_B == true && B == false) {//Bボタンが押されたら
            B = TRUE;//再度ボタンが押せる
            Sndflg = FALSE;//メニューオープンのフラグをFALSEにして再度関数に入った時音が鳴るようにする
            g_MapC.StageNumber = NowStage + 1;
            //GameState = GAME_MAIN;

            //ステージセレクト決定音
            PlaySoundMem(g_Snd.Menu_decision, DX_PLAYTYPE_BACK);
            stage_decision_flg = 1;

        }

        B = (g_Pad.KEY_B == TRUE) ? TRUE : FALSE;//Bボタンが押されていたら/再度Bボタンが押せるように

        if (g_Pad.KEY_A == TRUE && A == FALSE) {//Aボタンが押されたら
            GameState = GAME_TITLE;
            A = TRUE;//再度ボタンが押せる
            B = TRUE;//Bボタン
        }
        A = (g_Pad.KEY_A == TRUE) ? TRUE : FALSE;//Aボタンが押されていたら/再度Aボタンが押せるように

    }
}
void Stage_Draw() {
    static int MenuX = 634, MenuY = 200;
    static double anicnt = 0.05;//回転カウント
    static double anicntMax = 5.0;//回転カウント最大値
    static double anicnt2 = anicntMax;//逆回転カウント
    static int FreamCnt = 0;
    static int BoxX = 0;//選択カーソルのプラスする量の位置;
    static int Color = 9;//色チェンジ用一時変数
    int cnt = 0;
    int
        x = NowStage % 5,
        y = NowStage / 5;


    anicnt += 0.05; 
    anicnt2 -= 0.1;

    if (anicnt > anicntMax) {
        anicnt = 0.05;
    }
    if (anicnt2 < 0.0) {
        anicnt2 = anicntMax;
    }

    //拡大していく円**********************************************
    if (stage_decision_flg == 0) {
        static int
            CircleX = SCREEN_WIDHT / 2,
            CircleY = SCREEN_HEIGHT / 2;
        CircleRcnt = CircleRcntMax > CircleRcnt ? CircleRcnt += 5 : CircleRcnt = 0;
        CircleRcnt2 = CircleRcntMax > CircleRcnt2 ? CircleRcnt2 += 5 : CircleRcnt2 = 0;

        if (CircleRcnt == 0) {
            ColorMove++;
            CircleX = GetRand(SCREEN_WIDHT);
            CircleY = GetRand(SCREEN_HEIGHT);
        }

        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);//描画ブレンドモードをアルファブレンドにする
        Change(ColorMove % 7);//セレクト画面を動かすごとに色が変わる
        DrawCircle(CircleX, CircleY, CircleRcnt, 0xffffff, TRUE, TRUE);
        Change(WHITE);//セレクト画面を動かすごとに色が変わる
        DrawCircle(CircleX, CircleY, CircleRcnt2, 0xffffff, TRUE, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);	//描画ブレンドモードをノーブレンドにする
        ColorReset();
    }
    //***********************************************************

    //static int r = 0, g = 0, b = 0;
    //if (FreamCnt % 60 == 0) {
    //    r = GetRand(255);
    //    g = GetRand(255);
    //    b = GetRand(255);
    //}

    if (FreamCnt++ % 60 == 0)
        Color = GetRand(6);

    Change(Color);
    DrawRotaGraph(268 + x * 168, 76 + y * 156, 1.2, anicnt* anicnt2, g_pic.WhiteBox, TRUE, FALSE);//回転する箱
    ColorReset();

    int c = 0;
    //ステージのびょうが　
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            DrawBox(218 + j * 168, 26 + i * 156, 318 + j * 168, 126 + i * 156, 0xffffff, TRUE);//白い四角
            DrawBox(218 + j * 168, 26 + i * 156, 318 + j * 168, 126 + i * 156, 0x000000 , FALSE);//枠線
            DrawRotaGraph(268 + j * 168, 76 + i * 156,0.5,0, g_pic.StageNum[cnt++ % Stage_Num],TRUE,FALSE);
            //クリアしたステージのクリア画像表示
            if (ClearStage[c++] == TRUE)
                DrawRotaGraph(268 + j * 168, 76 + i * 156, 1.0, 0, g_pic.SelectClear, TRUE, FALSE);
        }
    }

    //ステージセレクトの大きなる表示
    DrawExtendGraph(218 + x * 168, 26 + y * 156, 318 + x * 168, 126 + y * 156, g_pic.StageNum[NowStage], TRUE);

   // DrawRotaGraph(SCREEN_WIDHT/2, SCREEN_HEIGHT - 50,0.5,0,g_pic.Select_Txt,TRUE,FALSE);// ステージを選んでください
    DrawRotaGraph(100, SCREEN_HEIGHT/2, 0.7, 0, g_pic.Select_Char, TRUE, FALSE);// ステージを選んでください

}

int StageSelect(void) {
    //DrawRotaGraph(SCREEN_WIDHT / 2, SCREEN_HEIGHT / 2, 1.0, 0, g_pic.Title, TRUE, FALSE); //タイトル画像描画
  
    DrawBox(0,0,1280,768,0xffffff,TRUE);//白い背景
    if (stage_decision_flg == 0) {
        Stage_Update();
    }
    Stage_Draw();
    Stage_Decision();

    if (HtPflg > 0) DrawExtendGraph(235, 90, 1045, 678, g_pic.How_to_play_background, TRUE);   //背景サイズ X=610 Y=776



    switch(HtPflg) {//ウィンドウページ

        case 1://１ページ目
            DrawRotaGraph(680, 384, 1.2, 0, g_pic.asobikata, TRUE, FALSE);
            DrawRotaGraph(800, 550, 1.0, 0, g_pic.NextPage, TRUE);
            DrawFormatString(600, 200, GetColor(0,0,0), "１/ ７ページ");
            break;
        case 2://２ページ目
            DrawRotaGraph(480, 384, 0.8, 0, g_pic.Tutorial_pic[0], TRUE, FALSE);
            DrawRotaGraph(830, 384, 0.8, 0, g_pic.Tutorial_pic[1], TRUE, FALSE);
            DrawRotaGraph(480, 250, 1.0, 0, g_pic.Tutorial_text[0], TRUE);
            DrawRotaGraph(830, 250, 1.0, 0, g_pic.Tutorial_text[1], TRUE);
            DrawRotaGraph(655, 384, 0.5, 0, g_pic.yazirusi, TRUE,TRUE);
            DrawRotaGraph(600, 555, 1.0, 0, g_pic.BackPage, TRUE);
            DrawRotaGraph(800, 550, 1.0, 0, g_pic.NextPage, TRUE);
            DrawFormatString(600, 200, GetColor(0, 0, 0), "２/ ７ページ");
            break;
        case 3://３ページ目
            DrawRotaGraph(480, 384, 0.8, 0, g_pic.Tutorial_pic[2], TRUE, FALSE);
            DrawRotaGraph(830, 384, 0.8, 0, g_pic.Tutorial_pic[3], TRUE, FALSE);
            DrawRotaGraph(500, 250, 1.0, 0, g_pic.Tutorial_text[2], TRUE);
            DrawRotaGraph(830, 250, 1.0, 0, g_pic.Tutorial_text[3], TRUE);
            DrawRotaGraph(655, 384, 0.5, 0, g_pic.yazirusi, TRUE, TRUE);
            DrawRotaGraph(600, 555, 1.0, 0, g_pic.BackPage, TRUE);
            DrawRotaGraph(800, 550, 1.0, 0, g_pic.NextPage, TRUE);
            DrawFormatString(600, 200, GetColor(0, 0, 0), "３/ ７ページ");
            break;
        case 4:
            DrawRotaGraph(480, 384, 0.8, 0, g_pic.Tutorial_pic[4], TRUE, FALSE);
            DrawRotaGraph(830, 304, 0.4, 0, g_pic.Tutorial_pic[5], TRUE, FALSE);
            DrawRotaGraph(830, 474, 0.4, 0, g_pic.Tutorial_pic[6], TRUE, FALSE);
            DrawRotaGraph(500, 250, 1.0, 0, g_pic.Tutorial_text[4], TRUE);
            DrawRotaGraph(830, 400, 1.0, 0, g_pic.Tutorial_text[5], TRUE);
            DrawRotaGraph(655, 384, 0.5, 0, g_pic.yazirusi, TRUE, TRUE);
            DrawRotaGraph(600, 555, 1.0, 0, g_pic.BackPage, TRUE);
            DrawRotaGraph(800, 550, 1.0, 0, g_pic.NextPage, TRUE);
            DrawFormatString(600, 200, GetColor(0, 0, 0), "４/ ７ページ");
            break;
        case 5:
            DrawRotaGraph(480, 424, 0.8, 0, g_pic.Tutorial_pic[7], TRUE, FALSE);
            DrawRotaGraph(830, 364, 0.2, 0, g_pic.StageClear, TRUE, FALSE);
            DrawRotaGraph(500, 280, 1.0, 0, g_pic.Tutorial_text[6], TRUE);
            DrawRotaGraph(830, 250, 1.0, 0, g_pic.Tutorial_text[7], TRUE);
            DrawRotaGraph(655, 384, 0.5, 0, g_pic.yazirusi, TRUE, TRUE);
            DrawRotaGraph(600, 555, 1.0, 0, g_pic.BackPage, TRUE);
            DrawRotaGraph(800, 550, 1.0, 0, g_pic.NextPage, TRUE);
            DrawFormatString(600, 200, GetColor(0, 0, 0), "５/ ７ページ");
            break;
        case 6:
            DrawRotaGraph(480, 384, 0.8, 0, g_pic.Tutorial_pic[8], TRUE, FALSE);
            DrawRotaGraph(830, 384, 0.8, 0, g_pic.Tutorial_pic[9], TRUE, FALSE);
            DrawRotaGraph(520, 250, 1.0, 0, g_pic.Tutorial_text[8], TRUE);
            DrawRotaGraph(830, 250, 1.0, 0, g_pic.Tutorial_text[9], TRUE);
            DrawRotaGraph(655, 384, 0.5, 0, g_pic.yazirusi, TRUE, TRUE);
            DrawRotaGraph(600, 555, 1.0, 0, g_pic.BackPage, TRUE);
            DrawRotaGraph(800, 550, 1.0, 0, g_pic.NextPage, TRUE);
            DrawFormatString(600, 200, GetColor(0, 0, 0), "６/ ７ページ");
            break;
        case 7:
            DrawRotaGraph(480, 404, 0.8, 0, g_pic.Tutorial_pic[10], TRUE, FALSE);
            DrawRotaGraph(830, 404, 0.8, 0, g_pic.Tutorial_pic[11], TRUE, FALSE);
            DrawRotaGraph(500, 270, 1.0, 0, g_pic.Tutorial_text[10], TRUE);
            DrawRotaGraph(830, 250, 1.0, 0, g_pic.Tutorial_text[11], TRUE);
            DrawRotaGraph(655, 384, 0.5, 0, g_pic.yazirusi, TRUE, TRUE);
            DrawRotaGraph(600, 555, 1.0, 0, g_pic.BackPage, TRUE);
            DrawRotaGraph(800, 550, 1.0, 0, g_pic.EndPage, TRUE);
            DrawFormatString(600, 200, GetColor(0, 0, 0), "７/ ７ページ");
            break;
       // case 4://４ページ目
            //DrawRotaGraph(640, 384, 1.0, 0, g_pic.How_to_play[3], TRUE, FALSE);
            //DrawRotaGraph(750, 600, 1.0, 0, g_pic.EndPage, TRUE);
            //break;
    }

    DrawFormatString(1080, 50, GetColor(0,0,0),"STARTボタンでゲーム説明");
    return 0;
}

void Stage_Decision(void) {

    if (stage_decision_flg == 1) {
        anicount += 20;
        SetDrawBlendMode(DX_BLENDMODE_ADD, anicount);

        if (anicount >= 255)stage_decision_flg = 3;

    }
    else if (stage_decision_flg == 3) {	//演出が終わったらゲームメインへ
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        stage_decision_flg = 0;
        anicount = 0;
        B = TRUE;
        GameState = GAME_MAIN;
    }

}