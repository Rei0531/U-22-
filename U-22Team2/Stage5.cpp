#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Object.h"
#include "LoadSound.h"
#include "Menu.h"
#include "Draw_Door_Rotation.h"
#include "Lever.h"
#include "Gimmick.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Controller g_Pad;
extern Sound g_Snd;
extern GimmickAll gim;

static bool InitFlag = TRUE;//Init�֐���ʂ��Ă���������ϐ�/TRUE������/FALSE���_��


void Stage5Init() {
	//�v���C���[�̏����ʒu
	//�I�u�W�F�N�g�̏����ʒu��`��
	g_Player.Interact = 10;//�v���C���[���C���^���N�g�ł���񐔂�10��ɐݒ�
	InitFlag = FALSE;	//FALSE�ɂ��Ď�TRUE�ɂȂ�܂Œʂ�Ȃ��悤�ɂ���

	g_Player.x = 110;			//�v���C���[���W������
	g_Player.y = 571;			//�v���C���[���W������
	g_Player.NowColor = 0;		//�v���C���[�̐F������

	g_Door.RotationNumber = 0;	//���[�e�[�V����������
	g_Lock.Release = 0;			//����������������

	gim.g_LeverX = 500;		//���o�[��X���W
	gim.g_LeverY = 633;		//���o�[��Y���W
	
	gim.g_L_BoxX1 = 700;		//���o�[�Ŕ������锠X/Y���W
	gim.g_L_BoxY1 = 568;
	gim.g_L_BoxX2 = gim.g_L_BoxX1 + 100;
	gim.g_L_BoxY2 = gim.g_L_BoxY1 + 100;
	gim.g_L2_BoxX1 = 700;
	gim.g_L2_BoxY1 = 468;
	gim.g_L2_BoxX2 = gim.g_L2_BoxX1 + 100;
	gim.g_L2_BoxY2 = gim.g_L2_BoxY1 + 100;
	gim.g_L3_BoxX1 = 300;
	gim.g_L3_BoxY1 = 568;
	gim.g_L3_BoxX2 = gim.g_L3_BoxX1 + 100;
	gim.g_L3_BoxY2 = gim.g_L3_BoxY1 + 100;
	gim.g_L4_BoxX1 = 300;
	gim.g_L4_BoxY1 = 468;
	gim.g_L4_BoxX2 = gim.g_L4_BoxX1 + 100;
	gim.g_L4_BoxY2 = gim.g_L4_BoxY1 + 100;
	gim.g_L5_BoxX1 = 300;
	gim.g_L5_BoxY1 = 368;
	gim.g_L5_BoxX2 = gim.g_L5_BoxX1 + 100;
	gim.g_L5_BoxY2 = gim.g_L5_BoxY1 + 100;

	gim.OTSBox_Color = RED;
	gim.OTSBox_Color2 = YELLOW;
	gim.OTSBox_Color3 = RED;
	gim.OTSBox_Color4 = RED;
	gim.OTSBox_Color5 = RED;
	
	

	gim.SwitchFlag = 0;		//���o�[��ON�AOFF
	gim.SwitchColor = 0;		//���o�[�̐F

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//�h�A�̈ʒu
	g_Door.x = 1100;			//���̍����x���W
	g_Door.y = 468;				//���̍����y���W
	g_Door.w = g_Door.x + 100;	//����
	g_Door.h = g_Door.y + 200;	//�c��


}

int Stage5(void) {			//�}�b�v�摜�̕`��

	if ((InitFlag == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���
		Stage5Init();
	}

	//�F�u���b�N�`��

	DrawExtendGraph(700, 568, 800, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(700, 468, 800, 568, g_pic.Box[0], TRUE);

	//�M�~�b�N�����`��
	Change(BLUE);
	DrawRotaGraph(900, 110, 1.5, 0, g_pic.All_text[6], TRUE, FALSE);

	//DrawFormatString(0, 400, 0x000000, "g_SwitchFlag = %d", g_SwitchFlag);
	Door();			//�X�e�[�W�S�[������
	Lock();

	DoorRotationBox(1);

	Lever();


	//�X�e�[�W�N���A�������A�^�C�g����ʂɖ߂����Ƃ�
	if (g_Lock.clearflg == TRUE || g_Player.InitFlag == TRUE) {
		InitFlag = TRUE;
		g_Player.InitFlag = FALSE;
	}

	if (g_Player.PLAYER_MENU == TRUE) {
		InitFlag = Menu_Update();
	}
	return 0;
}