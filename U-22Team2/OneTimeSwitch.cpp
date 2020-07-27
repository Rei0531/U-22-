#include "Gimmick.h"
#include "LoadPic.h"
#include "Color.h"
#include "Controller.h"
#include "Player.h"

extern Controller g_Pad;
extern image g_pic;
extern Player g_Player;
extern GimmickAll gim;

int OneTimeSwitch(void) {

	if (g_Pad.KEY_B == TRUE &&
		g_Player.x > 800 && g_Player.x < 850 && gim.OTSwitchFlag == 0) {			//�X�C�b�`���ӂŃC���^���N�g�������ƕǂ�������
		gim.OTSwitchFlag = 99;
	}

	if (gim.OTSwitchFlag == 0) {
		Change(NONCOLOR);
		DrawBox(900, 0, 1000, 669, GetColor(255, 255, 255), TRUE);					//�X�C�b�`��������ĂȂ��Ȃ�\��
	}																				
	else if (gim.OTSwitchFlag != 0) {												//�����ꂽ���\��
		DrawBox(900, 0, 1000, 669, GetColor(255, 255, 255), TRUE);
		Change(NONCOLOR);
		DrawBox(720, 0, 770, 669, GetColor(255, 255, 255), TRUE);
	}

	DrawFormatString(100, 300, 0xffffff,"OTS = %d", gim.OTSwitchFlag);

	return 0;
}