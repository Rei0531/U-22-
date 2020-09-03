#pragma once
#include "DxLib.h"
#include "Controller.h"
#include "constant.h"
#include "Player.h"

extern Controller g_Pad;
extern Player g_Player;
extern int GameState;

//const static int SELECT_Y = 430;    //「ステージセレクト」文字のy位置
//const static int THANKS_Y = 480;    //「スペシャルサンクス」文字のy位置
//const static int END_Y = 530;    //「終了」文字のy位置

typedef enum {
    Stage_1,
    Stage_2,
    Stage_3,
    Stage_4,
    Stage_5,
    Stage_6,
    Stage_7,
    Stage_8,
    Stage_9,
    Stage_10,
    Stage_11,
    Stage_12,
    Stage_13,
    Stage_14,
    Stage_15,
    Stage_16,
    Stage_17,
    Stage_18,
    Stage_19,
    Stage_20,
    Stage_21,
    Stage_22,
    Stage_23,
    Stage_24,
    Stage_25,
    //Stage_26,
    //Stage_27,
    //Stage_28,
    //Stage_29,
    //Stage_30,

    Stage_Num,        //本項目の数
} Stageselect;


static int NowStage = Stage_1;    //現在の選択状態(初期はゲーム選択中)

int StageSelect();
void Stage_Update();
void Stage_Draw();
