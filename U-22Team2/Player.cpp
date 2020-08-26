#include "DxLib.h"
#include "Player.h"
#include "Controller.h"
#include "Map.h"
#include "Color.h"
#include "Object.h"
#include"Door.h"
#include "Object.h"
#include "LoadSound.h"
#include <stdlib.h>

extern image g_pic;
extern Controller g_Pad;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern Sound g_Snd;
extern Object g_Object;

int anicnt = 0,	//�A�j���������ϐ�
anicntMax = 20,	//�A�j���S�̂̎���
aniy = 0,		//�w�̏㉺�A�j���p�ϐ�
anix = 0,		//�v���C���[�̌����ɂ���ĕς��X���W�p�ϐ�


const PicChangeFream = 8;
static int animecnt = 0;	//�X�|�C���g�}���A�j���[�V�����p�J�E���g�ϐ�
static int Jumpcnt = 20;	//�W�����v�����̃J�E���g
static int JumpMax = 0;		//�W�����v�����S�̂ɂ�����ő厞��
static int Sndcnt = 0;		//�����̃t���[���J�E���g�ϐ�
static int Gravity = 5;		//���t���[�����ɗ��Ƃ�
static int NoMove = 0;		//0�̎������Ă��Ȃ�1�̎������Ă���/�v���C���[�̕������[�V�����ҋ@���[�V�����؂�ւ��悤�ϐ�
static int JumpOkflag = 0;	//�󒆃W�����v�h�~�ϐ�/0���W�����v���Ă��Ȃ�/1���W�����v��
static int Move_Hitx1 = 0,	//�������ɐG��Ă��邩�̎擾����ꏊ
		   Move_Hitx2 = 0;	//�������ɐG��Ă��邩�̎擾����ꏊ

static bool Move_B = FALSE,//�������锠�̓������邩�̕ϐ�
B = FALSE;//B�{�^����x�����h�~

