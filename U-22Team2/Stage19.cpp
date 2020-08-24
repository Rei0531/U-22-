#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Draw_Door_Rotation.h"
#include "Rotation_Box.h"
#include "Menu.h"
#include "Gimmick.h"
#include "Warp.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern GimmickAll gim;

static bool InitFlag = TRUE;//Init�֐���ʂ��Ă���������ϐ�/TRUE������/FALSE���_��

int Warpy = 50;

void Stage19Init() {
	//�v���C���[�̏����ʒu
	//�I�u�W�F�N�g�̏����ʒu��`��
	g_Player.Interact = 20;//�v���C���[���C���^���N�g�ł���񐔂�10��ɐݒ�
	InitFlag = FALSE;	//FALSE�ɂ��Ď�TRUE�ɂȂ�܂Œʂ�Ȃ��悤�ɂ���

	g_Player.x = 110;			//�v���C���[���W������
	g_Player.y = 571;			//�v���C���[���W������
	g_Player.NowColor = 6;		//�v���C���[�̐F������

	g_Door.RotationNumber = 0;	//���[�e�[�V����������
	g_Lock.Release = 0;			//����������������

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//���[�v***********************************************
	gim.SetNum = 2;//���[�v�̑΂̐�
	//*****************************************************

	//�V�����[***********************************************
	gim.shower_C = LIGHTBLUE2;			//�V�����[�̓h��Ԃ��̐F��������
	gim.shower_X = 1000;				//�V�����[�̍��W
	//*****************************************************

	//���o�[***********************************************
	gim.g_LeverX = 1180;		//���o�[��X���W
	gim.g_LeverY = 340;		//���o�[��Y���W
	//���o�[�Ŕ������锠X/Y���W
	//���
	gim.g_L_BoxX1 = 780;		
	gim.g_L_BoxY1 = 568;
	gim.g_L_BoxX2 = gim.g_L_BoxX1 + 100;
	gim.g_L_BoxY2 = gim.g_L_BoxY1 + 100;
	//���
	gim.g_L2_BoxX1 = 780;
	gim.g_L2_BoxY1 = 468;
	gim.g_L2_BoxX2 = gim.g_L2_BoxX1 + 100;
	gim.g_L2_BoxY2 = gim.g_L2_BoxY1 + 100;
	//�O��
	gim.g_L3_BoxX1 = 680;
	gim.g_L3_BoxY1 = 568;
	gim.g_L3_BoxX2 = gim.g_L3_BoxX1 + 100;
	gim.g_L3_BoxY2 = gim.g_L3_BoxY1 + 100;
	//�e���̐F�ݒ�
	gim.OTSBox_Color = PURPLE;
	gim.OTSBox_Color2 = PURPLE;
	gim.OTSBox_Color3 = PURPLE;
	gim.OTSBox_Color4 = WHITE;
	gim.OTSBox_Color5 = WHITE;

	gim.SwitchFlag = 1;		//���o�[��ON�AOFF
	gim.SwitchColor = 6;		//���o�[�̐F
	//*****************************************************


	//�h�A�̈ʒu
	g_Door.x = 50;				//���̍����x���W
	g_Door.y = 170;				//���̍����y���W
	g_Door.w = g_Door.x + 100;	//����
	g_Door.h = g_Door.y + 200;	//�c��

}

int Stage19(void) {			//�}�b�v�摜�̕`��

	if ((InitFlag == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���
		Stage19Init();
	}


	Warp(200, 270, 200, 568);

	Lever();

	Shower();		//�h��Ԃ��V�����[�̏���

	//�F�u���b�N�`��
	Change(GREEN);
	DrawExtendGraph(400, 569, 500, 669, g_pic.Box[0], TRUE);
	DrawExtendGraph(400, 468, 500, 568, g_pic.Box[0], TRUE);
	DrawExtendGraph(400, 368, 500, 468, g_pic.Box[0], TRUE);

	//���E�̕�_________________________________________
	Change(NONCOLOR);
	DrawBox(0, 370, 400, 420, GetColor(255, 255, 255), TRUE);
	DrawBox(880, 370, 1280, 420, GetColor(255, 255, 255), TRUE);


	Door();			//�X�e�[�W�S�[������
	Lock();


	DoorRotationBox(3);


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