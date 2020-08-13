#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Draw_Door_Rotation.h"
#include "Rotation_Box.h"
#include "Menu.h"
#include "Warp.h"
#include "Gimmick.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern GimmickAll gim;
extern Object g_Object;

static bool InitFlag = TRUE;//Init�֐���ʂ��Ă���������ϐ�/TRUE������/FALSE���_��

void Stage28Init() {
	//�v���C���[�̏����ʒu
	//�I�u�W�F�N�g�̏����ʒu��`��
	g_Player.Interact = 3;//�v���C���[���C���^���N�g�ł���񐔂�10��ɐݒ�
	InitFlag = FALSE;	//FALSE�ɂ��Ď�TRUE�ɂȂ�܂Œʂ�Ȃ��悤�ɂ���

	g_Player.x = 110;			//�v���C���[���W������
	g_Player.y = 571;			//�v���C���[���W������
	g_Player.NowColor = 0;		//�v���C���[�̐F������

	g_Door.RotationNumber = 0;	//���[�e�[�V����������
	g_Lock.Release = 0;			//����������������

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//���[�v***********************************************
	gim.SetNum = 2;//���[�v�̑΂̐�
	//*****************************************************

	//�C���X�^���g�X�C�b�`***********************************************
	gim.g_OTSwitchFlag = 0;		//��x����̃X�C�b�`�t���O������

	gim.OTS_X1 = 1200;				//��x����̃X�C�b�`��X/Y��������
	gim.OTS_Y1 = 618;
	gim.OTS_X2 = gim.OTS_X1 + 50;
	gim.OTS_Y2 = gim.OTS_Y1 + 50;
	gim.OTS_WallX1 = 0;
	gim.OTS_WallY1 = 0;
	gim.OTS_WallX2 = 0;
	gim.OTS_WallY2 = 0;
	gim.OTS_C_WallX1 = 590;            //��x����̃X�C�b�`�ŕ\���ǂ�X/Y��
	gim.OTS_C_WallY1 = 280;
	gim.OTS_C_WallX2 = 690;
	gim.OTS_C_WallY2 = 320;
	//*****************************************************

	//�ό`�I�u�W�F�N�g*******************************************
	gim.cheobj_flg = 1;			//�ό`����I�u�W�F�N�g�̃t���O
	gim.cheobj_x = 525;
	gim.cheobj_y = 425;
	gim.cheobj_c = g_Player.NowColor;
	gim.cheobj_ani = 158;
	//*****************************************************

	//���̈ʒu���Z�b�g
	g_Object.Init();//�I�u�W�F�N�g�̈ړ��ʃ��Z�b�g


	//�h�A�̈ʒu
	g_Door.x = 590;				//���̍����x���W
	g_Door.y = 80;				//���̍����y���W
	g_Door.w = g_Door.x + 100;	//����
	g_Door.h = g_Door.y + 200;	//�c��

}

int Stage28(void) {			//�}�b�v�摜�̕`��

	if ((InitFlag == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���
		Stage28Init();
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//�}�b�v�̕`��

	//�F�u���b�N�`��___________________________
	Change(PURPLE);
	DrawExtendGraph(0, 295, 100, 395, g_pic.Box, TRUE);
	DrawExtendGraph(1080, 195, 1180, 295, g_pic.Box, TRUE);
	DrawExtendGraph(1180, 195, 1280, 295, g_pic.Box, TRUE);
	Change(YELLOW);
	DrawExtendGraph(1180, 95, 1280, 195, g_pic.Box, TRUE);
	//�������锠�̕`��___________________________
	MoveBox(BLUE, 340, 568);
	MoveBox(RED, 840, 568);

	ColorReset();
	Warp(150, 270, 150, 568);

	OneTimeSwitch();

	ChangeBlock();	//�ό`����I�u�W�F�N�g�̊֐�

	//���E�̕�_________________________________________
	Change(NONCOLOR);
	DrawBox(0, 395, 400, 420, GetColor(255, 255, 255), TRUE);//���̏�
	DrawBox(525, 569, 750, 669, GetColor(255, 255, 255), TRUE);//�����̍�����
	DrawBox(880, 395, 1280, 420, GetColor(255, 255, 255), TRUE);//�E�̏�
	DrawBox(290, 295, 340, 395, GetColor(255, 255, 255), TRUE);//���̏�Q��
	DrawBox(940, 295, 990, 395, GetColor(255, 255, 255), TRUE);//�E�̏�Q��

	//�������锠����ԑO�ɏo��
	frontMoveBox(BLUE, 340, 568);
	frontMoveBox(RED, 840, 568);

	Door();			//�X�e�[�W�S�[������
	Lock();


	DoorRotationBox(4);

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