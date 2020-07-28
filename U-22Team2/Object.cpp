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

int GetPointColor(int Point_x, int Point_y) {	//�n���ꂽ���W�̐F���擾���ĕԂ�
	int color, r, g, b;
	int getcolor = 99;		//���擾����F�i�[�ϐ�

	color = GetPixel(Point_x, Point_y);		//�X�|�C�g����/�����̓X�|�C�g����ꏊ
	GetColor2(color, &r, &g, &b);							//�X�|�C�g�����F��R,G,B�l�ɒ���
	int colorsum = r + g + b;
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
	//DrawRotaGraph(g_Player.PickUpPixel, g_Player.PickUpPixely,1.0,0,g_pic.Pin,TRUE,FALSE);
	if (g_Player.PLAYER_PICKUP == TRUE) {//�X�|�C�g���ꂽ�Ƃ�
		g_Player.PLAYER_PICKUP = FALSE;			//TRUE�ɂȂ��Ă��̊֐��ɓ��邩���x�����̏����ɂ��邽�߂ɃX�|�C�g�t���O��FALSE�ɂ���
		if ((g_Player.Hit_Up == getcolor) | (SaveColor == getcolor )|| (getcolor == WHITE) || (getcolor == BLACK)) {
			g_Door.Picupflg = FALSE;	//�X�|�C�g�����F���v���C���[�Ɠ��F�Ȃ�FALSE�ɂ���
		}
		if (g_Player.Hit_Up == getcolor || getcolor == WHITE || getcolor == BLACK  || getcolor == MOVE ||
			(g_Door.x < g_Player.PickUpPixel && g_Door.w > g_Player.PickUpPixel &&
				g_Door.y < g_Player.PickUpPixely && g_Door.h > g_Player.PickUpPixely)) {
			////�v���C���[���d�Ȃ��Ă���ʒu�̐F�Ǝ擾�����F���������������A�擾�����F�����F�̎�,���F�̎��A�h�A�̈ʒu�̎�
			Interact(FALSE);//�X�|�C�g���s
			g_Door.Picupflg = FALSE;	//�X�|�C�g�����F���v���C���[�Ɠ��F�Ȃ�FALSE�ɂ���
			return SaveColor; //���݂̐F��Ԃ�
		}
		if (SaveColor != getcolor && getcolor != MOVE) {//�擾�����F�����ݎ����Ă��鎩�g�̐F�ƈႤ��
			g_Door.Picupflg = TRUE;				//�h�A�̃��[�e�[�V�������߂̃X�|�C�g�̃t���O��TRUE�ɂ���
			Interact(TRUE);//�X�|�C�g����
		}
		else {
			Interact(FALSE);
		}
	}

	if (SaveColor != getcolor) {//���݂̐F�Ǝ擾�����F���Ⴄ�Ƃ�
		//�C���^���N�g����������`��
		return getcolor;		//�擾�����F��Ԃ�
	}
	else {
		//�C���^���N�g���Ă��Ȃ�������`��
		return SaveColor;//�����F�̏ꍇ�͌��̐F��Ԃ�
	}
}

int GetObjectColor(void) {
	//�v���C���[�̌����Ă���������+-50�����Ƃ��납�F���擾����
	g_Player.PickUpPixel = (g_Player.PLAYER_DIRECTION) ? g_Player.x - 30 : g_Player.x + 30l;//�X�|�C�g����ꏊ
	g_Player.PickUpPixely = g_Player.y - 33;
	SaveColor = g_Player.NowColor;		//�ꎞ�ϐ��Ɍ��݂̐F���i�[����

	return GetPointColor(g_Player.PickUpPixel, g_Player.PickUpPixely);
}

void MoveObjectValue(int P_Color) {
	static int dir = 1;//�����ɂ����*-1���邩�炻�̂��߂̕ϐ�
	//g_Player.PLAYER_DIRECTION ? dir = -1 : dir = 1;//�v���C���[��TURE(������)�Ȃ�}�C�i�X�AFALSE(�E����)�Ȃ�v���X�A
	//if (g_Pad.KEY_RIGHT && (g_Player.Move_Hit1 == MOVE && (g_Player.Hit_RightUnder == g_Player.NowColor || g_Player.Hit_RightUp == g_Player.NowColor))) {
	//	dir = 1;
	//}
	//if (g_Pad.KEY_LEFT && (g_Player.Move_Hit2 == MOVE && (g_Player.Hit_LeftUnder == g_Player.NowColor || g_Player.Hit_LeftUp == g_Player.NowColor))) {
	//	dir = -1;
	//}
	//if (g_Player.Move_Hit1 == MOVE && g_Player.Hit_LeftUnder != g_Player.NowColor && g_Pad.KEY_LEFT == TRUE) {
	//	dir = -1;
	//}
	//if (g_Player.Move_Hit2 == MOVE && g_Player.Hit_RightUnder != g_Player.NowColor && g_Pad.KEY_RIGHT == TRUE) {
	//	dir = 1;
	//}
	
	g_Pad.KEY_LEFT ? dir = -1 : dir = 1;//�v���C���[��TURE(������)�Ȃ�}�C�i�X�AFALSE(�E����)�Ȃ�v���X�A

	switch (P_Color) {		//�v���C���[�̐F�ɍ��킹�ē������I�u�W�F�N�g�����߂�
	case RED:
		g_Object.RED_x += PLAYERX * dir ;
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