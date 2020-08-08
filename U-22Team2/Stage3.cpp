#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Object.h"
#include "Menu.h"
#include "Draw_Door_Rotation.h"
#include "Gimmick.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Object g_Object;

static bool InitFlag = TRUE;//Init�֐���ʂ��Ă���������ϐ�/TRUE������/FALSE���_��


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

	//���̈ʒu���Z�b�g
	g_Object.Init();//�I�u�W�F�N�g�̈ړ��ʃ��Z�b�g

	//�h�A�̈ʒu
	g_Door.x = 1100;			//���̍����x���W
	g_Door.y = 468;				//���̍����y���W
	g_Door.w = g_Door.x + 100;	//����
	g_Door.h = g_Door.y + 200;	//�c��

}

int Stage3(void) {			//�}�b�v�摜�̕`��

	if ((InitFlag == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���,�܂��́AY�{�^���������ꂽ�Ƃ��������ł���
		Stage3Init();
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//�}�b�v�̕`��

	//�F�u���b�N�`��_____________________________________________________
	MoveBox(ORENGE,400,568);
	MoveBox(ORENGE, 400, 468);

	MoveBox(YELLOW, 550, 568);
	MoveBox(YELLOW, 550, 468);

	MoveBox(PURPLE, 700, 568);
	MoveBox(PURPLE, 700, 468);
	//�v���C���[�̐F�Ɠ����u���b�N����O�ɏo��_______________________________________________________________
	frontMoveBox(ORENGE, 400, 568);
	frontMoveBox(ORENGE, 400, 468);

	frontMoveBox(YELLOW, 550, 568);
	frontMoveBox(YELLOW, 550, 468);

	frontMoveBox(PURPLE, 700, 568);
	frontMoveBox(PURPLE, 700, 468);

	Door();			//�X�e�[�W�S�[������
	Lock();


	//�h�A���[�e�[�V����_________________________________________________________
	DoorRotationBox(3);

	ColorReset();

	if (g_Lock.clearflg == TRUE)InitFlag = TRUE;

	if (g_Player.PLAYER_MENU == TRUE) {
		Menu_Draw();
		InitFlag = Menu_Update();
	}
	return 0;
}