#include "Gimmick.h"
#include "Color.h"
#include"Player.h"
#include "LoadPic.h"
#include "LoadSound.h"

extern image g_pic;
extern Player g_Player;
GimmickAll gim;
extern Sound g_Snd;

int i = 0;

int Shower(void) {		//塗りつぶしをするシャワーの処理
	
	gim.shower_x = gim.shower_X+95;
	gim.shower_y = gim.shower_Y;
	gim.shower_w = gim.shower_x+35;
	gim.shower_h = gim.shower_y+256;


	Change2(gim.shower_C);
	DrawGraph(gim.shower_X, gim.shower_Y,g_pic.shower, TRUE);

	if (((gim.shower_x < g_Player.x) & (gim.shower_w > g_Player.x)) & 
		((gim.shower_y < g_Player.y) & (gim.shower_h > g_Player.y))) {	//塗りつぶしの判定
		
		
			DrawGraph(gim.shower_X, gim.shower_Y + 10 * i, g_pic.shower_m, TRUE);
		
			g_Player.NowColor = gim.shower_C;
			PlaySoundMem(g_Snd.Shower, DX_PLAYTYPE_BACK); //範囲内なら音を流す
	}
	else {
		StopSoundMem(g_Snd.Shower); //範囲外に行ったら音を止める
	}


	return 0;
}