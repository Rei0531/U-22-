#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Object.h"
#include "Gimmick.h"
#include "Draw_Door_Rotation.h"
#include "Menu.h"

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
	g_Player.NowColor = BLUE;		//�v���C���[�̐F������

	g_Door.RotationNumber = 0;	//���[�e�[�V����������
	g_Lock.Release = 0;			//����������������

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}
	obj2x1 = 550,
		obj2x2 = obj2x1 + 150,
		objALLy1 = 518,
		objALLy2 = 668;

	gim.move_cnt = 0;
	gim.move_max = 160;

	//�h�A�̈ʒu
	g_Door.x = 1100;				//���̍����x���W
	g_Door.y = 468;				//���̍����y���W
	g_Door.w = g_Door.x + 100;	//����
	g_Door.h = g_Door.y + 200;	//�c��
}

int Stage9(void) {			//�}�b�v�摜�̕`��

	if ((InitFlag == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���
		Stage9Init();
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//�}�b�v�̕`��
	Change(NONCOLOR);
	DrawBox(0, 268, 1300, 368, GetColor(255, 255, 255), TRUE);
	ColorReset();
	DrawExtendGraph(168, 168, 268, 268, g_pic.Warp_Area, TRUE);//���[�v�p�摜
	DrawExtendGraph(368, 568, 468, 668, g_pic.Warp_Area, TRUE);//���[�v�p�摜
	DrawExtendGraph(868, 168, 968, 268, g_pic.Warp_Area, TRUE);//���[�v�p�摜

	Change(RED);
	/*DrawExtendGraph(150, 568, 250, 668, g_pic.Box, TRUE);
	DrawExtendGraph(150, 468, 250, 568, g_pic.Box, TRUE);*/
	DrawExtendGraph(500, 68, 600, 168, g_pic.Box, TRUE);
	DrawExtendGraph(500, 168, 600, 268, g_pic.Box, TRUE);

	Change(BLUE);
	DrawExtendGraph(700, 68, 800, 168, g_pic.Box, TRUE);
	DrawExtendGraph(700, 168, 800, 268, g_pic.Box, TRUE);
	/*DrawExtendGraph(500, 468, 600, 568, g_pic.Box, TRUE);
	DrawExtendGraph(500, 568, 600, 668, g_pic.Box, TRUE);*/

	Change(LIGHTBLUE);
	DrawExtendGraph(300, 68, 400, 168, g_pic.Box, TRUE);
	DrawExtendGraph(300, 168, 400, 268, g_pic.Box, TRUE);

	if (g_Pad.KEY_B == TRUE) {
		gim.move_cnt++;
		if ((g_Player.x >= 368) && (g_Player.x <= 468) && (g_Player.y <= 668) && (g_Player.y >= 568) && gim.move_cnt % 3 == 1) {
			g_Player.x = 218;
			g_Player.y = 200;
		}
		if ((g_Player.x >= 868) && (g_Player.x <= 968) && (g_Player.y <= 268) && (g_Player.y >= 168) && gim.move_cnt % 3 == 2) {
			g_Player.x = 418;
			g_Player.y = 600;
		}
	}
	//DrawFormatString(g_Player.x - 30, g_Player.y - 200, g_Player.NowColor, "%d", gim.move_cnt);

	DoorRotationBox(3);

	Door();			//�X�e�[�W�S�[������
	Lock();

	ColorReset();

	if (g_Player.PLAYER_MENU == TRUE) {
		Menu_Draw();
		InitFlag = Menu_Update();
	}

	return 0;
}