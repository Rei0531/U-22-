#include "Controller.h"
#include "Map.h"
#include "constant.h"
#include "Player.h"

extern Controller g_Pad;
Player g_Player;

void ControllerVlue(void) {         //�v���C���[�̈ړ������֐�
    //������_____________________________________________________________________________________________________________________
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) != 0)    //��ʍ�������
    {
        g_Pad.KEY_LEFT = TRUE;
        if (GameState == GAME_TITLE) { //�Q�[�����v���C����������//���̓^�C�g���œ������Ă���
            g_Player.PLAYER_DIRECTION = TRUE;  //�v���C���[�̌����t���O�����ɂ���
        }
    }
    else { g_Pad.KEY_LEFT = FALSE; }
    //�E����_____________________________________________________________________________________________________________________
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT) != 0)
    {
        g_Pad.KEY_RIGHT = TRUE;
        if (GameState == GAME_TITLE) { //�Q�[�����v���C����������//���̓^�C�g���œ������Ă���
            g_Player.PLAYER_DIRECTION = FALSE;  //�v���C���[�̌����t���O���E�ɂ���
        }
    }
    else { g_Pad.KEY_RIGHT = FALSE; }
    //�����_____________________________________________________________________________________________________________________
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP) != 0)
    {
        g_Pad.KEY_UP = TRUE;
    }
    else { g_Pad.KEY_UP = FALSE; }
    //������_____________________________________________________________________________________________________________________
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN) != 0)
    {
        g_Pad.KEY_DOWN = TRUE;
        if (GameState == GAME_TITLE) { //�Q�[�����v���C����������//���̓^�C�g���œ������Ă���
            g_Player.PLAYER_SQUAT = TRUE;      //�v���C���[�̂��Ⴊ�݃t���O
        }
    }
    else { g_Pad.KEY_DOWN = FALSE; }
    //B�{�^��_____________________________________________________________________________________________________________________
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B) != 0)//�W�����v����
    {
        g_Pad.KEY_B = TRUE;
        if (GameState == GAME_TITLE && g_Player.PLAYER_JUMP == FALSE) {//�Q�[�����v���C����������//���̓^�C�g���œ������Ă���
            g_Player.PLAYER_JUMP = TRUE;
        }
    }
    else { g_Pad.KEY_B = FALSE; }
    //A�{�^��_____________________________________________________________________________________________________________________
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A) != 0)
    {
        g_Pad.KEY_A = TRUE;
        if (GameState == GAME_TITLE) { //�Q�[�����v���C����������//���̓^�C�g���œ������Ă���
            g_Player.PLAYER_SQUAT = TRUE;      //�v���C���[�̂��Ⴊ�݃t���O
        }
    }
    else { g_Pad.KEY_A = FALSE; }
    //X�{�^��_____________________________________________________________________________________________________________________
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_3) != 0)//�A�N�V��������
    {
        g_Pad.KEY_X = TRUE;
        if (GameState == GAME_TITLE) { //�Q�[�����v���C����������//���̓^�C�g���œ������Ă���
            g_Player.PLAYER_ACTION = TRUE;      //�v���C���[�̃A�N�V�����t���O
        }
    }
    else { g_Pad.KEY_X = FALSE; }
    //Y�{�^��_____________________________________________________________________________________________________________________
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_4) != 0)//�I�v�V�����{�^��    //�I�v�V��������
    {
        g_Pad.KEY_Y = TRUE;
        if (GameState == GAME_TITLE) { //�Q�[�����v���C����������//���̓^�C�g���œ������Ă���
            g_Player.PLAYER_MENU = TRUE;      //�v���C���[�̃��j���[�t���O
        }
    }
    else { g_Pad.KEY_Y = FALSE; }
    //L1,R1�{�^��_____________________________________________________________________________________________________________________
    if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_6) != 0 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_5) != 0)//L1,R1�{�^��    //�_�b�V������
    {
        g_Pad.KEY_LR = TRUE;
    }
    else { g_Pad.KEY_LR = FALSE; }

    //_____________________________________________________________________________________________________________________
    //if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {          //�R���g���[���[�Ȃ����͂��̏����ŃL�[�{�[�h�̏\���L�[�ő���
    //    g_MapC.X1 -= PLAYERX;
    //    g_MapC.X2 -= PLAYERX;
    //}
    //if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
    //    g_MapC.X1 += PLAYERX;
    //    g_MapC.X2 += PLAYERX;
    //}
}