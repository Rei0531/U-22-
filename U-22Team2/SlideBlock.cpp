#include "Color.h"
#include"Player.h"
#include "LoadPic.h"
#include "Gimmick.h"
#include "SlaidBlock.h"

extern image g_pic;
extern Player g_Player;
//extern SlideFunction g_SlaF;
extern GimmickAll gim;


int SlideBlock(int SlaColor)
{

	if (((g_Player.x + 30 < gim.SliObjx1 + gim.move_x) &&
		(g_Player.x + 30 < gim.SliObjx2 + gim.move_x)) ||
		((g_Player.x - 30 > gim.SliObjx1 + gim.move_x) &&
		(g_Player.x - 30 > gim.SliObjx2 + gim.move_x))) {
		if (((g_Player.y + 70 <= gim.SliObjy1) &&
			(g_Player.y - 70 <= gim.SliObjy1)) ||
			((g_Player.y + 70 != gim.SliObjy2) &&
			(g_Player.y - 70 != gim.SliObjy2))) {
			gim.move_x -= gim.Speed;
			if (gim.move_cnt++ > gim.move_max) {
				gim.move_cnt = 0;
				gim.Speed = gim.Speed * (-1);
			}
		}
	}

	Change(SlaColor);
	DrawExtendGraph(gim.SliObjx1 + gim.move_x, gim.SliObjy1, gim.SliObjx2 + gim.move_x, gim.SliObjy2, g_pic.Box[4], TRUE);//������

	if ((g_Player.x + 15 >= gim.SliObjx1 + gim.move_x) && (g_Player.x - 15 <= gim.SliObjx2 + gim.move_x) &&
		(g_Player.Hit_Under == g_Player.NowColor && g_Player.NowColor == SlaColor)) {
		g_Player.x -= gim.Speed;		//�v���C���[�������œ�����
	}

	DrawExtendGraph(gim.GetObjx1, gim.GetObjy1, gim.GetObjx2, gim.GetObjy2, g_pic.Box[0], TRUE);//�F���p�̃u���b�N

	ColorReset();

	return 0;
}