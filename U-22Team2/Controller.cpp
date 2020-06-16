#include "Controller.h"
#include "Map.h"
#include "constant.h"


//int PadInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
extern Controller g_Pad;
//MapCoordinate MapC;

void ControllerVlue(void) {         //プレイヤーの移動処理関数
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) != 0 && g_MapC.X1 < 0)    //画面左側制限
    {
        g_MapC.X1 += PLAYERX;
        g_MapC.X2 += PLAYERX;
        g_Pad.KEY_LEFT = TRUE;
    }
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT) != 0 && g_MapC.X2 > SCREEN_WIDHT)    //画面右側制限
    {
        g_MapC.X1 -= PLAYERX;
        g_MapC.X2 -= PLAYERX;
        g_Pad.KEY_RIGHT = TRUE;
    }
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B) != 0)//Bボタン    //ジャンプ処理
    {
        DrawString(100,100,"ジャンプしました",0x00ff00);
        g_Pad.KEY_B = TRUE;
    }
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A) != 0 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN) != 0)//Aボタン    //ジャンプ処理
    {
        DrawString(100, 100, "しゃがみました", 0x00ff00);
        //しゃがみ
        g_Pad.KEY_A = TRUE;
    }
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_3) != 0)//Xボタン    //アクション処理
    {
        DrawString(100, 100, "アクション", 0x00ff00);
        //アクション
        g_Pad.KEY_X = TRUE;
    }
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_6) != 0 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_5) != 0)//L1,R1ボタン    //ダッシュ処理
    {
        DrawString(100, 100, "ダッシュ", 0x00ff00);
        //ダッシュ
        g_Pad.KEY_LR = TRUE;
    }
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_4) != 0)//オプションボタン    //オプション処理
    {
        DrawString(100, 100, "オプション", 0x00ff00);
        //オプション
        g_Pad.KEY_Y = TRUE;
    }
    //if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {          //コントローラーない時はこの処理でキーボードの十字キーで操作
    //    g_MapC.X1 -= PLAYERX;
    //    g_MapC.X2 -= PLAYERX;
    //}
    //if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
    //    g_MapC.X1 += PLAYERX;
    //    g_MapC.X2 += PLAYERX;
    //}
}