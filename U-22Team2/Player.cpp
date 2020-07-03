#include "DxLib.h"
#include "Player.h"
#include "Controller.h"
#include "Map.h"
#include "Color.h"
#include "Object.h"


extern image g_pic;
extern Controller g_Pad;
extern MapCoordinate g_MapC;
extern Player g_Player;

int PlayerDraw(void) {
	static int animecnt = 0;	//�X�|�C���g�}���A�j���[�V�����p�J�E���g�ϐ�
	static int Jumpcnt;			//�W�����v�����̃J�E���g
	static int JumpMax = 20;	//�W�����v�����S�̂ɂ�����ő厞��
	static int Gravity = 5;		//���t���[�����ɗ��Ƃ�
	static int NoMove = 0;		//0�̎������Ă��Ȃ�1�̎������Ă���/�v���C���[�̕������[�V�����ҋ@���[�V�����؂�ւ��悤�ϐ�
		

	//�X�|�C�g_____________________________________________________________________________________________________________________
	if (g_Player.PLAYER_PICKUP == TRUE) //���̊֐��Ăяo���ŐF���擾
		g_Player.NowColor = GetObjectColor();//�ϐ��ɃX�|�C�g�����F���i�[����

	//�����蔻�菈��_____________________________________________________________________________________________________________________
	//�����蔻��擾������W
	int Hit_Up_y = g_Player.y - 90,			//�v���C���[�̓���
		Hit_L_x = g_Player.x - 40,		//���̒��S�����x���W
		Hit_R_x = g_Player.x + 40,		//�E�̒��S�����x���W
		Hit_UpLR_y = g_Player.y - ((g_Player.y - Hit_Up_y) / 2),		//�㑤���E�̒��S�����y���W
		Hit_Under_y = g_Player.y + 90,		//�v���C���[�̑���	y��
		Hit_Under_x = 20,		//�v���C���[�̑���  x��
		Hit_UnderLR_y = g_Player.y - ((g_Player.y - Hit_Under_y) / 2);		//�������E�̒��S�����y���W

	//�}�W�b�N�i���o�[�̉��
	//Hit_Up_y��90�̓v���C���[�摜�̐^�񒆂���㉺�̒[�����܂ł̋���
	//Hit_LR_x��40�͉摜�̐^�񒆂��獶�E�̒[�����܂ł̋���
	//Hit_UpLR_y�͉摜�̐^�񒆂���ォ���܂ł̋����̔���

	//�����蔻��ӏ��̐F���擾
	g_Player.Hit_Up = GetPointColor(g_Player.x, Hit_Up_y);				//����
	g_Player.Hit_RightUp = GetPointColor(Hit_R_x, Hit_UpLR_y);			//�E��
	g_Player.Hit_RightUnder = GetPointColor(Hit_R_x, Hit_UnderLR_y);	//�E��
	g_Player.Hit_LeftUp = GetPointColor(Hit_L_x, Hit_UpLR_y);			//����
	g_Player.Hit_LeftUnder = GetPointColor(Hit_L_x, Hit_UnderLR_y);		//����
	g_Player.Hit_Under = GetPointColor(g_Player.x + Hit_Under_x, Hit_Under_y);		//�E����
	g_Player.Hit_Under2 = GetPointColor(g_Player.x - Hit_Under_x, Hit_Under_y);		//������

	//�����蔻��̉���
	DrawBox(g_Player.x - 5, Hit_Up_y - 5, g_Player.x + 5, Hit_Up_y + 5, 0xff00ff, FALSE);	//����
	DrawBox(Hit_R_x - 5, Hit_UpLR_y - 5, Hit_R_x + 5, Hit_UpLR_y + 5, 0xff00ff, FALSE);	//�E��
	DrawBox(Hit_R_x - 5, Hit_UnderLR_y - 5, Hit_R_x + 5, Hit_UnderLR_y + 5, 0xff00ff, FALSE);	//�E��
	DrawBox(Hit_L_x - 5, Hit_UpLR_y - 5, Hit_L_x + 5, Hit_UpLR_y + 5, 0xff00ff, FALSE);	//����
	DrawBox(Hit_L_x - 5, Hit_UnderLR_y - 5, Hit_L_x + 5, Hit_UnderLR_y + 5, 0xff00ff, FALSE);	//����

	DrawBox(g_Player.x - 5 + Hit_Under_x, Hit_Under_y - 5, g_Player.x + 5 + Hit_Under_x, Hit_Under_y + 5, 0xff00ff, FALSE);	//�����E
	DrawBox(g_Player.x - 5 - Hit_Under_x, Hit_Under_y - 5, g_Player.x + 5 - Hit_Under_x, Hit_Under_y + 5, 0xff00ff, FALSE);	//������

	//�X�|�C�g���Ă���ꏊ�̎l�p�\��
	DrawBox(g_Player.PickUpPixel - 5, g_Player.y - 5, g_Player.PickUpPixel + 5, g_Player.y + 5, 0xff00ff, FALSE);


	//�v���C���[�̈ړ�����_____________________________________________________________________________________________________________________
	if (g_Pad.KEY_RIGHT == TRUE || g_Pad.KEY_LEFT == TRUE)	//�E�����ɓ��͂���Ă�����
	{
		if (g_Player.x < g_MapC.X1) {		//�}�b�v�[�Ńv���C���[����ʂ����������Ă��܂��̂�h�~�A���[�ɓ��B
			g_Player.x = g_MapC.X1;
		}
		if (g_Player.x > g_MapC.X2) {		//�}�b�v�[�Ńv���C���[����ʂ����������Ă��܂��̂�h�~�A�E�[�ɓ��B
			g_Player.x = g_MapC.X2;
		}

		//�����蔻�菈��____________________________________________________________________________
		if (g_Player.NowColor != g_Player.Hit_RightUp && g_Player.NowColor != g_Player.Hit_RightUnder) {
			g_Player.x += PLAYERX;
		}
		if (g_Player.NowColor != g_Player.Hit_LeftUp && g_Player.NowColor != g_Player.Hit_LeftUnder) {
			g_Player.x -= PLAYERX;
		}

		g_Player.x += (g_Pad.KEY_RIGHT) ? PLAYERX : -PLAYERX;		//�v���C���[���g��X���������Z
		//_________________________________________________________________________________________
		animecnt++;//�A�j���[�V�����p�̃J�E���g�v���X
		NoMove = 1;
	}
	else {
		NoMove = 0;//�����Ă��Ȃ�
		animecnt = 0;//�A�j���[�V�������~�߂�
	}
	//�d�͂̏���_____________________________________________________________________________________________
	//�v���C���[���n�ʂɂ��Ă��Ȃ��Ƃ�
	if (!((g_Player.Hit_Under == BLACK || g_Player.Hit_Under == g_Player.NowColor) || 
		(g_Player.Hit_Under2 == BLACK || g_Player.Hit_Under2 == g_Player.NowColor))) {
		g_Player.y += Gravity;		//�v���C���[�ɏd�͂�ǉ�
	}

	//�v���C���[�̃W�����v����_____________________________________________________________________________________________________________________
	if (g_Player.PLAYER_JUMP == TRUE) {	//�W�����v�{�^���������ꂽ��
		Jumpcnt++;		//�W�����v�A�j���[�V�����̃J�E���g�J�n
		if (Jumpcnt <= JumpMax) {//���߂�ꂽ���Ԃ܂Ńv���C���[����ɂ�����
			g_Player.y -= Jumpcnt;
		}
		if (Jumpcnt >= JumpMax && ((g_Player.Hit_Under == BLACK || g_Player.Hit_Under == g_Player.NowColor) ||
			(g_Player.Hit_Under2 == BLACK || g_Player.Hit_Under2 == g_Player.NowColor))) {		//�W�����v�A�j���[�V���������߂�ꂽ���ԂɂȂ����Ƃ�
			g_Player.PLAYER_JUMP = FALSE;//�W�����v�����̏I��
			Jumpcnt = 0;				//�W�����v�A�j���[�V�����̃J�E���g��0�ɂ���
		}
	}
	//�v���C���[�̕`��_____________________________________________________________________________________________________________________
	Change(g_Player.NowColor);//�����ɐF�̖��O/���������Ēl��ύX
	DrawRotaGraph(g_Player.x, g_Player.y, 1.0, 0, g_pic.Player[animecnt / 10 % 4 + NoMove], TRUE, g_Player.PLAYER_DIRECTION);//�v���C���[�摜�̕`��
	ColorReset();//��ʑS�̂̕ϐF�����ɖ߂�
	//_____________________________________________________________________________________________________________________
	return 0;
}