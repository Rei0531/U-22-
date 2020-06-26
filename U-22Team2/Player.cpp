#include "DxLib.h"
#include "Player.h"
#include "Controller.h"
#include "Map.h"
#include "Color.h"

extern image g_pic;
extern Controller g_Pad;
extern MapCoordinate g_MapC;
extern Player g_Player;

int PlayerDraw(void) {
	static int cnt = 0;	//�X�|�C���g�}���A�j���[�V�����p�J�E���g�ϐ�
	static int Jumpcnt;			//�W�����v�����̃J�E���g
	static int JumpMax = 36;	//�W�����v�����S�̂ɂ�����ő厞��


	//�v���C���[�̈ړ�����_____________________________________________________________________________________________________________________
	if (g_Pad.KEY_RIGHT == TRUE || g_Pad.KEY_LEFT == TRUE)	//�E�����ɓ��͂���Ă�����
	{
		if (g_Player.x < g_MapC.X1) {		//�}�b�v�[�Ńv���C���[����ʂ����������Ă��܂��̂�h�~�A���[�ɓ��B
			g_Player.x = g_MapC.X1;
		}
		if (g_Player.x > g_MapC.X2) {		//�}�b�v�[�Ńv���C���[����ʂ����������Ă��܂��̂�h�~�A�E�[�ɓ��B
			g_Player.x = g_MapC.X2;
		}

		g_Player.x += (g_Pad.KEY_RIGHT) ? PLAYERX : -PLAYERX;		//�v���C���[���g��X���������Z

		cnt++;//�A�j���[�V�����p�̃J�E���g�v���X
	}
	CC.Change(2);//�����ɐF�̖��O/���������Ēl��ύX
	DrawRotaGraph(g_Player.x, g_Player.y, 1.0, 0, g_pic.Player[cnt / 10 % 5], TRUE, g_Player.PLAYER_DIRECTION);//�v���C���[�摜�̕`��
	CC.ColorReset();//��ʑS�̂̕ϐF�����ɖ߂�

	//�v���C���[�̃W�����v����_____________________________________________________________________________________________________________________
	if (g_Player.PLAYER_JUMP == TRUE) {	//�W�����v�{�^���������ꂽ��

		Jumpcnt++;		//�W�����v�A�j���[�V�����̃J�E���g�J�n

		g_Player.y += (Jumpcnt <= JumpMax / 2) ? -Jumpcnt : Jumpcnt - JumpMax / 2;

		if (Jumpcnt >= JumpMax) {		//�W�����v�A�j���[�V���������߂�ꂽ���ԂɂȂ����Ƃ�
			g_Player.PLAYER_JUMP = FALSE;//�W�����v�����̏I��
			Jumpcnt = 0;				//�W�����v�A�j���[�V�����̃J�E���g��0�ɂ���
		}
	}
	//_____________________________________________________________________________________________________________________
	return 0;
}