#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Draw_Door_Rotation.h"
#include "Rotation_Box.h"
#include "Menu.h"
#include "Gimmick.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern GimmickAll gim;

static bool InitFlag = TRUE;//Init�֐���ʂ��Ă���������ϐ�/TRUE������/FALSE���_��

void Stage15Init() {
	//�v���C���[�̏����ʒu
	//�I�u�W�F�N�g�̏����ʒu��`��
	g_Player.Interact = 20;//�v���C���[���C���^���N�g�ł���񐔂�10��ɐݒ�
	InitFlag = FALSE;	//FALSE�ɂ��Ď�TRUE�ɂȂ�܂Œʂ�Ȃ��悤�ɂ���

	g_Player.x = 110;			//�v���C���[���W������
	g_Player.y = 571;			//�v���C���[���W������
	g_Player.NowColor = 5;		//�v���C���[�̐F������

	g_Door.RotationNumber = 0;	//���[�e�[�V����������
	g_Lock.Release = 0;			//����������������

	//���o�[******************************************************
	gim.g_LeverX = 880;		//���o�[��X���W
	gim.g_LeverY = 638;		//���o�[��Y���W
	//���
	gim.g_L_BoxX1 = 280;		//���o�[�Ŕ������锠X/Y���W
	gim.g_L_BoxY1 = 468;
	gim.g_L_BoxX2 = gim.g_L_BoxX1 + 100;
	gim.g_L_BoxY2 = gim.g_L_BoxY1 + 100;
	//���
	gim.g_L2_BoxX1 = 380;
	gim.g_L2_BoxY1 = 468;
	gim.g_L2_BoxX2 = gim.g_L2_BoxX1 + 100;
	gim.g_L2_BoxY2 = gim.g_L2_BoxY1 + 100;
	//�O��
	gim.g_L3_BoxX1 = 680;
	gim.g_L3_BoxY1 = 468;
	gim.g_L3_BoxX2 = gim.g_L3_BoxX1 + 100;
	gim.g_L3_BoxY2 = gim.g_L3_BoxY1 + 100;
	//�l��
	gim.g_L4_BoxX1 = 1080;
	gim.g_L4_BoxY1 = 568;
	gim.g_L4_BoxX2 = gim.g_L4_BoxX1 + 100;
	gim.g_L4_BoxY2 = gim.g_L4_BoxY1 + 100;
	//�{�b�N�X�̐F
	gim.OTSBox_Color = RED;
	gim.OTSBox_Color2 = BLUE;
	gim.OTSBox_Color3 = BLUE;
	gim.OTSBox_Color4 = BLUE;
	gim.OTSBox_Color5 = WHITE;

	gim.SwitchFlag = 0;		//���o�[��ON�AOFF
	gim.SwitchColor = 0;		//���o�[�̐F
	//********************************************************

	//������******************************************
	gim.SliObjx1 = 880,
	gim.SliObjx2 = gim.SliObjx1 + 100,
	gim.SliObjy1 = 368,
	gim.SliObjy2 = gim.SliObjy1 + 50,

	gim.GetObjx1 = 0,
	gim.GetObjx2 = gim.GetObjx1 + 0,
	gim.GetObjy1 = 0,
	gim.GetObjy2 = gim.GetObjy1 + 0;

	gim.move_max = 75;//25���ƂɂЂƃu���b�N��(100x���W)

	//SlideColor = RED;//�X�C�b�`����\�̏�����
	//****************************************************



	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//�h�A�̈ʒu
	g_Door.x = 1180;			//���̍����x���W
	g_Door.y = 168;				//���̍����y���W
	g_Door.w = g_Door.x + 100;	//����
	g_Door.h = g_Door.y + 200;	//�c��

}

int Stage15(void) {			//�}�b�v�摜�̕`��

	if ((InitFlag == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���
		Stage15Init();
	}


	//�F�u���b�N�`��
	Change(BLUE);
	DrawExtendGraph(980, 568, 1080, 668, g_pic.Box[0], TRUE);	//
	DrawExtendGraph(980, 468, 1080, 568, g_pic.Box[0], TRUE);	//

	Change(RED);
	DrawExtendGraph(980, 368, 1080, 468, g_pic.Box[0], TRUE);	//
	DrawExtendGraph(480, 468, 580, 568, g_pic.Box[0], TRUE);	//
	DrawExtendGraph(480, 368, 580, 468, g_pic.Box[0], TRUE);	//
	DrawExtendGraph(380, 568, 480, 668, g_pic.Box[0], TRUE);	//

	//����������___________________________________________________________________________________________________
	SlideBlock(RED);

	ColorReset();
	Lever();


	//���E�̕ǁi�����u���b�N�j
	Change(NONCOLOR);
	DrawBox(680, 568, 780, 668, GetColor(255, 255, 255), TRUE);
	DrawBox(480, 568, 580, 668, GetColor(255, 255, 255), TRUE);
	DrawBox(280, 568, 380, 668, GetColor(255, 255, 255), TRUE);
	DrawBox(1180, 368, 1280, 668, GetColor(255, 255, 255), TRUE);

	Door();			//�X�e�[�W�S�[������
	Lock();


	DoorRotationBox(2);

	ColorReset();

	//�X�e�[�W�N���A�������A�^�C�g����ʂɖ߂����Ƃ�
	if (g_Lock.clearflg == TRUE || g_Player.InitFlag == TRUE) {
		InitFlag = TRUE;
		g_Player.InitFlag = FALSE;
	}

	if (g_Player.PLAYER_MENU == TRUE) {
		Menu_Draw();
		InitFlag = Menu_Update();
	}

	return 0;
}