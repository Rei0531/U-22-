#include "Player.h"
#include "Color.h"
#include"Door.h"
#include"Interact.h"
#include "Object.h"
#include "Controller.h"
#include "LoadSound.h"

extern Player g_Player;
extern DoorAll g_Door;
extern Object g_Object;
extern Controller g_Pad;
extern Sound g_Snd;

static int SaveColor = 99;		//�ꎞ�ϐ��Ɍ��݂̐F���i�[����

/************************************************************************
*�n���ꂽ���W�̐F���擾���ĕԂ�
*************************************************************************/
int GetPointColor(int Point_x, int Point_y) {
	int color, r, g, b;
	int getcolor = 9;		//���擾����F�i�[�ϐ�

	//�����蔻��̏ꏊ�̐F���擾******************************************************************************
	color = GetPixel(Point_x, Point_y);		//�X�|�C�g����/�����̓X�|�C�g����ꏊ
	GetColor2(color, &r, &g, &b);							//�X�|�C�g�����F��R,G,B�l�ɒ���
	int colorsum = r + g + b;
	//********************************************************************************************************

	switch (colorsum) {		//R,G,B�̍��v�ŋ�ʂ���/�X�|�C�g�����F��return�ŕԂ�
	case 255:
		getcolor = RED;
		break;
	case 420:
		getcolor = ORENGE;
		break;
	case 510:
		getcolor = YELLOW;
		break;
	case 128:
		getcolor = GREEN;
		break;
	case 509:
		getcolor = LIGHTBLUE;
		break;
	case 254:
		getcolor = BLUE;
		break;
	case 256:
		getcolor = PURPLE;
		break;
	case 0:
		getcolor = BLACK;
		break;
	case 765:
		getcolor = WHITE;
		break;
	//MOVE�̒l���Ƃ邽�߂�RGB�l���U�ȉ��̎��̏����ɂ��������ǁA�����l����̖ʓ|�����炢������
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		getcolor = MOVE;
		break;
	default:
		//getcolor = SaveColor;
		break;
	}

	//�X�|�C�g���ꂽ�Ƃ�********************************************************************************************************
	if (g_Player.PLAYER_PICKUP == TRUE) {
		g_Player.PLAYER_PICKUP = FALSE;			//TRUE�ɂȂ��Ă��̊֐��ɓ��邩���x�����̏����ɂ��邽�߂ɃX�|�C�g�t���O��FALSE�ɂ���
		//if (g_Object.PixelColor1 != WHITE)g_Object.PixelColor = g_Object.PixelColor1;
		//if (g_Object.PixelColor4 != WHITE)g_Object.PixelColor = g_Object.PixelColor4;
		//if (g_Object.PixelColor2 != WHITE)g_Object.PixelColor = g_Object.PixelColor2;
		//if (g_Object.PixelColor3 != WHITE)g_Object.PixelColor = g_Object.PixelColor3;

		if ((g_Player.Hit_Up == getcolor) || (SaveColor == getcolor) || (getcolor == WHITE) || (getcolor == BLACK)) {
			g_Door.Picupflg = FALSE;	//�X�|�C�g�����F���v���C���[�Ɠ��F�Ȃ�FALSE�ɂ���
		}
		//�v���C���[���d�Ȃ��Ă���ʒu�̐F�Ǝ擾�����F���������������A�擾�����F�����F�̎�,���F�̎��A�h�A�̈ʒu�̎�
		if (getcolor == WHITE || getcolor == BLACK || getcolor == MOVE || g_Player.Interact <= 0 || 
			(g_Door.x <= g_Player.PickUpPixel && g_Door.w >= g_Player.PickUpPixel &&
				g_Door.y <= g_Player.PickUpPixely && g_Door.h >= g_Player.PickUpPixely)) {
			Interact(FALSE);//�X�|�C�g���s
			g_Door.Picupflg = FALSE;	//�X�|�C�g�����F���v���C���[�Ɠ��F�Ȃ�FALSE�ɂ���
			return SaveColor; //���݂̐F��Ԃ�
		}
		if (SaveColor != getcolor) {//�擾�����F�����ݎ����Ă��鎩�g�̐F�ƈႤ��
			g_Door.Picupflg = TRUE;				//�h�A�̃��[�e�[�V�������߂̃X�|�C�g�̃t���O��TRUE�ɂ���
			Interact(TRUE);//�X�|�C�g����
			//g_Player.NowColor = g_Object.PixelColor;//�ϐ��ɃX�|�C�g�����F���i�[����
		}
		else {
			Interact(FALSE);
		}
	}
	//********************************************************************************************************

	if (SaveColor != getcolor) {//���݂̐F�Ǝ擾�����F���Ⴄ�Ƃ�
		//�C���^���N�g����������`��
		return getcolor;		//�擾�����F��Ԃ�
	}
	else {
		//�C���^���N�g���Ă��Ȃ�������`��
		return SaveColor;//�����F�̏ꍇ�͌��̐F��Ԃ�
	}
}
/************************************************************************
*�X�|�C�g����
*************************************************************************/
int GetObjectColor(void) {
	//�v���C���[�̌����Ă���������+-50�����Ƃ��납�F���擾����
	//g_Player.PickUpPixel = (g_Player.PLAYER_DIRECTION) ? g_Player.x - 40 : g_Player.x + 40;//�X�|�C�g����ꏊ
	//g_Player.PickUpPixely = g_Player.y - 27;//�����l33�������F������悤�ɂȂ��Ă��܂�����߂�
	SaveColor = g_Player.NowColor;		//�ꎞ�ϐ��Ɍ��݂̐F���i�[����

	return GetPointColor(g_Player.PickUpPixel, g_Player.PickUpPixely);
}

