#include "DxLib.h"
#include "Controller.h"
#include "constant.h"
#include "Player.h"

extern Controller g_Pad;
extern Player g_Player;
extern int GameState;

const static int BACK_X = 320;    //「前ステージ」文字のx位置
const static int SELECT_X = BACK_X * 2;    //「ステージセレクト」文字のx位置
const static int NEXT_X = BACK_X * 3;    //「次ステージ」文字のx位置

typedef enum {
    eGoal_Next,    //次ステージ
    eGoal_Select,      //ステージセレクト
    eGoal_Back,    //前ステージ

    eGoal_Num,        //本項目の数
} eGoal;

static int NowSelect = eGoal_Next;    //現在の選択状態(初期はゲーム選択中)


void Goal_Update();
void Goal_Draw();

