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
/************************************************************************
**
**		�X�|�C�g����
**
*************************************************************************/

	if (g_Player.PLAYER_PICKUP == TRUE && g_Player.Interact > 0) { //���̊֐��Ăяo���ŐF���擾
		g_Player.NowColor = GetObjectColor();//�ϐ��ɃX�|�C�g�����F���i�[����
	}
	if (g_Player.Interact <= 0)g_Player.Interact = 0;

/************************************************************************
**
**		�����蔻��擾����
**
*************************************************************************/
	int Hit_Up_y = g_Player.y - 33,			//�v���C���[�̓���
		Hit_L_x = g_Player.x - 30,		//���̒��S�����x���W
		Hit_R_x = g_Player.x + 30,		//�E�̒��S�����x���W
		Hit_UpLR_y = g_Player.y,		//�㑤���E�̒��S�����y���W
		Hit_Under_y = g_Player.y + 72,		//�v���C���[�̑���	y��
		Hit_Under_x = 20,		//�v���C���[�̑���  x��
		Hit_UnderLR_y = g_Player.y + 60;		//�������E�̒��S�����y���W

	Move_Hitx1 = g_Player.x + 40;//�擾������W
	Move_Hitx2 = g_Player.x - 40;//�擾������W

	//�}�W�b�N�i���o�[�̉��
	//Hit_Up_y��90�̓v���C���[�摜�̐^�񒆂���㉺�̒[�����܂ł̋���
	//Hit_LR_x��40�͉摜�̐^�񒆂��獶�E�̒[�����܂ł̋���
	//Hit_UpLR_y�͉摜�̐^�񒆂���ォ���܂ł̋����̔���

	/*
	�����蔻��̃C���\�W

	   Left_High��	�@�@	��Rght_High
					�@��Hit_Up
		  LeftUp��			��RightUp
	Move_Hit2��				   ��Move_Hit1
	�@ LeftUnder��			��RightUnder
			Under2��	�@��Under

	*/

	/************************************************************************
	*�����蔻��ӏ��̐F���擾
	*************************************************************************/
	g_Player.Hit_Rght_High = GetPointColor(Hit_R_x, Hit_UpLR_y - 50);		//�E��
	g_Player.Hit_Left_High = GetPointColor(Hit_L_x, Hit_UpLR_y - 50);		//�E��
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

	/************************************************************************
	**
	**		�v���C���[�̓���
	**
	*************************************************************************/
	if (g_Player.PLAYER_MENU == FALSE && g_Player.Hit_Up != g_Player.NowColor) {//���j���[��ʂ���Ă���Ƃ�,�F���d�Ȃ��Ă��Ȃ��Ƃ�
		/************************************************************************
		*�v���C���[�̈ړ�����
		*************************************************************************/
		if (g_Pad.KEY_RIGHT == TRUE || g_Pad.KEY_LEFT == TRUE)	//�E�����ɓ��͂���Ă�����
		{
			//�������̉��A�}�b�v�[�𒴂��Ȃ��悤�ɂ��鏈��_______________________________________
			if (CheckSoundMem(g_Snd.Walk) == 0 && g_Player.PLAYER_JUMP == FALSE) {//����炷
				PlaySoundMem(g_Snd.Walk, DX_PLAYTYPE_BACK);
			}
			if (g_Player.x < g_MapC.X1) {		//�}�b�v�[�Ńv���C���[����ʂ����������Ă��܂��̂�h�~�A���[�ɓ��B
				g_Player.x = g_MapC.X1;
			}
			if (g_Player.x > g_MapC.X2) {		//�}�b�v�[�Ńv���C���[����ʂ����������Ă��܂��̂�h�~�A�E�[�ɓ��B
				g_Player.x = g_MapC.X2;
			}
			//_____________________________________________________________________________________

		/************************************************************************
		*�����蔻�菈�� & �{�b�N�X�𓮂���
		*************************************************************************/

		//�E���̓����蔻�菈��______________________________________________________________
			if (RightOK == TRUE) {
				if (g_Pad.KEY_RIGHT)
					g_Player.x += PLAYERX;
				//�u���b�N����������_____________________________________________________________
				if (g_Pad.KEY_B == TRUE && g_Player.Move_Hit1 == MOVE && g_Player.NowColor == g_Player.Hit_RightUnder
					&& g_Player.PLAYER_GROUND == TRUE) {//�E���ɓ����u���b�N����������
					if (g_Pad.KEY_RIGHT == TRUE)
						MoveObjectValue(g_Player.NowColor);
				}
			}
			//�u���b�N����������___________________________________________________________________
			else if (g_Pad.KEY_B == TRUE && g_Player.Move_Hit1 == MOVE && g_Player.NowColor == g_Player.Hit_RightUnder
				&& g_Player.PLAYER_GROUND == TRUE) {//�E���ɓ����u���b�N����������
				if (g_Pad.KEY_LEFT == TRUE && g_Player.NowColor != g_Player.Hit_LeftUnder ||
					g_Pad.KEY_RIGHT == TRUE) {
					MoveObjectValue(g_Player.NowColor);
				}
			}


			//�����̓����蔻�菈��________________________________________________
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
			//�u���b�N����������_________________________________________________
			else if (g_Pad.KEY_B == TRUE && g_Player.Move_Hit2 == MOVE && g_Player.NowColor == g_Player.Hit_LeftUnder
				&& g_Player.PLAYER_GROUND == TRUE) {//�����ɓ����u���b�N����������
				if (g_Pad.KEY_RIGHT == TRUE && g_Player.NowColor != g_Player.Hit_RightUnder ||
					g_Pad.KEY_LEFT == TRUE) {
					MoveObjectValue(g_Player.NowColor);
				}
			}
			//********************************************************************************************

			//�����������鉹���~�߂�___________________________________________________
			if ((g_Pad.KEY_B == FALSE) && (CheckSoundMem(g_Snd.BoxDrag) == 1)) {
				StopSoundMem(g_Snd.BoxDrag);
			}
			//���𓮂����Ă���t���O�����Z�b�g����____________________________________________
			if (CheckSoundMem(g_Snd.BoxDrag) == 0 
				&& (g_Player.PLAYER_MOVEBOX_PUSH == TRUE || g_Player.PLAYER_MOVEBOX_PULL == TRUE)) {
				g_Player.PLAYER_MOVEBOX_PUSH = FALSE;
				g_Player.PLAYER_MOVEBOX_PULL = FALSE;

			}
			//_________________________________________________________________________________________
			animecnt++;//�A�j���[�V�����p�̃J�E���g�v���X
			NoMove = 1;//�����Ă���Ƃ��̃t���O
		}
	/************************************************************************
	*�����Ă��Ȃ�����
	*************************************************************************/
		else {
			NoMove = 0;//�����Ă��Ȃ�
			animecnt = 0;//�A�j���[�V�������~�߂�
			if (CheckSoundMem(g_Snd.Walk) == 1) {//�����~�߂�
				StopSoundMem(g_Snd.Walk);
			}
		}
	/************************************************************************
	*�d�͂̏���
	*************************************************************************/
		//�v���C���[���n�ʂɂ��Ă��Ȃ��Ƃ�
		if (!((g_Player.Hit_Under == g_Player.NowColor || g_Player.Hit_Under2 == g_Player.NowColor) ||
			(g_Player.Hit_Under == BLACK || g_Player.Hit_Under2 == BLACK))) {
			g_Player.y += Gravity;		//�v���C���[�ɏd�͂�ǉ�
			g_Player.PLAYER_GROUND = FALSE;
		}
		else {
			JumpOkflag = 0;	//�n�ʂɂ��Ă���̂ŃW�����v���Ă��Ȃ�
			g_Player.PLAYER_GROUND = TRUE;
		}
		DrawFormatString(0, 100, 0xff0fff, "Gravity %d ", Gravity);

	/************************************************************************
	*�v���C���[�̃W�����v����
	*************************************************************************/
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
				PlaySoundMem(g_Snd.Landing, DX_PLAYTYPE_BACK);
			}
			if (g_Player.Hit_Up == BLACK) {	//�v���C���[���V��ɂԂ�������,�W�����v�������I������
				g_Player.PLAYER_JUMP = FALSE;//�W�����v�����̏I��
				Jumpcnt = 20;				//�W�����v�A�j���[�V�����̃J�E���g��0�ɂ���
				JumpOkflag = 0;	//��x�W�����v�����̂ŏI���܂ŃW�����v����
			}
		}
	}

	/************************************************************************
	**
	**		�v���C���[�̕`��
	**
	*************************************************************************/

	static int
		anime_motionMax = 0,//�v���C���[�̕`��ɍ��킹�ĉ摜�̂ǂ̗�̃v���C���[��`�悷�邩�̕ϐ�
		anime_JumpMax = 9,//�W�����v�A�j���[�V�����̂ǂ��܂ł��摜����`�悷�邩�̍ő�l�̕ϐ�
		anime_PushMax = 14,//�������[�V����
		anime_PullMax = 16;//�������[�V����

	//�W�����v���Ă���Ƃ�_________________________________________
	if (g_Player.PLAYER_JUMP == TRUE) {			
		g_Player.Anime_Num = 5;		//�摜�̕`��̊J�n�ʒu�̐ݒ�
		anime_motionMax = 1;		//�摜�̕����̍ő�l�̐ݒ�(4���̉摜)
		NoMove = 0;
	}
	//�ʏ�̕����Ă���Ƃ�_______________________________________________________
	else {										
		anime_motionMax = 4;		//�摜�̕����̍ő�l�̐ݒ�(3���̉摜)
		g_Player.Anime_Num = 0;		//�摜�̕`��̊J�n�ʒu�̐ݒ�
	}
	//���������Ă��鎞___________________________________________________________
	if (g_Player.PLAYER_MOVEBOX_PUSH == TRUE) {
		g_Player.Anime_Num = 10;		//�摜�̕`��̊J�n�ʒu�̐ݒ�
		anime_motionMax = 4;			//�摜�̕����̍ő�l�̐ݒ�(3���̉摜)
		NoMove = 0;
	}
	//���������Ă��鎞___________________________________________________________
	if (g_Player.PLAYER_MOVEBOX_PULL == TRUE) {
		g_Player.Anime_Num = 15;		//�摜�̕`��̊J�n�ʒu�̐ݒ�
		anime_motionMax = 4;			//�摜�̕����̍ő�l�̐ݒ�(3���̉摜)
		NoMove = 0;
	}
	Change(g_Player.NowColor);//�����ɐF�̖��O/���������Ēl��ύX
	//														10�t���[�����ƂɁA�v���C���[�̓����ɍ��킹�ē�����
	DrawRotaGraph(g_Player.x, g_Player.y, 0.7, 0, g_pic.Player[animecnt / 9 % anime_motionMax + g_Player.Anime_Num + NoMove], TRUE, g_Player.PLAYER_DIRECTION);//�v���C���[�摜�̕`��
	ColorReset();//��ʑS�̂̕ϐF�����ɖ߂�
	//_____________________________________________________________________________________________________________________
	return 0;
}