/************************************************************************
*�����u���b�N�̏���
*************************************************************************/
void MoveObjectValue(int P_Color) {
	
	int dir = 0;//�����ɂ����*-1���邩�炻�̂��߂̕ϐ�

	//�E�ɔ�����������______________________________________
	if (g_Player.Move_HitR == MOVE && g_Player.NowColor == g_Player.Hit_RightUnder) {
		//�E�Ɍ������ē����Ă�����//�����Ă�Ƃ�
		if (g_Player.PLAYER_DIRECTION == FALSE && g_Player.Move_BlackR != BLACK) {
			g_Player.PLAYER_MOVEBOX_PUSH = TRUE;//�v���C���[�͉�����������Ă���
			g_Player.PLAYER_MOVEBOX_PULL = FALSE;//��������̃t���O��FALSE�ɂ���
			dir = 1;// (�E����)�Ȃ�v���X
		}
		//���Ɍ������ē����Ă�����//�����Ă��鎞
		else if(g_Player.PLAYER_DIRECTION == TRUE && g_Player.Hit_LeftUnder != BLACK && g_Player.NowColor != g_Player.Hit_LeftUnder){
			g_Player.PLAYER_MOVEBOX_PULL = TRUE;//�v���C���[�͈�����������Ă���
			g_Player.PLAYER_MOVEBOX_PUSH = FALSE;//��������̃t���O��FALSE�ɂ���
			dir = -1;//(������)�Ȃ�}�C�i�X
		}
	}

	//���ɔ�����������______________________________________
	if (g_Player.Move_HitL == MOVE && g_Player.NowColor == g_Player.Hit_LeftUnder) {
		//���Ɍ������ē����Ă�����//�����Ă�Ƃ�
		if (g_Player.PLAYER_DIRECTION == TRUE&& g_Player.Move_BlackL != BLACK) {
			g_Player.PLAYER_MOVEBOX_PUSH = TRUE;//�v���C���[�͉�����������Ă���
			g_Player.PLAYER_MOVEBOX_PULL = FALSE;//��������̃t���O��FALSE�ɂ���
			dir = -1;//(������)�Ȃ�}�C�i�X
		}
		//�E�Ɍ������ē����Ă�����//�����Ă�Ƃ�
		else if(g_Player.PLAYER_DIRECTION == FALSE && g_Player.Hit_RightUnder != BLACK && g_Player.NowColor != g_Player.Hit_RightUnder){
			g_Player.PLAYER_MOVEBOX_PULL = TRUE;//�v���C���[�͈�����������Ă���
			g_Player.PLAYER_MOVEBOX_PUSH = FALSE;//��������̃t���O��FALSE�ɂ���
			dir = 1;// (�E����)�Ȃ�v���X
		}
	}

	if (g_Pad.KEY_LEFT || g_Pad.KEY_RIGHT) {
		switch (P_Color) {		//�v���C���[�̐F�ɍ��킹�ē������I�u�W�F�N�g�����߂�
		case RED:
			g_Object.RED_x += PLAYERX * dir;
			break;
		case ORENGE:
			g_Object.ORENGE_x += PLAYERX * dir;
			break;
		case YELLOW:
			g_Object.YELLOW_x += PLAYERX * dir;
			break;
		case GREEN:
			g_Object.GREEN_x += PLAYERX * dir;
			break;
		case LIGHTBLUE:
			g_Object.LIGHTBLUE_x += PLAYERX * dir;
			break;
		case BLUE:
			g_Object.BLUE_x += PLAYERX * dir;
			break;
		case PURPLE:
			g_Object.PURPLE_x += PLAYERX * dir;
			break;
		default:
			break;
		}
	}
}