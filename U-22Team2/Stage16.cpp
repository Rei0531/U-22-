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


void Stage16Init() {
	//�v���C���[�̏����ʒu
	//�I�u�W�F�N�g�̏����ʒu��`��
	g_Player.Interact = 20;//�v���C���[���C���^���N�g�ł���񐔂�10��ɐݒ�
	InitFlag = FALSE;	//FALSE�ɂ��Ď�TRUE�ɂȂ�܂Œʂ�Ȃ��悤�ɂ���

	g_Player.x = 110;			//�v���C���[���W������
	g_Player.y = 571;			//�v���C���[���W������
	g_Player.NowColor = 3;		//�v���C���[�̐F������

	g_Door.RotationNumber = 0;	//���[�e�[�V����������
	g_Lock.Release = 0;			//����������������

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//�h�A�̈ʒu
	g_Door.x = 1180;				//���̍����x���W
	g_Door.y = 168;				//���̍����y���W
	g_Door.w = g_Door.x + 100;	//����
	g_Door.h = g_Door.y + 200;	//�c��

	gim.CC_SwitchColor = 9;//�X�C�b�`����\�̏�����

}

int Stage16(void) {			//�}�b�v�摜�̕`��


	if ((InitFlag == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���
		Stage16Init();
	}

	//�F�u���b�N�`��
	Change(BLUE);
	DrawExtendGraph(300, 568, 400, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(300, 468, 400, 568, g_pic.Box[0], TRUE);
	Change(GREEN);
	DrawExtendGraph(500, 568, 600, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(500, 468, 600, 568, g_pic.Box[0], TRUE);
	Change(YELLOW);
	DrawExtendGraph(700, 568, 800, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(700, 468, 800, 568, g_pic.Box[0], TRUE);

	//�ϐF���`��________________________________
	Change(Rotation_Box(2));
	DrawExtendGraph(900, 568, 1000, 668, g_pic.Box[2], TRUE);

	//�F���f�X�C�b�`____________________________				
	gim.CC_SwitchColor = CC_Switch(g_Player.NowColor, 140, 578);//�ꎞ�ϐ��Ɋ֐�����̖߂�l���i�[����
	Change(gim.CC_SwitchColor);
	//�F���f���锠________________________________________________
	DrawExtendGraph(1000, 568, 1100, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(1000, 468, 1100, 568, g_pic.Box[0], TRUE);
	//���̘g��__________________________________________
	ColorReset();
	DrawBox(1000, 568, 1100, 668, GetColor(3, 3, 3), FALSE);
	DrawBox(1000, 468, 1100, 568, GetColor(3, 3, 3), FALSE);

	//���E�̕�_______________________
	DrawBox(1130, 368, 1280, 418, GetColor(0, 0, 0), TRUE);


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