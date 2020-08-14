#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Gimmick.h"
#include "Draw_Door_Rotation.h"
#include "Rotation_Box.h"
#include "Menu.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Controller g_Pad;
extern GimmickAll gim;

static bool InitFlag = TRUE;//Init�֐���ʂ��Ă���������ϐ�/TRUE������/FALSE���_��

void Stage12Init() {
	//�v���C���[�̏����ʒu
	//�I�u�W�F�N�g�̏����ʒu��`��
	g_Player.Interact = 1;//�v���C���[���C���^���N�g�ł���񐔂�10��ɐݒ�
	InitFlag = FALSE;	//FALSE�ɂ��Ď�TRUE�ɂȂ�܂Œʂ�Ȃ��悤�ɂ���


	g_Player.x = 110;			//�v���C���[���W������
	g_Player.y = 571;			//�v���C���[���W������
	g_Player.NowColor = BLUE;		//�v���C���[�̐F������

	//�񕜃A�C�e���p_________
	gim.item_x = 520;
	gim.item_y;
	gim.item_flg = 1;

	g_Door.RotationNumber = 0;	//���[�e�[�V����������
	g_Lock.Release = 0;			//����������������




	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//�h�A�̈ʒu
	g_Door.x = 1150;				//���̍����x���W
	g_Door.y = 670 - 200;				//���̍����y���W
	g_Door.w = g_Door.x + 100;	//����
	g_Door.h = g_Door.y + 200;	//�c��


}

int Stage12(void) {			//�}�b�v�摜�̕`��

	if ((InitFlag == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���
		Stage12Init();
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//�}�b�v�̕`��
	//�F�u���b�N�`��


	Change(LIGHTBLUE);
	DrawExtendGraph(300, 568, 400, 668, g_pic.Box, TRUE);	//1

	Change(LIGHTBLUE);
	DrawExtendGraph(400, 568, 500, 668, g_pic.Box, TRUE);	//1
	DrawExtendGraph(400, 468, 500, 568, g_pic.Box, TRUE);	//2


	Change(BLUE);
	DrawExtendGraph(500, 568, 600, 668, g_pic.Box, TRUE);	//1
	DrawExtendGraph(500, 468, 600, 568, g_pic.Box, TRUE);	//2
	Change(LIGHTBLUE);
	DrawExtendGraph(500, 368, 600, 468, g_pic.Box, TRUE);	//3

	Change(BLUE);
	DrawExtendGraph(900, 568, 1000, 668, g_pic.Box, TRUE);	//1
	DrawExtendGraph(900, 468, 1000, 568, g_pic.Box, TRUE);	//2


	kaihuku(gim.item_x, gim.item_y);

	Door();			//�X�e�[�W�S�[������
	Lock();

	DoorRotationBox(1);

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