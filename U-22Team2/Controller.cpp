#include "Controller.h"
#include "Map.h"

//int PadInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
extern Controller g_Pad;
Controller g_Pad;
//MapCoordinate MapC;

void ControllerVlue(void) {
    //if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) != 0)
    //{
    //    MapC.X1 += 4;
    //    MapC.X2 += 4;
    //    DrawString(100,100,"’l‚Í—ˆ‚Ä‚¢‚Ü‚·",0xFF0000);
    //}
    //if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT) != 0)
    //{
    //    MapC.X1 -= 4;
    //    MapC.X2 -= 4;
    //}
    if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {
        MapC.X1 -= 8;
        MapC.X2 -= 8;
    }
    if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
        MapC.X1 += 8;
        MapC.X2 += 8;
    }
}