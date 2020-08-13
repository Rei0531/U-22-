#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Object.h"
#include "Gimmick.h"
#include "Draw_Door_Rotation.h"
#include "Menu.h"
#include "SlaidBlock.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Object g_Object;
extern Controller g_Pad;
extern GimmickAll gim;

static bool InitFlag = TRUE;//Init�֐���ʂ��Ă���������ϐ�/TRUE������/FALSE���_��
//�I�u�W�F�N�g�̏����ʒu
static int
SliObjx1 = 750 + 200,
SliObjx2 = 750 + 200,
SliObjy1 = 568,
SliObjy2 = 668;
static int SlideColor = 9;//�X���C�h�p�̐F

void Stage25Init() {
	//�v���C���[�̏����ʒu
	//�I�u�W�F�N�g�̏����ʒu��`��
	g_Player.Interact = 60;//�v���C���[���C���^���N�g�ł���񐔐ݒ�
	InitFlag = FALSE;	//FALSE�ɂ��Ď�TRUE�ɂȂ�܂Œʂ�Ȃ��悤�ɂ���

	g_Player.x = 110;			//�v���C���[���W������
	g_Player.y = 571;			//�v���C���[���W������
	g_Player.NowColor = 6;		//�v���C���[�̐F������

	g_Door.RotationNumber = 0;	//���[�e�[�V����������
	g_Lock.Release = 0;			//����������������

	gim.SliObjx1 = 950,
	gim.SliObjx2 = gim.SliObjx1 + 150,
	gim.SliObjy1 = 320,
	gim.SliObjy2 = gim.SliObjy1 + 50,
	gim.GetObjx1 = 1180,
	gim.GetObjx2 = gim.GetObjx1 + 100,
	gim.GetObjy1 = 265,
	gim.GetObjy2 = gim.GetObjy1 + 105,
	gim.move_max = 160;

	gim.shower_C = PURPLE2;			//�V�����[�̓h��Ԃ��̐F��������
	gim.shower_X = 70;				//�V�����[�̍��W

	gim.g_LeverX = 50;		//���o�[��X���W
	gim.g_LeverY = 330;		//���o�[��Y���W

	gim.g_L_BoxX1 = 200;		//���o�[�Ŕ������锠X/Y���W
	gim.g_L_BoxY1 = 270;
	gim.g_L_BoxX2 = 300;
	gim.g_L_BoxY2 = 370;
	gim.SwitchFlag = 0;		//���o�[��ON�AOFF
	gim.SwitchColor = 0;		//���o�[�̐F

	gim.SwitchColor = BLUE2;		//���o�[�̐F�̏�����

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//�h�A�̈ʒu
	g_Door.x = 100;
	g_Door.y = 170;
	g_Door.w = 200;
	g_Door.h = 370;

	SlideColor = RED;//�X�C�b�`����\�̏�����

	g_Object.Init();//�I�u�W�F�N�g�̈ړ��ʃ��Z�b�g
}

int Stage25(void) {			//�}�b�v�摜�̕`��
	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//�}�b�v�̕`��

	if ((InitFlag == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���
		Stage25Init();
	}


	//�F�u���b�N�`��
	Change(YELLOW);
	DrawExtendGraph(900, 568, 1000, 668, g_pic.Box, TRUE);
	MoveBox(YELLOW, 500, 568);
	MoveBox(YELLOW, 500, 468);
	Change(BLUE);
	DrawExtendGraph(350, 568, 450, 668, g_pic.Box, TRUE);
	MoveBox(BLUE, 750, 568);
	MoveBox(BLUE, 750, 468);

	//����������___________________________________________________________________________________________________
	SlideBlock(SlideColor);

	//�V�����[����___________________________________________________________________________________________________
	Shower();

	//���o�[����___________________________________________________________________________________________________
	if (g_Lock.Release == 2)
		Lever();

	//�G���Ă���F�̃I�u�W�F����ʂ̈�Ԏ�O�ɗ���悤�ɂ��鏈���A����Z���ݒ肵�Ă�肽��
	frontMoveBox(YELLOW, 500, 568);
	frontMoveBox(YELLOW, 500, 468);
	frontMoveBox(BLUE, 750, 568);
	frontMoveBox(BLUE, 750, 468);

	//���E�̕ǁi�����u���b�N�j
	Change(NONCOLOR);
	DrawBox(0, 370, 300, 420, GetColor(255, 255, 255), TRUE);
	DrawBox(1080, 370, 1280, 420, GetColor(255, 255, 255), TRUE);
	Door();			//�X�e�[�W�S�[������
	Lock();


	DoorRotationBox(4);//�h�A�̏�̃��[�e�\�V��������{�b�N�X�̕`��

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