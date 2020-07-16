#include "Gimmick.h"
#include "Color.h"
#include"Player.h"
#include "LoadPic.h"
#include "Controller.h"

extern image g_pic;
extern Player g_Player;
extern Controller g_Pad;
extern GimmickAll gim;



int Lever(void) {

	Change2(gim.SwitchColor);
	if ((g_Player.x > 0) & (g_Player.x < 100) & (g_Pad.KEY_B == TRUE)
		& (gim.SwitchFlag == 0) & (gim.SwitchWait == 0) & (g_Player.NowColor == gim.SwitchColor)) { //�X�C�b�`�t���O��OFF�ł���ҋ@���Ԃ��O�ł���X�C�b�`�Əd�Ȃ��Ă���
		gim.SwitchFlag = 1;														  //���o�[�̐F�Ǝ�l���������ł����ԂŃC���^���N�g�������Ɣ���������
		gim.SwitchWait = 10;
	}
	else if ((g_Player.x > 0) & (g_Player.x < 200) & (g_Pad.KEY_B == TRUE)	  //�X�C�b�`��ON�̏ꍇ��OFF�ɐ؂�ւ���
		& (gim.SwitchFlag == 1) & (gim.SwitchWait == 0) & (g_Player.NowColor == gim.SwitchColor)) {  //���o�[��ON�܂���OFF�ɂȂ����ꍇ�ҋ@���Ԃ������
		gim.SwitchFlag = 0;
		gim.SwitchWait = 10;
	}

	if (gim.SwitchFlag == 0) {			//�I�t
		DrawRotaGraph(51, 337, 0.7, 0, g_pic.Reba, TRUE, FALSE);
	}
	else if (gim.SwitchFlag == 1) {		//�I��
		DrawRotaGraph(51, 337, 0.7, 0, g_pic.Reba, TRUE, TRUE);
		//Change(WHITE);
		//DrawExtendGraph(200, 270, 300, 370, g_pic.Box, TRUE);
		Change(YELLOW);
		DrawExtendGraph(200, 265, 300, 370, g_pic.Box, TRUE);
	}
	
	if (gim.SwitchWait != 0) {													//�ҋ@���Ԃ�����ꍇ���炵������
		gim.SwitchWait--;
	}

	return 0;
}


