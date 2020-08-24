#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Draw_Door_Rotation.h"
#include "Rotation_Box.h"
#include "Menu.h"
#include "Gimmick.h"
#include "OneTime_Switch.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern GimmickAll gim;

static int SwitchColor = 9;
static bool InitFlag = TRUE;//Init�֐���ʂ��Ă���������ϐ�/TRUE������/FALSE���_��

void Stage23Init() {
	//�v���C���[�̏����ʒu
	//�I�u�W�F�N�g�̏����ʒu��`��
	g_Player.Interact = 10;//�v���C���[���C���^���N�g�ł���񐔂�10��ɐݒ�
	InitFlag = FALSE;	//FALSE�ɂ��Ď�TRUE�ɂȂ�܂Œʂ�Ȃ��悤�ɂ���

	g_Player.x = 110;			//�v���C���[���W������
	g_Player.y = 571;			//�v���C���[���W������
	g_Player.NowColor = 0;		//�v���C���[�̐F������

	g_Door.RotationNumber = 0;	//���[�e�[�V����������
	g_Lock.Release = 0;			//����������������

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//�h�A�̈ʒu
	g_Door.x = 1100;				//���̍����x���W
	g_Door.y = 100;				//���̍����y���W
	g_Door.w = g_Door.x + 100;	//����
	g_Door.h = g_Door.y + 200;	//�c��

	SwitchColor = 9;//���F�ŏ�����

	gim.g_OTSwitchFlag = 0;		//��x����̃X�C�b�`�t���O������

	gim.OTS_X1 = 800;				//��x����̃X�C�b�`��X/Y��������
	gim.OTS_Y1 = 618;
	gim.OTS_X2 = gim.OTS_X1 + 50;
	gim.OTS_Y2 = gim.OTS_Y1 + 50;
	gim.OTS_WallX1 = 1000;
	gim.OTS_WallY1 = 300;
	gim.OTS_WallX2 = 1100;
	gim.OTS_WallY2 = 669;
	gim.OTS_C_WallX1 = 400;			//��x����̃X�C�b�`�ŕ\���ǂ�X/Y��
	gim.OTS_C_WallY1 = 300;
	gim.OTS_C_WallX2 = 600;
	gim.OTS_C_WallY2 = 325;

	//�񕜃A�C�e���p_
	gim.item_x = 200;   //���̍��W
	gim.item_y = 250;   //�c�̍��W
	gim.item_flg = 1;   //�A�C�e���������������ĂȂ����̃t���O�̃t���O

}

int Stage23(void) {			//�}�b�v�摜�̕`��

	if ((InitFlag == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���
		Stage23Init();
	}

	Change(NONCOLOR);
	DrawBox(1000,300,1300,325,GetColor(255,255,255),TRUE);
	Change(RED);
	DrawExtendGraph(340, 568, 440, 668, g_pic.Box[0], TRUE);
	Change(BLUE);
	DrawExtendGraph(440, 468, 540, 568, g_pic.Box[0], TRUE);
	Change(YELLOW);
	DrawExtendGraph(540, 568, 640, 668, g_pic.Box[0], TRUE);
	Change(GREEN);
	DrawExtendGraph(640, 468, 740, 568, g_pic.Box[0], TRUE);
	//�F���f�X�C�b�`_
	SwitchColor = CC_Switch(g_Player.NowColor, 140, 588);//�ꎞ�ϐ��Ɋ֐�����̖߂�l���i�[����
	Change(SwitchColor);
	//�F���f���锠__
	DrawExtendGraph(0, 318, 100, 418, g_pic.Box[0], TRUE);
	DrawExtendGraph(100, 318, 200, 418, g_pic.Box[0], TRUE);
	DrawExtendGraph(800, 318, 900, 418, g_pic.Box[0], TRUE);
	DrawExtendGraph(900, 318, 1000, 418, g_pic.Box[0], TRUE);
	ColorReset();
	DrawBox(0, 318, 100, 418, GetColor(1, 1, 1), FALSE);
	DrawBox(100, 318, 200, 418, GetColor(1, 1, 1), FALSE);
	DrawBox(800, 318, 900, 418, GetColor(1, 1, 1), FALSE);
	DrawBox(900, 318, 1000, 418, GetColor(1, 1, 1), FALSE);
	
	ColorReset();
	OneTimeSwitch();
	
	kaihuku(gim.item_x, gim.item_y);  //(x���W�Ay���W�j

	ColorReset();
	Warp(50, 200, 1100, 568);


	Door();			//�X�e�[�W�S�[������
	Lock();

	DoorRotationBox(4);

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