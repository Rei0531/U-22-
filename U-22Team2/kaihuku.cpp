#include"Gimmick.h"
#include "DxLib.h"
#include "LoadPic.h"
#include "Color.h"
#include"Player.h"

extern image g_pic;
extern Player g_Player;
extern GimmickAll gim;

int kaihuku(int x, int y) {

	int w = x + 50,
		h = y + 50;


	if (gim.item_flg > 0) {
		Change2(YELLOW);
		DrawGraph(x, y, g_pic.item, TRUE);	//flg��1�ȏ�Ȃ�`��


		if ((x <= g_Player.x && w >= g_Player.x) &&		//�A�C�e���̍��W�Ƀv���C���[��������
			y <= g_Player.y + 60 && h >= g_Player.y + 60) {

			g_Player.Interact += 1;			//�X�|�C�g�̉񐔂���񑝂₷
			gim.item_flg -= 1;

		}
	}

	return 0;
}
