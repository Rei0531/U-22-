#include "DxLib.h"
#include "Map.h"
#include "Controller.h"

extern MapCoordinate g_MapC;
extern Controller g_Pad;
MapCoordinate g_MapC;
image g_pic;

int Map(void) {			//�}�b�v�摜�̕`��
	if (g_Pad.KEY_RIGHT == TRUE) {	//�v���C���[�̈ړ��ɍ��킹���X�N���[������
		g_MapC.X1 -= PLAYERX;
		g_MapC.X2 -= PLAYERX;
	}
	if (g_Pad.KEY_LEFT == TRUE) {
		g_MapC.X1 += PLAYERX;
		g_MapC.X2 += PLAYERX;
	}
	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//�}�b�v�̕`��
	return 0;
}