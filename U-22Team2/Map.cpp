#include "DxLib.h"
#include "Map.h"
#include "Controller.h"

extern MapCoordinate g_MapC;
extern Controller g_Pad;
MapCoordinate g_MapC;
image g_pic;
extern Controller g_Pad;

int Map(void) {			//�}�b�v�摜�̕`��

	//�v���C���[�̈ړ��ɍ��킹���X�N���[������_____________________________________________________________________________________________________________________
	if (g_Pad.KEY_RIGHT == TRUE) {		//�v���C���[���E�Ɉړ��B�}�b�v�͍��ɃX�N���[��
		if (g_MapC.X2 > SCREEN_WIDHT && g_MapC.MAP_MAX == FALSE) {
			g_MapC.X1 -= PLAYERX;
			g_MapC.X2 -= PLAYERX;
		}
		else {
			g_MapC.MAP_MAX = TRUE;		//�}�b�v�[�ɓ���
		}
	}
	if (g_Pad.KEY_LEFT == TRUE) {		//�v���C���[�����Ɉړ��B�}�b�v�͉E�ɃX�N���[��
		if (g_MapC.X1 < 0 && g_MapC.MAP_MAX == FALSE) {
			g_MapC.X1 += PLAYERX;
			g_MapC.X2 += PLAYERX;
		}
		else{
			g_MapC.MAP_MAX = TRUE;		//�}�b�v�[�ɓ���
		}
	}
	//_____________________________________________________________________________________________________________________
	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//�}�b�v�̕`��
	return 0;
}