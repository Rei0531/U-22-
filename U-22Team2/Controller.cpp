#include "Controller.h"
#include "Map.h"

/********************************
*define�̒�`
********************************/
#define PLYERX 8;		//�v���C���[�̈ړ���

//int PadInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//extern Controller g_Pad;
//MapCoordinate MapC;

void ControllerVlue(void) {         //�v���C���[�̈ړ������֐�
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) != 0)     //�R���g���[���[������Ƃ��ɂ����Ǝg���܂�
    {
        g_MapC.X1 += PLYERX;
        g_MapC.X2 += PLYERX;
    }
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT) != 0)
    {
        g_MapC.X1 -= PLYERX;
        g_MapC.X2 -= PLYERX;
    }
    //if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {          //�R���g���[���[�Ȃ����͂��̏����ŃL�[�{�[�h�̏\���L�[�ő���
    //    g_MapC.X1 -= 8;
    //    g_MapC.X2 -= 8;
    //}
    //if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
    //    g_MapC.X1 += 8;
    //    g_MapC.X2 += 8;
    //}
}