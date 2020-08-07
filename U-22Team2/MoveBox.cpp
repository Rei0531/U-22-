#include "MoveBox.h"
#include "LoadPic.h"
#include "Player.h"



extern Object g_Object;
extern image g_pic;
extern Player g_Player;


void MoveBox(int color ,int x, int y) {

	Change(color);
	switch (color) {
	case RED:
		DrawExtendGraph(x + g_Object.RED_x, y, x + 100 + g_Object.RED_x, y + 100, g_pic.Box_Move, TRUE);
		break;
	case ORENGE:
		DrawExtendGraph(x + g_Object.ORENGE_x, y, x + 100 + g_Object.ORENGE_x, y + 100, g_pic.Box_Move, TRUE);
		break;
	case YELLOW:
		DrawExtendGraph(x + g_Object.YELLOW_x, y, x + 100 + g_Object.YELLOW_x, y + 100, g_pic.Box_Move, TRUE);
		break;
	case GREEN:
		DrawExtendGraph(x + g_Object.GREEN_x, y, x + 100 + g_Object.GREEN_x, y + 100, g_pic.Box_Move, TRUE);
		break;
	case LIGHTBLUE:
		DrawExtendGraph(x + g_Object.LIGHTBLUE_x, y, x + 100 + g_Object.LIGHTBLUE_x, y + 100, g_pic.Box_Move, TRUE);
		break;
	case BLUE:
		DrawExtendGraph(x + g_Object.BLUE_x, y, x + 100 + g_Object.BLUE_x, y + 100, g_pic.Box_Move, TRUE);
		break;
	case PURPLE:
		DrawExtendGraph(x + g_Object.PURPLE_x, y, x + 100 + g_Object.PURPLE_x, y + 100, g_pic.Box_Move, TRUE);
		break;
	}
}


void frontMoveBox(int color, int x, int y) {
	//プレイヤーの色と同じブロックを手前に出す_______________________________________________________________
	if (g_Player.NowColor == color) {
		switch (color) {
		case RED:
			MoveBox(color, x, y);
			break;
		case ORENGE:
			MoveBox(color, x, y);
			break;
		case YELLOW:
			MoveBox(color, x, y);
			break;
		case GREEN:
			MoveBox(color, x, y);
			break;
		case LIGHTBLUE:
			MoveBox(color, x, y);
			break;
		case BLUE:
			MoveBox(color, x, y);
			break;
		case PURPLE:
			MoveBox(color, x, y);
			break;
		}
	}
}