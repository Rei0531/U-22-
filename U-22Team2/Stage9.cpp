#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Object.h"
#include "Gimmick.h"
#include "Draw_Door_Rotation.h"
#include "Menu.h"
#include "Warp.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Controller g_Pad;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Object g_Object;
extern GimmickAll gim;

static bool InitFlag = TRUE;//Init�֐���ʂ��Ă���������ϐ�
//�I�u�W�F�N�g�̏����ʒu
static int obj2x1 = 550,
obj2x2 = obj2x1 + 100,
objALLy1 = 568,
objALLy2 = 668;

void Stage9Init() {
	//�ړ������̃t���O
	//�I�u�W�F�N�g�̏����ʒu��`��
	g_Player.Interact = 10;//�v���C���[���C���^���N�g�ł���񐔂�10��ɐݒ�
	InitFlag = FALSE;	//FALSE�ɂ��Ď�TRUE�ɂȂ�܂Œʂ�Ȃ��悤�ɂ���

	g_Player.x = 110;			//�v���C���[���W������
	g_Player.y = 571;			//�v���C���[���W������
	g_Player.NowColor = 2;		//�v���C���[�̐F������

	g_Door.RotationNumber = 0;	//���[�e�[�V����������
	g_Lock.Release = 0;			//����������������

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}
	obj2x1 = 550,
		obj2x2 = obj2x1 + 150,
		objALLy1 = 518,
		objALLy2 = 668;
	gim.SetNum = 2;			//1:����ʍs�@2:�o����

	//�h�A�̈ʒu
	g_Door.x = 1100;			//���̍����x���W
	g_Door.y = 468;				//���̍����y���W
	g_Door.w = g_Door.x + 100;	//����
	g_Door.h = g_Door.y + 200;	//�c��
}

int Stage9(void) {			//�}�b�v�摜�̕`��

	if ((InitFlag == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���
		Stage9Init();
	}

	Change(NONCOLOR);
	DrawBox(0, 268, 1300, 368, GetColor(255, 255, 255), TRUE);
	ColorReset();
	//DrawExtendGraph(168, 168, 268, 268, g_pic.Warp_Area, TRUE);//���[�v�p�摜
	//DrawExtendGraph(368, 568, 468, 668, g_pic.Warp_Area, TRUE);//���[�v�p�摜
	//DrawExtendGraph(868, 168, 968, 268, g_pic.Warp_Area, TRUE);//���[�v�p�摜

	Change(RED);
	/*DrawExtendGraph(150, 568, 250, 668, g_pic.Box, TRUE);
	DrawExtendGraph(150, 468, 250, 568, g_pic.Box, TRUE);*/
	DrawExtendGraph(450, 68, 550, 168, g_pic.Box[0], TRUE);
	DrawExtendGraph(450, 168, 550, 268, g_pic.Box[0], TRUE);

	Change(BLUE);
	DrawExtendGraph(650, 68, 750, 168, g_pic.Box[0], TRUE);
	DrawExtendGraph(650, 168, 750, 268, g_pic.Box[0], TRUE);
	/*DrawExtendGraph(500, 468, 600, 568, g_pic.Box, TRUE);
	DrawExtendGraph(500, 568, 600, 668, g_pic.Box, TRUE);*/

	Change(LIGHTBLUE);
	DrawExtendGraph(250, 68, 350, 168, g_pic.Box[0], TRUE);
	DrawExtendGraph(250, 168, 350, 268, g_pic.Box[0], TRUE);
	ColorReset();
	Warp(125,175,125,575);
	Warp2(900, 175, 250, 575);

	//�M�~�b�N�����`��
	Change(GREEN);
	DrawRotaGraph(1024, 74, 1.0, 0, g_pic.All_text[3], TRUE, FALSE);
	
	//DrawFormatString(g_Player.x - 30, g_Player.y - 200, g_Player.NowColor, "%d", gim.move_cnt);

	Door();			//�X�e�[�W�S�[������
	Lock();

	DoorRotationBox(3);


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