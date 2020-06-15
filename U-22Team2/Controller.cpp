#include "Controller.h"
#include "Map.h"
#include "constant.h"

//int PadInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//extern Controller g_Pad;
//MapCoordinate MapC;

void ControllerVlue(void) {         //プレイヤーの移動処理関数
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) != 0 && g_MapC.X1 < 0)     //コントローラーがあるときにちゃんと使えます
    {
        g_MapC.X1 += PLAYERX;
        g_MapC.X2 += PLAYERX;
    }
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT) != 0 && g_MapC.X2 > SCREEN_WIDHT)
    {
        g_MapC.X1 -= PLAYERX;
        g_MapC.X2 -= PLAYERX;
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