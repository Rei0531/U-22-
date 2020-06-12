#include "DxLib.h"

int PadInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);

void a(void) {
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) == 0)
    {

    }
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT) == 0)
    {
    }
}