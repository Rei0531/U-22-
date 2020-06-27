#pragma once
#include "DxLib.h"
#include "Player.h"

extern Player g_Player;

int GetObjectFlag();

int GetObjectFlag() {
	g_Player.PLAYER_PICKUP = FALSE;			//�X�|�C�g�t���O��FALSE�ɂ���
	//�v���C���[�̌����Ă���������+-50�����Ƃ��납�F���擾����
	g_Player.PickUpPixel = (g_Player.PLAYER_DIRECTION) ? g_Player.x - 50 : g_Player.x + 50;

	int color, r, g, b;
	int ret;

	DrawBox(g_Player.PickUpPixel-5, g_Player.y-5, g_Player.PickUpPixel+5, g_Player.y+5, 0xff00ff,FALSE);	//�X�|�C�g���Ă���ꏊ�̎l�p�\��

	color = GetPixel(g_Player.PickUpPixel, g_Player.y);		//�X�|�C�g����/�����̓X�|�C�g����ꏊ
	GetColor2(color, &r, &g, &b);
	switch (r+g+b) {
	case 255:
		ret = 0;
		return  RED;
		break;
	case 420:
		ret = 1;
		return ORENGE;
		break;
	case 510:
		ret = 2;
		return YELLOW;
		break;
	case 128:
		ret = 3;
		return GREEN;
		break;
	case 509:
		ret = 4;
		return LIGHTBLUE;
		break;
	case 254:
		ret = 5;
		return BLUE;
		break;
	case 256:
		ret = 6;
		return PURPLE;
		break;
	default:
		ret = 99;
		return 99;
		break;
	}
	DrawFormatString(0, 40, 0xff0000, "�F�ԍ� %d ", ret);

	return -1;
}
