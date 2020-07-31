#include "Gimmick.h"
#include "LoadPic.h"
#include "Color.h"
#include "Controller.h"
#include "Player.h"

extern Controller g_Pad;
extern image g_pic;
extern Player g_Player;
extern GimmickAll gim;

int Bomb(void) {

	if (g_Pad.KEY_B == TRUE &&
		g_Player.x > 700 && g_Player.x < 730 && gim.g_Bomb == 0) {		//���e�̎��ӂŃC���^���N�g�������Ɣ��e���E��
		gim.g_Bomb = 1;
		Change(WHITE);
		//DrawExtendGraph(700, 638, 730, 668, g_pic.Bomb, TRUE);
	}
	
	if (gim.g_Bomb == 1 && g_Pad.KEY_B == TRUE &&
		g_Player.x > 770 && g_Player.x < 799) {							//�ǂ̎��ӂŎg���Ə���
		gim.g_Bomb = 2;
	}

	if (gim.g_Bomb == 1) {
		DrawExtendGraph(g_Player.x -25, g_Player.y - 125, g_Player.x + 25, g_Player.y - 75, g_pic.Bomb, TRUE);
	}
	if (gim.g_Bomb == 0) {
		DrawExtendGraph(700, 618, 750, 668, g_pic.Bomb, TRUE);					//���e�`��
	}
	if (gim.g_Bomb != 2) {
		Change(NONCOLOR);
		DrawBox(800, 0, 850, 669, 0xffffff, TRUE);						//�󂹂�ǂ̕`��
	}


	Change(NONCOLOR);
	DrawFormatString(50, 100, 0xffffff, "Bomb = %d", gim.g_Bomb);

	return 0;
}