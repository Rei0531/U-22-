#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Bomb.h"
#include "OneTime_Switch.h"
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

void Stage17Init() {
	//�v���C���[�̏����ʒu
	//�I�u�W�F�N�g�̏����ʒu��`��
	g_Player.Interact = 20;//�v���C���[���C���^���N�g�ł���񐔂�10��ɐݒ�
	InitFlag = FALSE;	//FALSE�ɂ��Ď�TRUE�ɂȂ�܂Œʂ�Ȃ��悤�ɂ���

	g_Player.x = 110;			//�v���C���[���W������
	g_Player.y = 571;			//�v���C���[���W������
	g_Player.NowColor = 1;		//�v���C���[�̐F������

	g_Door.RotationNumber = 0;	//���[�e�[�V����������
	g_Lock.Release = 0;			//����������������

	gim.g_OTSwitchFlag = 0;		//��x����̃X�C�b�`�t���O������

	gim.OTS_X1 = 50;				//��x����̃X�C�b�`��X/Y��������
	gim.OTS_Y1 = 250;
	gim.OTS_X2 = gim.OTS_X1 + 50;
	gim.OTS_Y2 = gim.OTS_Y1 + 50;

	gim.OTS_WallX1 = 1000;
	gim.OTS_WallY1 = 300;
	gim.OTS_WallX2 = 1050;
	gim.OTS_WallY2 = 669;
	gim.OTS_C_WallX1 = 0;			//��x����̃X�C�b�`�ŕ\���ǂ�X/Y��
	gim.OTS_C_WallY1 = 0;
	gim.OTS_C_WallX2 = 0;
	gim.OTS_C_WallY2 = 669;

	gim.g_Bombflg = 0;				//���e�t���O�̏�����
	gim.BombX1 = 250;				//���e��X��������
	gim.BombX2 = gim.BombX1 + 50;
	gim.BombY1 = 618;				//���e��Y��������
	gim.BombY2 = gim.BombY1 + 50;

	gim.B_EffectCount = 30;	//�����̉摜�̕`�掞��
	gim.B_WallX1 = 650;			//�󂹂�ǂ�X��
	gim.B_WallY1 = 0;
	gim.B_WallX2 = 700;			//�󂹂�ǂ�Y��
	gim.B_WallY2 = 669;


	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//�h�A�̈ʒu
	g_Door.x = 1100;				//���̍����x���W
	g_Door.y = 468;				//���̍����y���W
	g_Door.w = g_Door.x + 100;	//����
	g_Door.h = g_Door.y + 200;	//�c��

}

int Stage17(void) {			//�}�b�v�摜�̕`��

	if ((InitFlag == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���
		Stage17Init();
	}


	Change(NONCOLOR);
	DrawBox(0, 300, 300, 370, 0xffffff, TRUE);
	DrawBox(1050, 300, 1300, 370, 0xffffff, TRUE);

	Change(BLUE);
	DrawExtendGraph(400, 568, 500, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(400, 468, 500, 568, g_pic.Box[0], TRUE);
	DrawExtendGraph(400, 368, 500, 468, g_pic.Box[0], TRUE);
	DrawExtendGraph(500, 568, 600, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(500, 468, 600, 568, g_pic.Box[0], TRUE);
	DrawExtendGraph(500, 368, 600, 468, g_pic.Box[0], TRUE);
	DrawExtendGraph(1100, 200, 1200, 300, g_pic.Box[0], TRUE);
	DrawExtendGraph(1100, 100, 1200, 200, g_pic.Box[0], TRUE);
	Change(RED);
	DrawExtendGraph(300, 568, 400, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(300, 468, 400, 568, g_pic.Box[0], TRUE);
	DrawExtendGraph(700, 568, 800, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(800, 568, 900, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(800, 468, 900, 568, g_pic.Box[0], TRUE);
	DrawExtendGraph(900, 568, 1000, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(900, 468, 1000, 568, g_pic.Box[0], TRUE);
	DrawExtendGraph(900, 368, 1000, 468, g_pic.Box[0], TRUE);


	Door();			//�X�e�[�W�S�[������
	Lock();


	DoorRotationBox(2);

	Bomb();

	OneTimeSwitch();

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