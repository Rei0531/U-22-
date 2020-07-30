#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Draw_Door_Rotation.h"
#include "Gimmick.h"
#include "Menu.h"


extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;

static int SwitchColor = 9;
static bool InitFlag = TRUE;//Init�֐���ʂ��Ă���������ϐ�/TRUE������/FALSE���_��

void Stage7Init() {
	//�v���C���[�̏����ʒu
	//�I�u�W�F�N�g�̏����ʒu��`��
	g_Player.Interact = 10;//�v���C���[���C���^���N�g�ł���񐔂�10��ɐݒ�
	InitFlag = FALSE;	//FALSE�ɂ��Ď�TRUE�ɂȂ�܂Œʂ�Ȃ��悤�ɂ���

	g_Player.x = 110;			//�v���C���[���W������
	g_Player.y = 571;			//�v���C���[���W������
	g_Player.NowColor = 0;		//�v���C���[�̐F������//0:RED 1:ORENGE 2:YELLOW 3:GREEN 4:LIGHTBLUE 5:BLUE 6:PURPLE

	g_Door.RotationNumber = 0;	//���[�e�[�V����������
	g_Lock.Release = 0;			//����������������

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//�h�A�̈ʒu
	g_Door.x = 540;				//���̍����x���W
	g_Door.y = 170;				//���̍����y���W
	g_Door.w = g_Door.x + 100;	//����
	g_Door.h = g_Door.y + 200;	//�c��

	SwitchColor = 9;//�X�C�b�`����\�̏�����

}

int Stage7(void) {			//�}�b�v�摜�̕`��
	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//�}�b�v�̕`��

	//�F���f�X�C�b�`_____________________
	SwitchColor = CC_Switch(g_Player.NowColor, 140, 568);//�ꎞ�ϐ��Ɋ֐�����̖߂�l���i�[����
	Change(SwitchColor);
	//�F���f���锠________________________________________________
	DrawExtendGraph(340, 568, 440, 668, g_pic.Box, TRUE);
	DrawExtendGraph(340, 468, 440, 568, g_pic.Box, TRUE);
	DrawExtendGraph(740, 568, 840, 668, g_pic.Box, TRUE);
	DrawExtendGraph(740, 468, 840, 568, g_pic.Box, TRUE);
	//���̘g��__________________________________________
	ColorReset();
	DrawBox(340, 568, 440, 668, GetColor(1, 1, 1), FALSE);
	DrawBox(340, 468, 440, 568, GetColor(1, 1, 1), FALSE);
	DrawBox(740, 568, 840, 668, GetColor(1, 1, 1), FALSE);
	DrawBox(740, 468, 840, 568, GetColor(1, 1, 1), FALSE);

	//�F�u���b�N�`��
	Change(RED);
	DrawExtendGraph(240, 568, 340, 668, g_pic.Box, TRUE);
	Change(GREEN);
	DrawExtendGraph(840, 568, 940, 668, g_pic.Box, TRUE);

	//���E�̕�_________________________________________
	Change(NONCOLOR);
	DrawBox(440, 370, 740, 420, GetColor(255, 255, 255), TRUE);

	Door();			//�X�e�[�W�S�[������
	Lock();

	DoorRotationBox(2);

	ColorReset();

	//Init����___________________________________
	if ((InitFlag == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���
		Stage7Init();
	}
	if (g_Player.PLAYER_MENU == TRUE) {
		Menu_Draw();
		InitFlag = Menu_Update();
	}
	//if ((InitFlag == TRUE) || (g_Player.PLAYER_MENU == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���,�܂��́AY�{�^���������ꂽ�Ƃ��������ł���
	//	Stage7Init();
	//	g_Player.PLAYER_MENU = FALSE;
	//}
	return 0;
}