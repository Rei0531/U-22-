#include "DxLib.h"
#include "Player.h"
#include "Controller.h"
#include "Map.h"

extern image g_pic;
extern Controller g_Pad;
extern MapCoordinate g_MapC;
extern Rat g_Rat;

int Player(void) {
	static int cnt = 0;	//�l�Y�~�A�j���[�V�����p�J�E���g�ϐ�
	static int Jumpcnt;			//�W�����v�����̃J�E���g
	static int JumpMax = 46;	//�W�����v�����S�̂ɂ�����ő厞��//60�t���[����1�b�����炱�̏�����1�b�ō����



	//�v���C���[�̈ړ�����_____________________________________________________________________________________________________________________
	if (g_Pad.KEY_RIGHT == TRUE || g_Pad.KEY_LEFT == TRUE)	//�E�����ɓ��͂���Ă�����
	{
		if (g_Rat.x < g_MapC.X1) {		//�}�b�v�[�Ńv���C���[����ʂ����������Ă��܂��̂�h�~�A���[�ɓ��B
			g_Rat.x = g_MapC.X1;
		}
		if (g_Rat.x > g_MapC.X2) {		//�}�b�v�[�Ńv���C���[����ʂ����������Ă��܂��̂�h�~�A�E�[�ɓ��B
			g_Rat.x = g_MapC.X2;
		}

		if (g_MapC.MAP_MAX == TRUE && g_MapC.X1 <= g_Rat.x && g_MapC.X2 >= g_Rat.x) {		//�}�b�v�[���v���C���[����ʓ��ɂ��鎞
			g_Rat.x += (g_Pad.KEY_RIGHT) ? PLAYERX : -PLAYERX;		//�v���C���[���g��X���������Z
		}
		DrawRotaGraph(g_Rat.x, g_Rat.y, 1.0, 0, g_pic.Player[cnt++ / 10 % 2 + 1], TRUE, g_Rat.PLAYER_DIRECTION);//�l�Y�~�摜�̕`��

		g_MapC.MAP_MAX = (g_Rat.x == 640) ? FALSE : TRUE;
	}
	else {													//�������͂���Ă��Ȃ��Ƃ��ҋ@���[�V����
		DrawRotaGraph(g_Rat.x, g_Rat.y, 1.0, 0, g_pic.Player[0], TRUE, g_Rat.PLAYER_DIRECTION);//�l�Y�~�摜�̕`��
	}
	//�v���C���[�̃W�����v����_____________________________________________________________________________________________________________________
	if (g_Rat.PLAYER_JUMP == TRUE) {	//�W�����v�{�^���������ꂽ��

		Jumpcnt++;		//�W�����v�A�j���[�V�����̃J�E���g�J�n

		g_Rat.y += (Jumpcnt <= JumpMax / 2) ? -Jumpcnt : Jumpcnt - JumpMax / 2;

		if (Jumpcnt >= JumpMax) {		//�W�����v�A�j���[�V���������߂�ꂽ���ԂɂȂ����Ƃ�
			g_Rat.PLAYER_JUMP = FALSE;//�W�����v�����̏I��
			Jumpcnt = 0;				//�W�����v�A�j���[�V�����̃J�E���g��0�ɂ���
		}
	}
	//_____________________________________________________________________________________________________________________
	return 0;
}