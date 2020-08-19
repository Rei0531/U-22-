#include"Gimmick.h"
#include "DxLib.h"
#include "LoadPic.h"
#include "Color.h"
#include"Player.h"
#include "LoadSound.h"

extern image g_pic;
extern Player g_Player;
extern GimmickAll gim;
extern Sound g_Snd;

int kaihuku(int x, int y) {

	int w = x + 50,
		h = y + 50;


	if (gim.item_flg > 0) {
		Change2(YELLOW);
		DrawGraph(x, y, g_pic.item, TRUE);	//flgが1以上なら描画


		if ((x <= g_Player.x && w >= g_Player.x) &&		//アイテムの座標にプレイヤーがいた時
			y <= g_Player.y + 60 && h >= g_Player.y + 60) {

			g_Player.Interact += 1;			//スポイトの回数を一回増やす
			gim.item_flg -= 1;
			PlaySoundMem(g_Snd.HeartGet, DX_PLAYTYPE_BACK);

		}
	}

	return 0;
}
