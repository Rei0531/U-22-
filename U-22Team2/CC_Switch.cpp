#include "Gimmick.h"
#include "LoadPic.h"
#include "Color.h"
#include "Controller.h"
#include "Player.h"
#include "LoadSound.h"
#include"Lock.h"

extern Controller g_Pad;
extern image g_pic;
extern Player g_Player;
extern Sound g_Snd;
extern LockALL g_Lock;

int PushColor = 9;//�����ꂽ�F����������i�[����ϐ�

static bool //��x�����h�~
B = FALSE;//B�{�^��

int CC_Switch(int Color,int x,int y) {

	if (g_Pad.KEY_B == TRUE && B == FALSE &&
		g_Player.x > x && g_Player.x < x+100 && g_Player.y > y-100 && g_Player.y < y+100) {//�X�C�b�`�������ꂽ��
		PushColor = Color;
		PlaySoundMem(g_Snd.Switch, DX_PLAYTYPE_BACK);
	}

	if (g_Player.PLAYER_RESET == TRUE) {	//Init�������Ă΂ꂽ��F������������
		PushColor = 9;
		//DrawRotagGraph��FALSE�ɂ��Ă���
		//g_Player.PLAYER_RESET = FALSE;//���Z�b�g�����t���O��FALSE�ɂ�������
	}

	if (g_Lock.clearflg == TRUE)PushColor = 9;

	Change(PushColor);
	DrawExtendGraph(x, y, x+100, y+100, g_pic.C_Switch, TRUE);


	B = (g_Pad.KEY_B == TRUE) ? TRUE : FALSE;//B�{�^����������Ă�����/�ēxB�{�^����������悤��

	return PushColor;
}