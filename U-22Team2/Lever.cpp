#include "Gimmick.h"
#include "Color.h"
#include "LoadPic.h"
#include "Controller.h"
#include "Player.h"
#include "LoadSound.h"

extern image g_pic;
extern Player g_Player;
extern Controller g_Pad;
extern GimmickAll gim;
extern Sound g_Snd;



int Lever(void) {

	Change2(gim.SwitchColor);
	if ((g_Player.x > gim.g_LeverX - 100) & (g_Player.x < gim.g_LeverX + 100) & (g_Pad.KEY_B == TRUE) & (g_Player.y > gim.g_LeverY - 100) & (g_Player.y < gim.g_LeverY + 100)
		& (gim.SwitchFlag == 0) & (gim.SwitchWait == 0) & (g_Player.NowColor == gim.SwitchColor)) { //�X�C�b�`�t���O��OFF�ł���ҋ@���Ԃ��O�ł���X�C�b�`�Əd�Ȃ��Ă���
		gim.SwitchFlag = 1;														  //���o�[�̐F�Ǝ�l���������ł����ԂŃC���^���N�g�������Ɣ���������
		gim.SwitchWait = 10;
		PlaySoundMem(g_Snd.leva, DX_PLAYTYPE_BACK);
	}
	else if ((g_Player.x > gim.g_LeverX - 100) & (g_Player.x < gim.g_LeverX + 100) & (g_Pad.KEY_B == TRUE) & (g_Player.y > gim.g_LeverY - 100) & (g_Player.y < gim.g_LeverY + 100)	  //�X�C�b�`��ON�̏ꍇ��OFF�ɐ؂�ւ���
		& (gim.SwitchFlag == 1) & (gim.SwitchWait == 0) & (g_Player.NowColor == gim.SwitchColor)) {  //���o�[��ON�܂���OFF�ɂȂ����ꍇ�ҋ@���Ԃ������
		gim.SwitchFlag = 0;
		gim.SwitchWait = 10;
		PlaySoundMem(g_Snd.leva, DX_PLAYTYPE_BACK);
	}

	if (gim.SwitchFlag == 0) {			//�I�t
		DrawRotaGraph(gim.g_LeverX, gim.g_LeverY, 0.7, 0, g_pic.Reba, TRUE, FALSE);
		//Change(RED);
		//DrawExtendGraph(gim.g_L_BoxX1, gim.g_L_BoxY1, gim.g_L_BoxX2, gim.g_L_BoxY2, g_pic.Box, TRUE);
		//DrawExtendGraph(gim.g_L_BoxX1, gim.g_L_BoxY1 - 100, gim.g_L_BoxX2, gim.g_L_BoxY2 - 100, g_pic.Box, TRUE);
	}
	else if (gim.SwitchFlag == 1) {		//�I��
		DrawRotaGraph(gim.g_LeverX, gim.g_LeverY, 0.7, 0, g_pic.Reba, TRUE, TRUE);
		//	Change(WHITE);
		//DrawExtendGraph(200, 270, 300, 370, g_pic.Box, TRUE);
		Change(YELLOW);
		DrawExtendGraph(gim.g_L_BoxX1, gim.g_L_BoxY1, gim.g_L_BoxX2, gim.g_L_BoxY2, g_pic.Box[0], TRUE);
		DrawExtendGraph(gim.g_L_BoxX1, gim.g_L_BoxY1 - 100, gim.g_L_BoxX2, gim.g_L_BoxY2 - 100, g_pic.Box[0], TRUE);
		DrawExtendGraph(gim.g_L2_BoxX1, gim.g_L2_BoxY1, gim.g_L2_BoxX2, gim.g_L2_BoxY2, g_pic.Box[0], TRUE);
		DrawExtendGraph(gim.g_L2_BoxX1, gim.g_L2_BoxY1 - 100, gim.g_L2_BoxX2, gim.g_L2_BoxY2 - 100, g_pic.Box[0], TRUE);
		DrawExtendGraph(gim.g_L3_BoxX1, gim.g_L3_BoxY1, gim.g_L3_BoxX2, gim.g_L3_BoxY2, g_pic.Box[0], TRUE);
		DrawExtendGraph(gim.g_L3_BoxX1, gim.g_L3_BoxY1 - 100, gim.g_L3_BoxX2, gim.g_L3_BoxY2 - 100, g_pic.Box[0], TRUE);


		
	}
	
	if (gim.SwitchWait != 0) {													//�ҋ@���Ԃ�����ꍇ���炵������
		gim.SwitchWait--;
	}

	Change(WHITE);

	return 0;
}


