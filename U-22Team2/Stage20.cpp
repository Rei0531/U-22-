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

static int SwitchColor = 9;

void Stage20Init() {
	//�v���C���[�̏����ʒu
	//�I�u�W�F�N�g�̏����ʒu��`��
	g_Player.Interact = 10;//�v���C���[���C���^���N�g�ł���񐔂�10��ɐݒ�
	InitFlag = FALSE;	//FALSE�ɂ��Ď�TRUE�ɂȂ�܂Œʂ�Ȃ��悤�ɂ���

	g_Player.x = 110;			//�v���C���[���W������
	g_Player.y = 571;			//�v���C���[���W������
	g_Player.NowColor = 2;		//�v���C���[�̐F������

	g_Door.RotationNumber = 0;	//���[�e�[�V����������
	g_Lock.Release = 0;			//����������������

	SwitchColor = 9;//�X�C�b�`����\�̏�����

	gim.cheobj_flg = 0;			//�ό`����I�u�W�F�N�g�̃t���O
	gim.cheobj_x = 800;
	gim.cheobj_y = 670 - 225;
	gim.cheobj_c = g_Player.NowColor;
	gim.cheobj_ani = 126;


	gim.g_OTSwitchFlag = 0;		//��x����̃X�C�b�`�t���O������

	gim.OTS_X1 = 1135;				//��x����̃X�C�b�`��X/Y��������
	gim.OTS_Y1 = 618;
	gim.OTS_X2 = gim.OTS_X1 + 50;
	gim.OTS_Y2 = gim.OTS_Y1 + 50;
	gim.OTS_WallX1 = 250;
	gim.OTS_WallY1 = 0;
	gim.OTS_WallX2 = 300;
	gim.OTS_WallY2 = 370;
	gim.OTS_C_WallX1 = 0;			//��x����̃X�C�b�`�ŕ\���ǂ�X/Y��
	gim.OTS_C_WallY1 = 0;
	gim.OTS_C_WallX2 = 0;
	gim.OTS_C_WallY2 = 669;


	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//�h�A�̈ʒu
	g_Door.x = 1100;				//���̍����x���W
	g_Door.y = 370 - 200;				//���̍����y���W
	g_Door.w = g_Door.x + 100;	//����
	g_Door.h = g_Door.y + 200;	//�c��

}

int Stage20(void) {			//�}�b�v�摜�̕`��

	if ((InitFlag == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���
		Stage20Init();
	}

	Change(NONCOLOR);
	DrawBox(0, 370, 350, 400, GetColor(255, 255, 255), TRUE);
	Change(RED);
	DrawExtendGraph(0, 270, 100, 370, g_pic.Box[0], TRUE);	//1




	Change(BLUE);
	DrawExtendGraph(300, 568, 400, 668, g_pic.Box[0], TRUE);	//1
	DrawExtendGraph(300, 468, 400, 568, g_pic.Box[0], TRUE);	//2


		//�F���f�X�C�b�`_____________________
	SwitchColor = CC_Switch(g_Player.NowColor, 200, 578);//�ꎞ�ϐ��Ɋ֐�����̖߂�l���i�[����
	Change(SwitchColor);
	//�F���f���锠________________________________________________

	DrawExtendGraph(500, 568, 600, 668, g_pic.Box[0], TRUE);	//1
	DrawExtendGraph(500, 468, 600, 568, g_pic.Box[0], TRUE);	//2


	//���̘g��__________________________________________
	ColorReset();
	DrawBox(500, 568, 600, 668, GetColor(1, 1, 1), FALSE);
	DrawBox(500, 468, 600, 568, GetColor(1, 1, 1), FALSE);

	Change(YELLOW);
	DrawExtendGraph(400, 568, 500, 668, g_pic.Box[0], TRUE);

	ChangeBlock();


	Change(NONCOLOR);
	DrawBox(1280 - 250, 370, 1280, 400, GetColor(255, 255, 255), TRUE);


	Door();			//�X�e�[�W�S�[������
	Lock();


	DoorRotationBox(3);


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