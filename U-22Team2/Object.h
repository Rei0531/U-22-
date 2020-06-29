#pragma once
#include "DxLib.h"
#include "Player.h"

extern Player g_Player;

int GetObjectColor();
int GetPointColor(int Point_x,int Point_y);

int GetPointColor(int Point_x, int Point_y) {	//�n���ꂽ���W�̐F���擾���ĕԂ�
	int color, r, g, b;
	color = GetPixel(Point_x, Point_y);		//�X�|�C�g����/�����̓X�|�C�g����ꏊ
	GetColor2(color, &r, &g, &b);							//�X�|�C�g�����F��R,G,B�l�ɒ���
	switch (r + g + b) {		//R,G,B�̍��v�ŋ�ʂ���/�X�|�C�g�����F��return�ŕԂ�
	case 255:
		return  RED;
		break;
	case 420:
		return ORENGE;
		break;
	case 510:
		return YELLOW;
		break;
	case 128:
		return GREEN;
		break;
	case 509:
		return LIGHTBLUE;
		break;
	case 254:
		return BLUE;
		break;
	case 256:
		return PURPLE;
		break;
	default:
		return 99;
		break;
	}
}

int GetObjectColor() {
	g_Player.PLAYER_PICKUP = FALSE;			//TRUE�ɂȂ��Ă��̊֐��ɓ��邩���x�����̏����ɂ��邽�߂ɃX�|�C�g�t���O��FALSE�ɂ���
	//�v���C���[�̌����Ă���������+-50�����Ƃ��납�F���擾����
	g_Player.PickUpPixel = (g_Player.PLAYER_DIRECTION) ? g_Player.x - 50 : g_Player.x + 50;//�X�|�C�g����ꏊ

	return GetPointColor(g_Player.PickUpPixel, g_Player.y);
}
