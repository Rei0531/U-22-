#pragma once
#include "DxLib.h"
#include "Controller.h"
#include "constant.h"
#include "Player.h"

extern Controller g_Pad;
extern Player g_Player;
extern int GameState;

const static int SELECT_Y = 430;    //「ステージセレクト」文字のy位置
const static int THANKS_Y = 480;    //「スペシャルサンクス」文字のy位置
const static int END_Y = 530;    //「終了」文字のy位置

typedef enum {
    eTitle_Select,       //ステージセレクト
    eTitle_SpecialThanks,    //スペシャルサンクス
    eTitle_End,      //終了

    eTitle_Num,        //本項目の数
} eTitle;

static int NowSelect = eTitle_Select;    //現在の選択状態(初期はゲーム選択中)


void Title_Update();
void Title_Draw();

int GameTitle(void);