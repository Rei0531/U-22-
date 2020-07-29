#include "DxLib.h"
#include "Controller.h"
#include "constant.h"
#include "Player.h"

extern Controller g_Pad;
extern Player g_Player;
extern int GameState;

const static int GAME_Y = 450;    //「ゲーム」文字のy位置
const static int RESET_Y = 480;    //「リセット」文字のy位置
const static int END_Y = 510;    //「終了」文字のy位置

typedef enum {
    eMenu_Select,       //ステージセレクト
    eMenu_Reset,    //リセット
    eMenu_End,      //終了

    eMenu_Num,        //本項目の数
} eMenu;

static int NowSelect = eMenu_End;    //現在の選択状態(初期はゲーム選択中)


bool Menu_Update();
void Menu_Draw();
