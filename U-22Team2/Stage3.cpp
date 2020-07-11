#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Object.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Object g_Object;

static bool InitFlag = TRUE;//Init�֐���ʂ��Ă���������ϐ�/TRUE������/FALSE���_��

static int obj1x1 = 400,
obj1x2 = obj1x1 + 150,
obj2x1 = 550,
obj2x2 = obj2x1 + 150,
obj3x1 = 700,
obj3x2 = obj3x1 + 150,
objALLy1 = 518,
objALLy2 = 668;

void Stage3Init() {
	//�v���C���[�̏����ʒu
	//�I�u�W�F�N�g�̏����ʒu��`��
	g_Player.Interact = 10;//�v���C���[���C���^���N�g�ł���񐔂�10��ɐݒ�
	InitFlag = FALSE;	//FALSE�ɂ��Ď�TRUE�ɂȂ�܂Œʂ�Ȃ��悤�ɂ���

	g_Player.x = 110;			//�v���C���[���W������
	g_Player.y = 571;			//�v���C���[���W������
	g_Player.NowColor = 6;		//�v���C���[�̐F������

	g_Door.RotationNumber = 0;	//���[�e�[�V����������
	g_Lock.Release = 0;			//����������������

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	obj1x1 = 400;
	obj1x2 = obj1x1 + 150;
	obj2x1 = 550;
	obj2x2 = obj2x1 + 150;
	obj3x1 = 700;
	obj3x2 = obj3x1 + 150;
	objALLy1 = 518;
	objALLy2 = 668;
	g_Object.Init();
}

int Stage3(void) {			//�}�b�v�摜�̕`��

	if ((InitFlag == TRUE) || (g_Player.PLAYER_MENU == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���,�܂��́AY�{�^���������ꂽ�Ƃ��������ł���
		Stage3Init();
		g_Player.PLAYER_MENU = FALSE;
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//�}�b�v�̕`��
	//�F�u���b�N�`��
	Change(ORENGE);
	DrawExtendGraph(obj1x1 + g_Object.ORENGE_x, objALLy1, obj1x2 + g_Object.ORENGE_x, objALLy2, g_pic.Box_Move, TRUE);
	Change(YELLOW);
	DrawExtendGraph(obj2x1 + g_Object.YELLOW_x, objALLy1, obj2x2 + g_Object.YELLOW_x, objALLy2, g_pic.Box_Move, TRUE);
	Change(PURPLE);
	DrawExtendGraph(obj3x1 + g_Object.PURPLE_x, objALLy1, obj3x2 + g_Object.PURPLE_x, objALLy2, g_pic.Box_Move, TRUE);
	Door();			//�X�e�[�W�S�[������
	Lock();

	Change(g_Door.Rotation[g_MapC.StageNumber - 1][0]);
	DrawBox(1150, 370, 1250, 400, GetColor(255, 255, 255), TRUE);
	Change(g_Door.Rotation[g_MapC.StageNumber - 1][1]);
	DrawBox(1186, 370, 1250, 400, GetColor(255, 255, 255), TRUE);
	Change(g_Door.Rotation[g_MapC.StageNumber - 1][2]);
	DrawBox(1216, 370, 1250, 400, GetColor(255, 255, 255), TRUE);

	ColorReset();

	return 0;
}