#include "Stage_All.h"
#include "Map.h"
#include "Player.h"
#include "LoadPic.h"
#include "Controller.h"
#include"Lock.h"
#include "Goal.h"
#include "LoadSound.h"
#include "Color.h"

extern Player g_Player;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern Controller g_Pad;
extern LockALL g_Lock;
extern Sound g_Snd;
extern image g_pic;


static bool LEFT = FALSE,//左キー
RIGHT = FALSE,//右キー
B = TRUE;//Bボタン

static bool Sndflg = FALSE;//音再生フラグ


int Goal(void) {

	Goal_Update();
	Goal_Draw();

	ControllerVlue();

    //if (g_MapC.StageNumber >= 25) {
    //    if (g_Pad.KEY_B == TRUE && B == FALSE) {
    //        g_MapC.StageNumber = 1;
    //        GameState = GAME_TITLE;
    //        g_Lock.clearflg = FALSE;
    //    }
    //}
    //else {
    //    if (g_Pad.KEY_B == TRUE && B == FALSE) {
    //        g_MapC.StageNumber += 1;
    //        GameState = GAME_MAIN;
    //        g_Lock.clearflg = FALSE;
    //    }
    //}

    //B = (g_Pad.KEY_B == TRUE) ? TRUE : FALSE;//Bボタンが押されていたら/再度Bボタンが押せるように


	return 0;

}


//更新
void Goal_Update() {

    if (CheckSoundMem(g_Snd.MenuOpen) == 0 && Sndflg == FALSE) {
        PlaySoundMem(g_Snd.MenuOpen, DX_PLAYTYPE_BACK);
        Sndflg = TRUE;//音再生フラグをTRUEにして二度再生防止
    }

    if (g_Pad.KEY_LEFT == TRUE && LEFT == FALSE) {//左キーが押されていたら
        LEFT = TRUE;
        NowSelect = (NowSelect + 1) % eGoal_Num;//選択状態を一つ下げる
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
    }
    if (g_Pad.KEY_RIGHT == TRUE && RIGHT == FALSE) {//右キーが押されていたら
        RIGHT = TRUE;
        NowSelect = (NowSelect + (eGoal_Num - 1)) % eGoal_Num;//選択状態を一つ上げる
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
    }

    LEFT = (g_Pad.KEY_LEFT == TRUE) ? TRUE : FALSE;//左キーが押されていたら

    RIGHT = (g_Pad.KEY_RIGHT == TRUE) ? TRUE : FALSE;//右キーが押されていたら

    if (g_Pad.KEY_B == TRUE && B == FALSE) {//Bボタンが押されたら
        Sndflg = FALSE;//メニューオープンのフラグをFALSEにして再度関数に入った時音が鳴るようにする
        switch (NowSelect) {//現在選択中の状態によって処理を分岐
        case eGoal_Next://次ステージ選択中なら
            //本来はここにセレクト画面以降処理
            if (g_MapC.StageNumber >= 25) {
                if (g_Pad.KEY_B == TRUE && B == FALSE) {
                    g_MapC.StageNumber = 1;
                    GameState = GAME_TITLE;
                    g_Lock.clearflg = FALSE;
                }
            }
            else {
                if (g_Pad.KEY_B == TRUE && B == FALSE) {
                    g_MapC.StageNumber += 1;
                    GameState = GAME_MAIN;
                    g_Lock.clearflg = FALSE;
                    PlaySoundMem(g_Snd.Menu_decision, DX_PLAYTYPE_BACK);
                }
            }
            break;
        case eGoal_Back://前ステージ選択中なら
            if (g_MapC.StageNumber <= 1) {
                if (g_Pad.KEY_B == TRUE && B == FALSE) {
                    GameState = GAME_TITLE;
                    g_Lock.clearflg = FALSE;
                }
            }
            else {
                if (g_Pad.KEY_B == TRUE && B == FALSE) {
                    g_MapC.StageNumber -= 1;
                    GameState = GAME_MAIN;
                    g_Lock.clearflg = FALSE;
                    PlaySoundMem(g_Snd.Menu_decision, DX_PLAYTYPE_BACK);
                }
            }
            break;
        case eGoal_Select://ステージセレクト選択中だったら
            GameState = GAME_TITLE;
            g_Lock.clearflg = FALSE;
            break;

        }
    }

    B = (g_Pad.KEY_B == TRUE) ? TRUE : FALSE;//Bボタンが押されていたら/再度Bボタンが押せるように
}

//描画
void Goal_Draw() {

    static int MenuY = 600;

    ColorReset();
    //クリア画面の描画
    DrawRotaGraph(SCREEN_WIDHT / 2, SCREEN_HEIGHT / 2, 1.0, 0, g_pic.StageClear, TRUE, FALSE); //クリア画像描画
    DrawRotaGraph(NEXT_X, MenuY+7, 0.2, 0, g_pic.GoalTxt[0], TRUE, FALSE);
    DrawRotaGraph(BACK_X, MenuY, 0.2, 0, g_pic.GoalTxt[1], TRUE, FALSE);
    DrawRotaGraph(SELECT_X, MenuY, 0.2, 0, g_pic.GoalTxt[2], TRUE, FALSE);

    int x = 0;
    switch (NowSelect) {//現在の選択状態に従って処理を分岐
    case eGoal_Next://セレクト選択中なら
        x = NEXT_X;    //セレクトの座標を格納
        break;
    case eGoal_Back://リセット選択中なら
        x = BACK_X;    //リセットの座標を格納
        break;
    case eGoal_Select://終了選択中なら
        x = SELECT_X;      //終了の座標を格納
    }
    DrawRotaGraph(x-128, MenuY, 1.0, 0, g_pic.Pin, TRUE, TRUE);
}