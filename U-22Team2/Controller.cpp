#include "Controller.h"
#include "Map.h"
#include "constant.h"
#include "Player.h"

extern Controller g_Pad;
extern Player g_Player;

void ControllerVlue(void) {         //�v���C���[�̈ړ������֐�
	//������_____________________________________________________________________________________________________________________
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) != 0)    //��ʍ�������
	{
		g_Pad.KEY_LEFT = TRUE;
		if (GameState == GAME_MAIN && g_Player.PLAYER_MENU == FALSE && g_Player.PLAYER_MOVEOK == TRUE) { //�Q�[�����v���C����������
			g_Player.PLAYER_DIRECTION = TRUE;  //�v���C���[�̌����t���O�����ɂ���
		}
	}
	else { g_Pad.KEY_LEFT = FALSE; }
	//�E����_____________________________________________________________________________________________________________________
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT) != 0)
	{
		g_Pad.KEY_RIGHT = TRUE;
		if (GameState == GAME_MAIN && g_Player.PLAYER_MENU == FALSE && g_Player.PLAYER_MOVEOK == TRUE) { //�Q�[�����v���C����������
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
	}
	else { g_Pad.KEY_DOWN = FALSE; }
	//B�{�^��_____________________________________________________________________________________________________________________
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B) != 0)//�A�N�V��������
	{
		g_Pad.KEY_B = TRUE;
		if ((GameState == GAME_MAIN) & (g_Pad.KEY_FLG_B == TRUE)) { //�Q�[�����v���C����������
			g_Player.PLAYER_ACTION = TRUE;      //�v���C���[�̃A�N�V�����t���O
			g_Pad.KEY_FLG_B = FALSE;      //�{�^�����������܂�FLG��FALSE�ɂ���
		}
	}
	else {
		g_Pad.KEY_B = FALSE;
		g_Pad.KEY_FLG_B = TRUE;
		g_Player.PLAYER_ACTION = FALSE;      //�v���C���[�̃A�N�V�����t���O
	}
	//A�{�^��_____________________________________________________________________________________________________________________
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A) != 0)
	{
		g_Pad.KEY_A = TRUE;
		if (GameState == GAME_MAIN && g_Player.PLAYER_JUMP == FALSE 
			&& g_Player.PLAYER_MENU == FALSE && g_Player.PLAYER_MOVEOK == TRUE) {//�Q�[�����v���C����������
			g_Player.PLAYER_JUMP = TRUE;
		}
	}
	else { g_Pad.KEY_A = FALSE; }
	//X�{�^��_____________________________________________________________________________________________________________________
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_3) != 0)//�A�N�V��������
	{
		g_Pad.KEY_X = TRUE;
		if ((GameState == GAME_MAIN) & (g_Pad.KEY_FLG == TRUE)) { //�Q�[�����v���C����������
			g_Player.PLAYER_PICKUP = TRUE;      //�v���C���[�̃X�|�C�g�t���O
			g_Pad.KEY_FLG = FALSE;      //�{�^�����������܂�FLG��FALSE�ɂ���
		}
	}
	else {
		g_Pad.KEY_X = FALSE;
		g_Pad.KEY_FLG = TRUE;
	}
	//START�{�^��_____________________________________________________________________________________________________________________
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_8) != 0)//�I�v�V�����{�^��    //�I�v�V��������
	{
		g_Pad.KEY_Y = TRUE;
		if ((GameState == GAME_MAIN) & (g_Pad.KEY_FLG_Y == TRUE)) { //�Q�[�����v���C����������
			g_Player.PLAYER_MENU = TRUE;      //�v���C���[�̃��j���[�t���O
			g_Pad.KEY_FLG_Y = FALSE;    //�{�^�����������܂�FLG��FALSE�ɂ���
		}
	}
	else {
		g_Pad.KEY_Y = FALSE;
		g_Pad.KEY_FLG_Y = TRUE;
	}
	////L1,R1�{�^��_____________________________________________________________________________________________________________________
	//if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_6) != 0 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_5) != 0)//L1,R1�{�^��    //�_�b�V������
	//{
	//	g_Pad.KEY_LR = TRUE;
	//}
	//else { g_Pad.KEY_LR = FALSE; }

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