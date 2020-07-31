#include "DxLib.h"
#include "Player.h"
#include "Controller.h"
#include "Map.h"
#include "Color.h"
#include "Object.h"
#include"Door.h"
#include "Object.h"
#include "LoadSound.h"

extern image g_pic;
extern Controller g_Pad;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern Sound g_Snd;


int PlayerDraw(void) {
	static int animecnt = 0;	//�X�|�C���g�}���A�j���[�V�����p�J�E���g�ϐ�
	static int Jumpcnt = 20;			//�W�����v�����̃J�E���g
	static int JumpMax = 0;	//�W�����v�����S�̂ɂ�����ő厞��
	static int Gravity = 5;		//���t���[�����ɗ��Ƃ�
	static int NoMove = 0;		//0�̎������Ă��Ȃ�1�̎������Ă���/�v���C���[�̕������[�V�����ҋ@���[�V�����؂�ւ��悤�ϐ�
	static int JumpOkflag = 0;	//�󒆃W�����v�h�~�ϐ�/0���W�����v���Ă��Ȃ�/1���W�����v��
	static int Move_Hitx1 = 0,
		Move_Hitx2 = 0;

	//�X�|�C�g_____________________________________________________________________________________________________________________
	if (g_Player.PLAYER_PICKUP == TRUE && g_Player.Interact > 0) { //���̊֐��Ăяo���ŐF���擾
		g_Player.NowColor = GetObjectColor();//�ϐ��ɃX�|�C�g�����F���i�[����
	}

	//�����蔻�菈��_____________________________________________________________________________________________________________________
	//�����蔻��擾������W
	int Hit_Up_y = g_Player.y - 33,			//�v���C���[�̓���
		Hit_L_x = g_Player.x - 30,		//���̒��S�����x���W
		Hit_R_x = g_Player.x + 30,		//�E�̒��S�����x���W
		//Hit_UpLR_y = g_Player.y - ((g_Player.y - (g_Player.y - 36)) / 2),		//�㑤���E�̒��S�����y���W
		Hit_UpLR_y = g_Player.y,
		Hit_Under_y = g_Player.y + 72,		//�v���C���[�̑���	y��
		Hit_Under_x = 20,		//�v���C���[�̑���  x��
		//Hit_UnderLR_y = g_Player.y - ((g_Player.y - Hit_Under_y) / 2);		//�������E�̒��S�����y���W
		Hit_UnderLR_y = g_Player.y + 60;

	Move_Hitx1 = g_Player.x + 40;//�擾������W
	Move_Hitx2 = g_Player.x - 40;//�擾������W

	//�}�W�b�N�i���o�[�̉��
	//Hit_Up_y��90�̓v���C���[�摜�̐^�񒆂���㉺�̒[�����܂ł̋���
	//Hit_LR_x��40�͉摜�̐^�񒆂��獶�E�̒[�����܂ł̋���
	//Hit_UpLR_y�͉摜�̐^�񒆂���ォ���܂ł̋����̔���

	//�����蔻��ӏ��̐F���擾_________________________________________________________
	g_Player.Hit_Up = GetPointColor(g_Player.x, Hit_Up_y);				//����
	g_Player.Hit_RightUp = GetPointColor(Hit_R_x, Hit_UpLR_y);			//�E��
	g_Player.Hit_RightUnder = GetPointColor(Hit_R_x, Hit_UnderLR_y);	//�E��
	g_Player.Hit_LeftUp = GetPointColor(Hit_L_x, Hit_UpLR_y);			//����
	g_Player.Hit_LeftUnder = GetPointColor(Hit_L_x, Hit_UnderLR_y);		//����
	g_Player.Hit_Under = GetPointColor(g_Player.x + Hit_Under_x, Hit_Under_y);		//�E����
	g_Player.Hit_Under2 = GetPointColor(g_Player.x - Hit_Under_x, Hit_Under_y);		//������
	//��������{�b�N�X���ǂ����m�邽�߂̐F���擾_________________________
	g_Player.Move_Hit1 = GetPointColor(Move_Hitx1, g_Player.y + 20);		//�v���C���[�̒��S���W����ނ��Ă��������50�����Z�����l�̐F���擾
	g_Player.Move_Hit2 = GetPointColor(Move_Hitx2, g_Player.y + 20);		//�v���C���[�̒��S���W����ނ��Ă��������50�����Z�����l�̐F���擾

	g_Player.Hit_Rght_High = GetPointColor(Hit_R_x, Hit_UpLR_y - 50);		//�E��
	g_Player.Hit_Left_High = GetPointColor(Hit_L_x, Hit_UpLR_y - 50);		//�E��

	//�����蔻��̉���_____________________________________________________________________
	//DrawBox(g_Player.x - 5, Hit_Up_y - 5, g_Player.x + 5, Hit_Up_y + 5, 0xfe00fe, FALSE);	//����
	//DrawBox(Hit_R_x - 5, Hit_UpLR_y - 5, Hit_R_x + 5, Hit_UpLR_y + 5, 0xfe00fe, FALSE);	//�E��
	//DrawBox(Hit_R_x - 5, Hit_UnderLR_y - 5, Hit_R_x + 5, Hit_UnderLR_y + 5, 0xfe00fe, FALSE);	//�E��
	//DrawBox(Hit_L_x - 5, Hit_UpLR_y - 5, Hit_L_x + 5, Hit_UpLR_y + 5, 0xfe00fe, FALSE);	//����
	//DrawBox(Hit_L_x - 5, Hit_UnderLR_y - 5, Hit_L_x + 5, Hit_UnderLR_y + 5, 0xfe00fe, FALSE);	//����
	//DrawBox(g_Player.x - 5 + Hit_Under_x, Hit_Under_y - 5, g_Player.x + 5 + Hit_Under_x, Hit_Under_y + 5, 0xfe00fe, FALSE);	//�����E
	//DrawBox(g_Player.x - 5 - Hit_Under_x, Hit_Under_y - 5, g_Player.x + 5 - Hit_Under_x, Hit_Under_y + 5, 0xfe00fe, FALSE);	//������
	//DrawBox(g_Player.PickUpPixel - 5, g_Player.PickUpPixely - 5, g_Player.PickUpPixel + 5, g_Player.PickUpPixely + 5, 0xff00ff, FALSE);
	//DrawBox(Move_Hitx1 - 5, g_Player.y + 20 - 5, Move_Hitx1 + 5, g_Player.y + 20 + 5, 0xfe00fe, FALSE);	//�����u���b�N�̎擾�ʒu�E
	//DrawBox(Move_Hitx2 - 5, g_Player.y + 20 - 5, Move_Hitx2 + 5, g_Player.y + 20 + 5, 0xfe00fe, FALSE);	//�����u���b�N�̎擾�ʒu��

	//DrawBox(Hit_R_x - 5, Hit_UpLR_y - 50 - 5, Hit_R_x + 5, Hit_UpLR_y - 50 + 5, 0xfe00fe, FALSE);	//�E��
	//DrawBox(Hit_L_x - 5, Hit_UpLR_y - 50 - 5, Hit_L_x + 5, Hit_UpLR_y - 50 + 5, 0xfe00fe, FALSE);	//�E��

	//�����蔻��̃t���O�Ǘ�_____________________________________
	//�E�s���ă��V�I
	bool RightOK = g_Player.NowColor != g_Player.Hit_RightUp && g_Player.NowColor != g_Player.Hit_RightUnder && g_Player.NowColor != g_Player.Hit_Rght_High
		&& g_Player.Hit_RightUp != BLACK && g_Player.Hit_RightUnder != BLACK && g_Player.Hit_Rght_High != BLACK;
	//���s���ă��V�I
	bool LeftOK = g_Player.NowColor != g_Player.Hit_LeftUp && g_Player.NowColor != g_Player.Hit_LeftUnder && g_Player.NowColor != g_Player.Hit_Left_High
		&& g_Player.Hit_LeftUp != BLACK && g_Player.Hit_LeftUnder != BLACK && g_Player.Hit_Left_High != BLACK;

	if (g_Player.PLAYER_MENU == FALSE) {//���j���[��ʂ���Ă���Ƃ�
		//�v���C���[�̈ړ�����_____________________________________________________________________________________________________________________
		if (g_Pad.KEY_RIGHT == TRUE || g_Pad.KEY_LEFT == TRUE)	//�E�����ɓ��͂���Ă�����
		{
			if (CheckSoundMem(g_Snd.Walk) == 0 && g_Player.PLAYER_JUMP == FALSE) {
				PlaySoundMem(g_Snd.Walk, DX_PLAYTYPE_BACK);
			}
			if (g_Player.x < g_MapC.X1) {		//�}�b�v�[�Ńv���C���[����ʂ����������Ă��܂��̂�h�~�A���[�ɓ��B
				g_Player.x = g_MapC.X1;
			}
			if (g_Player.x > g_MapC.X2) {		//�}�b�v�[�Ńv���C���[����ʂ����������Ă��܂��̂�h�~�A�E�[�ɓ��B
				g_Player.x = g_MapC.X2;
			}

			//�����蔻�菈�� & �{�b�N�X�𓮂���____________________________________________________________________________
			//�E���̓����蔻�菈��___________________________________
			if (RightOK == TRUE) {
				if (g_Pad.KEY_RIGHT)
					g_Player.x += PLAYERX;
				//�u���b�N����������___________________________
				if (g_Pad.KEY_B == TRUE && g_Player.Move_Hit1 == MOVE && g_Player.NowColor == g_Player.Hit_RightUnder
					&& g_Player.PLAYER_GROUND == TRUE) {//�E���ɓ����u���b�N����������
					if (g_Pad.KEY_RIGHT == TRUE)
						MoveObjectValue(g_Player.NowColor);
				}
			}
			//�u���b�N����������___________________________
			else if (g_Pad.KEY_B == TRUE && g_Player.Move_Hit1 == MOVE && g_Player.NowColor == g_Player.Hit_RightUnder
				&& g_Player.PLAYER_GROUND == TRUE) {//�E���ɓ����u���b�N����������
				if (g_Pad.KEY_LEFT == TRUE && g_Player.NowColor != g_Player.Hit_LeftUnder ||
					g_Pad.KEY_RIGHT == TRUE) {
					MoveObjectValue(g_Player.NowColor);
				}
			}
			//�����̓����蔻�菈��_______________________
			if (LeftOK == TRUE) {
				if (g_Pad.KEY_LEFT)
					g_Player.x -= PLAYERX;
				//�u���b�N����������___________________________
				if (g_Pad.KEY_B == TRUE && g_Player.Move_Hit2 == MOVE && g_Player.NowColor == g_Player.Hit_LeftUnder
					&& g_Player.PLAYER_GROUND == TRUE) {//�����ɓ����u���b�N����������
					if (g_Pad.KEY_LEFT == TRUE)
						MoveObjectValue(g_Player.NowColor);
				}
			}
			//�u���b�N����������___________________________
			else if (g_Pad.KEY_B == TRUE && g_Player.Move_Hit2 == MOVE && g_Player.NowColor == g_Player.Hit_LeftUnder
				&& g_Player.PLAYER_GROUND == TRUE) {//�����ɓ����u���b�N����������
				if (g_Pad.KEY_RIGHT == TRUE && g_Player.NowColor != g_Player.Hit_RightUnder ||
					g_Pad.KEY_LEFT == TRUE) {
					MoveObjectValue(g_Player.NowColor);
				}
			}

			//�����������鉹���~�߂�_______
			if ((g_Pad.KEY_B == FALSE) && (CheckSoundMem(g_Snd.BoxDrag) == 1)) {
				StopSoundMem(g_Snd.BoxDrag);
			}
			//_________________________________________________________________________________________
			animecnt++;//�A�j���[�V�����p�̃J�E���g�v���X
			NoMove = 1;//�����Ă���Ƃ��̃t���O
		}
		else {//�����Ă��Ȃ�
			NoMove = 0;//�����Ă��Ȃ�
			animecnt = 0;//�A�j���[�V�������~�߂�
			if (CheckSoundMem(g_Snd.Walk) == 1) {
				StopSoundMem(g_Snd.Walk);
			}
		}

		//�d�͂̏���_____________________________________________________________________________________________
		//�v���C���[���n�ʂɂ��Ă��Ȃ��Ƃ�
		if (!((g_Player.Hit_Under == BLACK || g_Player.Hit_Under == g_Player.NowColor) ||
			(g_Player.Hit_Under2 == BLACK || g_Player.Hit_Under2 == g_Player.NowColor))) {
			g_Player.y += Gravity;		//�v���C���[�ɏd�͂�ǉ�
			g_Player.PLAYER_GROUND = FALSE;
		}
		else {
			JumpOkflag = 0;	//�n�ʂɂ��Ă���̂ŃW�����v���Ă��Ȃ�
			g_Player.PLAYER_GROUND = TRUE;
		}

		//�v���C���[�̃W�����v����_____________________________________________________________________________________________________________________
		if ((g_Player.PLAYER_JUMP == TRUE && ((g_Player.Hit_Under == BLACK || g_Player.Hit_Under == g_Player.NowColor) ||
			(g_Player.Hit_Under2 == BLACK || g_Player.Hit_Under2 == g_Player.NowColor))) || JumpOkflag == 1) {	//�W�����v�{�^���������ꂽ��
			Jumpcnt--;		//�W�����v�A�j���[�V�����̃J�E���g�J�n
			JumpOkflag = 1;	//��x�W�����v�����̂ŏI���܂ŃW�����v����
			if (Jumpcnt >= JumpMax) {//���߂�ꂽ���Ԃ܂Ńv���C���[����ɂ�����
				g_Player.y -= Jumpcnt;
			}
			if (Jumpcnt <= JumpMax && ((g_Player.Hit_Under == BLACK || g_Player.Hit_Under == g_Player.NowColor) ||
				(g_Player.Hit_Under2 == BLACK || g_Player.Hit_Under2 == g_Player.NowColor))) {		//�W�����v�A�j���[�V���������߂�ꂽ���ԂɂȂ����Ƃ�
				g_Player.PLAYER_JUMP = FALSE;//�W�����v�����̏I��
				Jumpcnt = 20;				//�W�����v�A�j���[�V�����̃J�E���g��0�ɂ���
			}
		}
	}
	//�v���C���[�̕`��_____________________________________________________________________________________________________________________
	Change(g_Player.NowColor);//�����ɐF�̖��O/���������Ēl��ύX
	DrawRotaGraph(g_Player.x, g_Player.y, 0.7, 0, g_pic.Player[animecnt / 10 % 4 + NoMove], TRUE, g_Player.PLAYER_DIRECTION);//�v���C���[�摜�̕`��
	ColorReset();//��ʑS�̂̕ϐF�����ɖ߂�
	//_____________________________________________________________________________________________________________________
	return 0;
}