#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Object.h"
#include "Gimmick.h"
#include "Menu.h"
#include "SlaidBlock.h"
#include "Draw_Door_Rotation.h"

extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Object g_Object;
extern GimmickAll gim;
//extern SlideFunction g_SlaF;

static bool InitFlag = TRUE;//Init�֐���ʂ��Ă���������ϐ�
//�I�u�W�F�N�g�̏����ʒu
static int obj2x1 = 550,
obj2x2 = obj2x1 + 100,
objALLy1 = 568,
objALLy2 = 668;
static int SlideColor = 9;//�X���C�h�p�̐F
void Stage6Init() {
	//�ړ������̃t���O
	//�I�u�W�F�N�g�̏����ʒu��`��
	g_Player.Interact = 10;//�v���C���[���C���^���N�g�ł���񐔂�10��ɐݒ�
	InitFlag = FALSE;	//FALSE�ɂ��Ď�TRUE�ɂȂ�܂Œʂ�Ȃ��悤�ɂ���

	g_Player.x = 110;			//�v���C���[���W������
	g_Player.y = 571;			//�v���C���[���W������
	g_Player.NowColor = BLUE;	//�v���C���[�̐F������

	g_Door.RotationNumber = 0;	//���[�e�[�V����������
	g_Lock.Release = 0;			//����������������

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}
	//�h�A�̈ʒu
	g_Door.x = 1100;			//���̍����x���W
	g_Door.y = 468;				//���̍����y���W
	g_Door.w = g_Door.x + 100;	//����
	g_Door.h = g_Door.y + 200;	//�c��

	//�u���b�N�̏�����
	obj2x1 = 550,
	obj2x2 = obj2x1 + 100,
	objALLy1 = 568,
	objALLy2 = objALLy1 + 100,
	gim.SliObjx1 = 750,
	gim.SliObjx2 = gim.SliObjx1 + 150,
	gim.SliObjy1 = 518,
	gim.SliObjy2 = gim.SliObjy1 + 150,
	gim.GetObjx1 = 260,
	gim.GetObjx2 = gim.GetObjx1 + 100,
	gim.GetObjy1 = 568,
	gim.GetObjy2 = gim.GetObjy1 + 100,
	gim.move_max = 100;

	SlideColor = 9;//�X�C�b�`����\�̏�����
}

int Stage6(void) {			//�}�b�v�摜�̕`��

	//if ((InitFlag == TRUE) || (g_Player.PLAYER_MENU == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���,�܂��́AY�{�^���������ꂽ�Ƃ��������ł���
	//	Stage6Init();
	//	g_Player.PLAYER_MENU = FALSE;
	//}
	if (InitFlag == TRUE) {//Init�t���O��TRUE�̎��ɏ������ł���,�܂��́AY�{�^���������ꂽ�Ƃ��������ł���
		Stage6Init();
		g_Player.PLAYER_MENU = FALSE;
	}
	SlideColor = g_Player.NowColor;
	//DrawFormatString(g_Player.x - 30, g_Player.y - 150, g_Player.NowColor, "%d %d %d %d",gim.SliObjx1,gim.SliObjx2,gim.SliObjy1,gim.SliObjy2);
	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//�}�b�v�̕`��
	Change(BLUE);//�F�u���b�N�`��
	DrawExtendGraph(980, 460, 1080, 560, g_pic.Box, TRUE);//��Q�u���b�N
	DrawExtendGraph(980, 560, 1080, 665, g_pic.Box, TRUE);//��Q�u���b�N
	//DrawExtendGraph(g_Player.x - 30, g_Player.y - 30, g_Player.x + 30, g_Player.y + 30, GetColor(255, 255, 255), TRUE);
	Change(RED);//�F�u���b�N�`��
	
	//DrawExtendGraph(380, 568, 480, 668, g_pic.Box, TRUE);//��Q�u���b�N
	DrawExtendGraph(880, 568, 980, 668, g_pic.Box, TRUE);//��Q�u���b�N
	DrawExtendGraph(880, 468, 980, 568, g_pic.Box, TRUE);//��Q�u���b�N


	SlideBlock();//�����u���b�N�̕����ƁA������v���C���[�𓮂�������
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