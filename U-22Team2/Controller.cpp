#include "Controller.h"
#include "Map.h"
#include "constant.h"


//int PadInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
extern Controller g_Pad;
//MapCoordinate MapC;

void ControllerVlue(void) {         //�v���C���[�̈ړ������֐�
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) != 0 && g_MapC.X1 < 0)    //��ʍ�������
    {
        g_Pad.KEY_LEFT = TRUE;
        if (GameState == GAME_TITLE) {
            //�Q�[�����v���C����������//���̓^�C�g���œ������Ă���
            g_Pad.PLAYER_DIRECTION = TRUE;  //�v���C���[�̌����t���O�����ɂ���
        }
    }
    else { g_Pad.KEY_LEFT = FALSE; }

    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT) != 0 && g_MapC.X2 > SCREEN_WIDHT)    //��ʉE������
    {
        g_Pad.KEY_RIGHT = TRUE;
        if (GameState == GAME_TITLE) {
            //�Q�[�����v���C����������//���̓^�C�g���œ������Ă���
            g_Pad.PLAYER_DIRECTION = FALSE;  //�v���C���[�̌����t���O���E�ɂ���
        }
    }
    else { g_Pad.KEY_RIGHT = FALSE; }

    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B) != 0)//B�{�^��    //�W�����v����
    {
        DrawString(100,100,"�W�����v���܂���",0x00ff00);
        g_Pad.KEY_B = TRUE;

        if (GameState == GAME_TITLE && g_Pad.PLAYER_JUMP == FALSE) {
            //�Q�[�����v���C����������//���̓^�C�g���œ������Ă���
            g_Pad.PLAYER_JUMP = TRUE;
        }

    }
    else { g_Pad.KEY_B = FALSE; }

    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A) != 0 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN) != 0)//A�{�^��    //�W�����v����
    {
        DrawString(100, 100, "���Ⴊ�݂܂���", 0x00ff00);
        //���Ⴊ��
        g_Pad.KEY_A = TRUE;
    }
    else { g_Pad.KEY_A = FALSE; }

    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_3) != 0)//X�{�^��    //�A�N�V��������
    {
        DrawString(100, 100, "�A�N�V����", 0x00ff00);
        //�A�N�V����
        g_Pad.KEY_X = TRUE;
    }
    else { g_Pad.KEY_X = FALSE; }

    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_6) != 0 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_5) != 0)//L1,R1�{�^��    //�_�b�V������
    {
        DrawString(100, 100, "�_�b�V��", 0x00ff00);
        //�_�b�V��
        g_Pad.KEY_LR = TRUE;
    }
    else { g_Pad.KEY_LR = FALSE; }

    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_4) != 0)//�I�v�V�����{�^��    //�I�v�V��������
    {
        DrawString(100, 100, "�I�v�V����", 0x00ff00);
        //�I�v�V����
        g_Pad.KEY_Y = TRUE;
    }
    else { g_Pad.KEY_Y = FALSE; }

    //if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {          //�R���g���[���[�Ȃ����͂��̏����ŃL�[�{�[�h�̏\���L�[�ő���
    //    g_MapC.X1 -= PLAYERX;
    //    g_MapC.X2 -= PLAYERX;
    //}
    //if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
    //    g_MapC.X1 += PLAYERX;
    //    g_MapC.X2 += PLAYERX;
    //}
}