#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Object.h"
#include "Gimmick.h"
#include "Menu.h"
#include "Draw_Door_Rotation.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
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

void Stage6Init() {
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

	//�h�A�̈ʒu
	g_Door.x = 1180;			//���̍����x���W
	g_Door.y = 468;				//���̍����y���W
	g_Door.w = g_Door.x + 100;	//����
	g_Door.h = g_Door.y + 200;	//�c��

}

int Stage6(void) {			//�}�b�v�摜�̕`��

	if ((InitFlag == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���
		Stage6Init();
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//�}�b�v�̕`��
	//DrawBox((obj2x1 + 200) + gim.move_x, g_Player.y + 65, (obj2x2 + 200) + gim.move_x, g_Player.y + 75, GetColor(1, 1, 1), TRUE);//�f�o�b�O�p
	DrawBox(g_Player.x - 20, g_Player.y + 65, g_Player.x, g_Player.y + 75, GetColor(1, 1, 1), TRUE);//�f�o�b�O�p
	Change(BLUE);//�F�u���b�N�`��
	DrawExtendGraph(980, 460, 1080, 565, g_pic.Box, TRUE);//��Q�u���b�N
	DrawExtendGraph(980, 565, 1080, 670, g_pic.Box, TRUE);//��Q�u���b�N
	//DrawExtendGraph(g_Player.x - 30, g_Player.y - 30, g_Player.x + 30, g_Player.y + 30, GetColor(255, 255, 255), TRUE);
	Change(RED);//�F�u���b�N�`��
	gim.move_x -= gim.Speed;
	gim.move_x -= gim.Speed;
	if (gim.move_cnt++ > gim.move_max - 100) {
		gim.move_cnt = 0;
		gim.Speed = gim.Speed * (-1);
	}
	DrawExtendGraph(380, 565, 480, 670, g_pic.Box, TRUE);//��Q�u���b�N
	DrawExtendGraph(880, 565, 980, 670, g_pic.Box, TRUE);//��Q�u���b�N
	DrawExtendGraph(880, 460, 980, 565, g_pic.Box, TRUE);//��Q�u���b�N
	DrawExtendGraph((obj2x1 + 200) + gim.move_x, objALLy1, (obj2x2 + 200) + gim.move_x, objALLy2, g_pic.Box, TRUE);//������
	if (((g_Player.x - 20 >= (obj2x1 + 200) + gim.move_x) && (g_Player.x - 20 <= (obj2x2 + 200) + gim.move_x) &&
		((g_Player.y + 65 <= objALLy1) && (g_Player.y + 75 >= objALLy1))) &&
		((g_Player.Hit_Under == g_Player.NowColor) || (g_Player.Hit_Under2 == g_Player.NowColor))) {
		g_Player.x -= gim.Speed * 2;		//�v���C���[�������œ�����
	}
	Door();			//�X�e�[�W�S�[������
	Lock();

	DoorRotationBox(2);

	ColorReset();

	if (g_Player.PLAYER_MENU == TRUE) {
		Menu_Draw();
		InitFlag = Menu_Update();
	}

	return 0;
}