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

int Shower(void) {		//“h‚è‚Â‚Ô‚µ‚ğ‚·‚éƒVƒƒƒ[‚Ìˆ—
	
	gim.shower_x = gim.shower_X+95;
	gim.shower_y = gim.shower_Y;
	gim.shower_w = gim.shower_x+35;
	gim.shower_h = gim.shower_y+256;


	Change2(gim.shower_C);
	DrawGraph(gim.shower_X, gim.shower_Y,g_pic.shower, TRUE);

	if (((gim.shower_x < g_Player.x) & (gim.shower_w > g_Player.x)) & 
		((gim.shower_y < g_Player.y) & (gim.shower_h > g_Player.y))) {	//“h‚è‚Â‚Ô‚µ‚Ì”»’è
		
		
			DrawGraph(gim.shower_X, gim.shower_Y + 10 * i, g_pic.shower_m, TRUE);
		
			g_Player.NowColor = gim.shower_C;
			if (CheckSoundMem(g_Snd.Shower) == 0){ 
				PlaySoundMem(g_Snd.Shower, DX_PLAYTYPE_BACK); //”ÍˆÍ“à‚È‚ç‰¹‚ğ—¬‚·
			}
	}
	else {
		StopSoundMem(g_Snd.Shower);
	}


	return 0;
}

int Shower2(int k) {

	int flg = 0;

	for (int i = 0; i < k; i++) {

		gim.shower_x2[i] = gim.shower_X2[i] + 95;
		gim.shower_y2[i] = gim.shower_Y2[i];
		gim.shower_w2[i] = gim.shower_x2[i] + 35;
		gim.shower_h2[i] = gim.shower_y2[i] + 256;


		Change2(gim.shower_C2[i]);
		DrawGraph(gim.shower_X2[i], gim.shower_Y2[i], g_pic.shower, TRUE);

		if (((gim.shower_x2[i] < g_Player.x) & (gim.shower_w2[i] > g_Player.x)) &
			((gim.shower_y2[i] < g_Player.y) & (gim.shower_h2[i] > g_Player.y))) {	//“h‚è‚Â‚Ô‚µ‚Ì”»’è

			flg = 1;

			DrawGraph(gim.shower_X2[i], gim.shower_Y2[i] + 10 * i, g_pic.shower_m, TRUE);

			g_Player.NowColor = gim.shower_C2[i];
			if (CheckSoundMem(g_Snd.Shower) == 0) {
				PlaySoundMem(g_Snd.Shower, DX_PLAYTYPE_BACK); //”ÍˆÍ“à‚È‚ç‰¹‚ğ—¬‚·
			}
		}
	}

	if (flg == 0) {

		StopSoundMem(g_Snd.Shower);
	}

	return 0;
}