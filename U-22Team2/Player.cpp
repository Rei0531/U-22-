#include "DxLib.h"
#include "Player.h"
#include "Controller.h"
//���Ă��܂���
extern image g_pic;
extern Controller g_Pad;

int Player(void) {
	static int cnt = 0;	//�A�j���[�V�����p�J�E���g�ϐ�
	static int MouseX = 640;	//���WX
	static int MouseY = 645;	//���WY
	static int Jumpcnt;			//�W�����v�����̃J�E���g
	static int JumpMax = 40;	//�W�����v�����S�̂ɂ�����ő厞��//60�t���[����1�b�����炱�̏�����1�b�ō����

	if (g_Pad.PLAYER_JUMP == TRUE) {	//�W�����v�{�^���������ꂽ��
		Jumpcnt++;

		if (Jumpcnt <= JumpMax /2) {	//�����̑O���͏㏸��
			MouseY -= Jumpcnt;
		}
		else {
			MouseY += Jumpcnt - JumpMax/2;
		}
		if (Jumpcnt >= JumpMax)//�W�����v�����̏I��
			g_Pad.PLAYER_JUMP = FALSE;
	}
	else {
		Jumpcnt = 0;
	}

	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT || GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) != 0)
	{
		//DrawRotaGraph(640, 645, 1.0, 0, g_pic.Player[cnt++ / 10 % 2 + 1], TRUE, FALSE);//�l�Y�~�摜�̕`��
		DrawRotaGraph(MouseX, MouseY, 1.0, 0, g_pic.Player[cnt++ / 10 % 2 + 1], TRUE, g_Pad.PLAYER_DIRECTION);//�l�Y�~�摜�̕`��
	}
	else
	{
		//DrawRotaGraph(640, 645, 1.0, 0, g_pic.Player[0], TRUE, FALSE);//�l�Y�~�摜�̕`��
		DrawRotaGraph(MouseX, MouseY, 1.0, 0, g_pic.Player[0], TRUE, g_Pad.PLAYER_DIRECTION);//�l�Y�~�摜�̕`��
	}
	return 0;
}