int PlayerDraw(void) {

	/************************************************************************
	**
	**		�X�|�C�g����
	**
	*************************************************************************/

	if (g_Player.PLAYER_PICKUP == TRUE && g_Player.Interact > 0) { //���̊֐��Ăяo���ŐF���擾
		g_Player.NowColor = GetObjectColor();//�ϐ��ɃX�|�C�g�����F���i�[����
	}
	if (g_Player.Interact <= 0)g_Player.Interact = 0;

	/*********************************************************************************************************
	*�X�|�C�g����ꏊ�̕`��
	********************************************************************************************************/
	//�X�|�C�g����ꏊ�̕`��___________________________________________________________________
	g_Player.PickUpPixel = (g_Player.PLAYER_DIRECTION) ? g_Player.x - 40 : g_Player.x + 40;//
	g_Player.PickUpPixely = g_Player.y - 27;//�����l33�������F������悤�ɂȂ��Ă��܂�����߂�

	//PixelColor�ɐF���i�[
	g_Object.PixelColor = GetPointColor(g_Player.PickUpPixel, g_Player.PickUpPixely);
	//�擾�����F�����F��������
	if (g_Object.PixelColor == WHITE) {
		//�������̍��W���擾����___________________________
		int Px1 = 5,
			Px2 = 3;

		//���p�̍��W�𔽓]�����E�����悤�ɂ���_______________________________________
		if (g_Player.PLAYER_DIRECTION == FALSE) {//�E�ނ��Ă��鎞
			Px1 *= -1;
			Px2 *= -1;
		}
		//PixelColor�̎��肩��F���擾����
		g_Object.PixelColor1 = GetPointColor(g_Player.PickUpPixel + Px1, g_Player.PickUpPixely);
		g_Object.PixelColor2 = GetPointColor(g_Player.PickUpPixel + Px2, g_Player.PickUpPixely - 3);
		g_Object.PixelColor3 = GetPointColor(g_Player.PickUpPixel, g_Player.PickUpPixely - 5);
		g_Object.PixelColor4 = GetPointColor(g_Player.PickUpPixel + Px1, g_Player.PickUpPixely - 5);
		//�w��̎擾�����F�ŗD�揇�ʂŐF�����
		if (g_Object.PixelColor1 != WHITE)g_Object.PixelColor = g_Object.PixelColor1;
		if (g_Object.PixelColor4 != WHITE)g_Object.PixelColor = g_Object.PixelColor4;
		if (g_Object.PixelColor2 != WHITE)g_Object.PixelColor = g_Object.PixelColor2;
		if (g_Object.PixelColor3 != WHITE)g_Object.PixelColor = g_Object.PixelColor3;
	}


	//�X�|�C�g�̎��\�������邩�̔��f��
	if (g_Object.PixelColor != WHITE && g_Object.PixelColor != NONCOLOR && g_Object.PixelColor != BLACK && g_Player.Interact > 0 &&
		g_Object.PixelColor != g_Player.NowColor && g_Object.PixelColor != MOVE && g_Player.PLAYER_MOVEBOX_PUSH == FALSE && g_Player.PLAYER_MOVEBOX_PULL == FALSE &&
		(!((g_Door.x - 5 < g_Player.PickUpPixel && g_Door.w + 5 > g_Player.PickUpPixel) &&
			(g_Door.y < g_Player.PickUpPixely && g_Door.h > g_Player.PickUpPixely)))) {//�擾����ꏊ�̐F��������Ȃ��Ƃ��`��

			//�X�|�C�g�̎肪�㉺����A�j���[�V��������______________
		anicnt++;

		if (anicnt > anicntMax / 2) {
			aniy += 2;
		}
		if (anicnt <= anicntMax / 2) {
			aniy -= 2;
		}
		if (anicnt >= anicntMax)anicnt = 0;
		g_Player.PLAYER_DIRECTION ? anix = 54 : anix = 10;
		//_____________________________________________________________

		//�X�|�C�g�̎�
		Change2(g_Object.PixelColor);
		DrawRotaGraph2(g_Player.PickUpPixel, g_Player.PickUpPixely + aniy, anix, 46, 1.0, 0, g_pic.Hand, TRUE, g_Player.PLAYER_DIRECTION);
		if (g_Pad.KEY_X == TRUE && g_Player.Interact > 0) {
			g_Player.NowColor = g_Object.PixelColor;
		}
	}

	//*********************************************************************************************************

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

	Move_Hitx1 = g_Player.x + 50;//�擾������W
	Move_Hitx2 = g_Player.x - 50;//�擾������W

	/*
	//   Left_High��	�@�@	��Rght_High
	�����蔻��̃C���\�W

					�@��Hit_Up
		  LeftUp��			��RightUp
	Move_Hit2��				   ��Move_Hit1
	�@ LeftUnder��			��RightUnder
			Under2��	�@��Under

	*/

	/************************************************************************
	*�����蔻��ӏ��̐F���擾
	*************************************************************************/
	g_Player.Hit_Up = GetPointColor(g_Player.x, Hit_Up_y);				//����
	if (g_Pad.KEY_RIGHT == TRUE) {
		//g_Player.Hit_Rght_High = GetPointColor(Hit_R_x, Hit_UpLR_y - 50);	//�E��
		g_Player.Hit_RightUp = GetPointColor(Hit_R_x, Hit_UpLR_y);			//�E��
		g_Player.Hit_RightUnder = GetPointColor(Hit_R_x, Hit_UnderLR_y);	//�E��
	}
	if (g_Pad.KEY_LEFT == TRUE) {
		//g_Player.Hit_Left_High = GetPointColor(Hit_L_x, Hit_UpLR_y - 50);	//����
		g_Player.Hit_LeftUp = GetPointColor(Hit_L_x, Hit_UpLR_y);			//����
		g_Player.Hit_LeftUnder = GetPointColor(Hit_L_x, Hit_UnderLR_y);		//����
	}
	g_Player.Move_HitR = GetPointColor(Move_Hitx1, g_Player.y + 25);		//�v���C���[�̒��S���W����ނ��Ă��������50�����Z�����l�̐F���擾
	g_Player.Move_HitL = GetPointColor(Move_Hitx2, g_Player.y + 25);		//�v���C���[�̒��S���W����ނ��Ă��������50�����Z�����l�̐F���擾
	g_Player.Hit_Under = GetPointColor(g_Player.x, Hit_Under_y);		//�E����
	//g_Player.Hit_Under2 = GetPointColor(g_Player.x - Hit_Under_x, Hit_Under_y);		//������
	//��������{�b�N�X���ǂ����m�邽�߂̐F���擾_________________________


	//�����蔻��̃t���O�Ǘ�_____________________________________
	//�E�s���ă��V�I
	//bool RightOK = g_Player.NowColor != g_Player.Hit_RightUp && g_Player.NowColor != g_Player.Hit_RightUnder && g_Player.NowColor != g_Player.Hit_Rght_High
	//	&& g_Player.Hit_RightUp != BLACK && g_Player.Hit_RightUnder != BLACK && g_Player.Hit_Rght_High != BLACK;
	////���s���ă��V�I
	//bool LeftOK = g_Player.NowColor != g_Player.Hit_LeftUp && g_Player.NowColor != g_Player.Hit_LeftUnder && g_Player.NowColor != g_Player.Hit_Left_High
	//	&& g_Player.Hit_LeftUp != BLACK && g_Player.Hit_LeftUnder != BLACK && g_Player.Hit_Left_High != BLACK;

	//�����蔻��ꎞ��̓�������폜�A�S�z�����珈���͂܂��R�����g�Ŏc��
	bool RightOK = g_Player.NowColor != g_Player.Hit_RightUp && g_Player.NowColor != g_Player.Hit_RightUnder
		&& g_Player.Hit_RightUp != BLACK && g_Player.Hit_RightUnder != BLACK && g_Player.Hit_RightUp != MOVE;
	//���s���ă��V�I
	bool LeftOK = g_Player.NowColor != g_Player.Hit_LeftUp && g_Player.NowColor != g_Player.Hit_LeftUnder
		&& g_Player.Hit_LeftUp != BLACK && g_Player.Hit_LeftUnder != BLACK && g_Player.Hit_LeftUp != MOVE;

	/************************************************************************
	**
	**		�v���C���[�̓���
	**
	*************************************************************************/
	if (g_Player.PLAYER_MENU == FALSE && g_Player.Hit_Up != g_Player.NowColor) {//���j���[��ʂ���Ă���Ƃ�,�F���d�Ȃ��Ă��Ȃ��Ƃ�
		/************************************************************************
		*�����蔻�菈�� & �{�b�N�X�𓮂���
		*************************************************************************/
		//B�{�^���̐؂�ւ������ׂ̗ɓ������锠�����邩
		bool MOVEOK = (g_Player.Move_HitL == MOVE && g_Player.NowColor == g_Player.Hit_LeftUnder)
			|| (g_Player.Move_HitR == MOVE && g_Player.NowColor == g_Player.Hit_RightUnder);

		//�������ɐG��Ă��锻��ɂȂ��Ă���̂ɁA���������߂��ɂȂ���
		if (Move_B == TRUE && g_Player.Move_HitL != MOVE && g_Player.Move_HitR != MOVE) {
			Move_B = FALSE;
		}

		if (g_Pad.KEY_B == TRUE && Move_B == TRUE && B == FALSE && MOVEOK == TRUE) {
			Move_B = FALSE;
			B = TRUE;
		}
		if (g_Pad.KEY_B == TRUE && Move_B == FALSE && B == FALSE && MOVEOK == TRUE) {
			Move_B = TRUE;
			B = TRUE;
		}

		//Init�������Ă΂ꂽ��A�I�u�W�F�N�g�����Ă锻�����߂�
		if (g_Player.InitFlag == TRUE) {
			Move_B = FALSE;
		}

		B = (g_Pad.KEY_B == TRUE) ? TRUE : FALSE;//B�{�^����������Ă�����/�ēxB�{�^����������悤��

		if (Move_B == TRUE && g_Player.PLAYER_GROUND == TRUE) {
			if (g_Pad.KEY_RIGHT == TRUE)g_Player.Move_BlackR = GetPointColor(Hit_R_x + 110, Hit_UnderLR_y);		//�������锠�������ǂɂ߂荞�܂Ȃ��悤�ɂނ��Ă�����ɃI�u�W�F�N�g�̔��̉���100�����Z�����l
			if (g_Pad.KEY_LEFT == TRUE)g_Player.Move_BlackL = GetPointColor(Hit_L_x - 110, Hit_UnderLR_y);		//�������锠�������ǂɂ߂荞�܂Ȃ��悤�ɂނ��Ă�����ɃI�u�W�F�N�g�̔��̉���100�����Z�����l
			MoveObjectValue(g_Player.NowColor);
		}
		//�����������鉹___________________________________________________
		if (Move_B == TRUE && CheckSoundMem(g_Snd.BoxDrag) == 0 &&
			(g_Player.PLAYER_MOVEBOX_PUSH == TRUE || g_Player.PLAYER_MOVEBOX_PULL == TRUE)
			&& (g_Pad.KEY_LEFT == TRUE || g_Pad.KEY_RIGHT == TRUE)) {
			PlaySoundMem(g_Snd.BoxDrag, DX_PLAYTYPE_BACK);
		}
		if ((g_Pad.KEY_LEFT == FALSE && g_Pad.KEY_RIGHT == FALSE) ||
			(Move_B == FALSE) && (CheckSoundMem(g_Snd.BoxDrag) == 1)) {
			StopSoundMem(g_Snd.BoxDrag);
		}
		//���𓮂����Ă���t���O�����Z�b�g����____________________________________________
		if (CheckSoundMem(g_Snd.BoxDrag) == 0
			&& (g_Player.PLAYER_MOVEBOX_PUSH == TRUE || g_Player.PLAYER_MOVEBOX_PULL == TRUE)) {
			g_Player.PLAYER_MOVEBOX_PUSH = FALSE;
			g_Player.PLAYER_MOVEBOX_PULL = FALSE;
		}
		//_________________________________________________________________________________________

		//********************************************************************************************
		/************************************************************************
		*�v���C���[�̈ړ�����
		*************************************************************************/
		if (g_Pad.KEY_RIGHT == TRUE || g_Pad.KEY_LEFT == TRUE)	//�E�����ɓ��͂���Ă�����
		{
			//�������̉��A�}�b�v�[�𒴂��Ȃ��悤�ɂ��鏈��_______________________________________
			if ((Sndcnt++ % (PicChangeFream + 6)) == 0) {
				if (g_Player.PLAYER_JUMP == FALSE && g_Player.PLAYER_GROUND == TRUE && Move_B == FALSE
					&& !((RightOK == FALSE && g_Pad.KEY_RIGHT == TRUE) || (g_Pad.KEY_LEFT == TRUE && LeftOK == FALSE))) {//����炷
					PlaySoundMem(g_Snd.Walk, DX_PLAYTYPE_BACK);
				}
			}
			if (g_Player.x < g_MapC.X1 + 20) {		//�}�b�v�[�Ńv���C���[����ʂ����������Ă��܂��̂�h�~�A���[�ɓ��B
				g_Player.x = g_MapC.X1 + 20;
			}
			if (g_Player.x > g_MapC.X2 - 20) {		//�}�b�v�[�Ńv���C���[����ʂ����������Ă��܂��̂�h�~�A�E�[�ɓ��B
				g_Player.x = g_MapC.X2 - 20;
			}
			//_____________________________________________________________________________________

			//�E���̓����蔻�菈��______________________________________________________________
			if (g_Pad.KEY_RIGHT == TRUE && RightOK == TRUE) {
				g_Player.x += PLAYERX;
			}

			//�����̓����蔻�菈��________________________________________________
			if (g_Pad.KEY_LEFT == TRUE && LeftOK == TRUE) {
				g_Player.x -= PLAYERX;
			}
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
		if (!((g_Player.Hit_Under == g_Player.NowColor) ||
			(g_Player.Hit_Under == BLACK))) {
			g_Player.y += Gravity;		//�v���C���[�ɏd�͂�ǉ�
			g_Player.PLAYER_GROUND = FALSE;
		}
		else {
			JumpOkflag = 0;	//�n�ʂɂ��Ă���̂ŃW�����v���Ă��Ȃ�
			g_Player.PLAYER_GROUND = TRUE;
		}

		/************************************************************************
		*�v���C���[�̃W�����v����
		*************************************************************************/
		if ((g_Player.PLAYER_JUMP == TRUE && ((g_Player.Hit_Under == BLACK || g_Player.Hit_Under == g_Player.NowColor))) || JumpOkflag == 1) {	//�W�����v�{�^���������ꂽ��
			Jumpcnt--;		//�W�����v�A�j���[�V�����̃J�E���g�J�n
			JumpOkflag = 1;	//��x�W�����v�����̂ŏI���܂ŃW�����v����
			if (Jumpcnt >= JumpMax) {//���߂�ꂽ���Ԃ܂Ńv���C���[����ɂ�����
				g_Player.y -= Jumpcnt;
			}
			if (Jumpcnt <= JumpMax && ((g_Player.Hit_Under == BLACK || g_Player.Hit_Under == g_Player.NowColor))) {		//�W�����v�A�j���[�V���������߂�ꂽ���ԂɂȂ����Ƃ�
				g_Player.PLAYER_JUMP = FALSE;//�W�����v�����̏I��
				Jumpcnt = 20;				//�W�����v�A�j���[�V�����̃J�E���g��0�ɂ���
				PlaySoundMem(g_Snd.Landing, DX_PLAYTYPE_BACK);
			}
			if (g_Player.Hit_Up == BLACK || g_Player.Hit_Up == g_Player.NowColor) {	//�v���C���[���V��ɂԂ�������,�W�����v�������I������
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

		if (Move_B == FALSE && ((RightOK == FALSE && g_Pad.KEY_RIGHT == TRUE) || (g_Pad.KEY_LEFT == TRUE && LeftOK == FALSE))) {
			NoMove = 0;
			animecnt = 0;
		}

		//��������G���Ă��鎞____________________________________________
		if (Move_B == TRUE && g_Pad.KEY_LEFT == FALSE && g_Pad.KEY_RIGHT == FALSE) {
			g_Player.Anime_Num = 10;		//�摜�̕`��̊J�n�ʒu�̐ݒ�
			anime_motionMax = 4;			//�摜�̕����̍ő�l�̐ݒ�(3���̉摜)
			NoMove = 0;

			//����������������
			//g_Player.PLAYER_DIRECTION = g_Player.Move_HitL == MOVE ? TRUE : FALSE;
			if (g_Player.Move_HitL == MOVE && g_Player.NowColor == g_Player.Hit_LeftUnder)g_Player.PLAYER_DIRECTION = TRUE;
			if (g_Player.Move_HitR == MOVE && g_Player.NowColor == g_Player.Hit_RightUnder)g_Player.PLAYER_DIRECTION = FALSE;

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
	}
	Change(g_Player.NowColor);//�����ɐF�̖��O/���������Ēl��ύX
	//														8�t���[�����ƂɁA�v���C���[�̓����ɍ��킹�ē�����
	DrawRotaGraph(g_Player.x, g_Player.y, 0.7, 0.0, g_pic.Player[animecnt / 8 % anime_motionMax + g_Player.Anime_Num + NoMove], TRUE, g_Player.PLAYER_DIRECTION);//�v���C���[�摜�̕`��
	//_____________________________________________________________________________________________________________________
	ColorReset();
	//�d�Ȃ����ꍇ�̒��ӕ\��
	if (g_Player.Hit_Up == g_Player.NowColor) {
		g_Player.PLAYER_MOVEOK = FALSE;//�����Ȃ���Ԃ̃t���O�ɂ���
		DrawString(450, 698, "��ς��I�I�u�W�F�N�g�Əd�Ȃ��Ă��܂����I", 0xff0000);
		DrawString(470, 718, "START�{�^����������RESET���悤", 0xffffff);
	}
	else {
		g_Player.PLAYER_MOVEOK = TRUE;//�����Ȃ���Ԃ̃t���O�ɂ���
	}
	//�����蔻��̉���_____________________________________________________________________
	//DrawBox(g_Player.x - 5, Hit_Up_y - 5, g_Player.x + 5, Hit_Up_y + 5, 0xfe00fe, FALSE);	//����
	//DrawBox(Hit_R_x - 5, Hit_UpLR_y - 5, Hit_R_x + 5, Hit_UpLR_y + 5, 0xfe00fe, FALSE);	//�E��
	//DrawBox(Hit_R_x - 5, Hit_UnderLR_y - 5, Hit_R_x + 5, Hit_UnderLR_y + 5, 0xfe00fe, FALSE);	//�E��
	//DrawBox(Hit_L_x - 5, Hit_UpLR_y - 5, Hit_L_x + 5, Hit_UpLR_y + 5, 0xfe00fe, FALSE);	//����
	//DrawBox(Hit_L_x - 5, Hit_UnderLR_y - 5, Hit_L_x + 5, Hit_UnderLR_y + 5, 0xfe00fe, FALSE);	//����
	//DrawBox(g_Player.x - 5, Hit_Under_y - 5, g_Player.x + 5, Hit_Under_y + 5, 0xfe00fe, FALSE);	//�����E
	////DrawBox(g_Player.x - 5 - Hit_Under_x, Hit_Under_y - 5, g_Player.x + 5 - Hit_Under_x, Hit_Under_y + 5, 0xfe00fe, FALSE);	//������
	//DrawBox(g_Player.PickUpPixel - 5, g_Player.PickUpPixely - 5, g_Player.PickUpPixel + 5, g_Player.PickUpPixely + 5, 0xff00ff, FALSE);
	//DrawBox(Move_Hitx1 - 5, g_Player.y + 25 - 5, Move_Hitx1 + 5, g_Player.y + 25 + 5, 0xfe00fe, FALSE);	//�����u���b�N�̎擾�ʒu�E
	//DrawBox(Move_Hitx2 - 5, g_Player.y + 25 - 5, Move_Hitx2 + 5, g_Player.y + 25 + 5, 0xfe00fe, FALSE);	//�����u���b�N�̎擾�ʒu��

	////DrawBox(Hit_R_x - 5, Hit_UpLR_y - 50 - 5, Hit_R_x + 5, Hit_UpLR_y - 50 + 5, 0xfe00fe, FALSE);	//�E��
	////DrawBox(Hit_L_x - 5, Hit_UpLR_y - 50 - 5, Hit_L_x + 5, Hit_UpLR_y - 50 + 5, 0xfe00fe, FALSE);	//�E��

	//DrawBox(Hit_R_x + 110 - 5, Hit_UnderLR_y - 5, Hit_R_x + 110 + 5, Hit_UnderLR_y + 5, 0xfe00fe, FALSE);	//�������锠�̍����ǔ���
	//DrawBox(Hit_L_x - 110 - 5, Hit_UnderLR_y - 5, Hit_L_x - 110 + 5, Hit_UnderLR_y + 5, 0xfe00fe, FALSE);	//�������锠�̍����ǔ���

	return 0;
}