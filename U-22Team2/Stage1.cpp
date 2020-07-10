#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;

static bool InitFlag = TRUE;//Init�֐���ʂ��Ă���������ϐ�/TRUE������/FALSE���_��

void Stage1Init() {
	//�v���C���[�̏����ʒu
	//�I�u�W�F�N�g�̏����ʒu��`��
	g_Player.Interact = 10;//�v���C���[���C���^���N�g�ł���񐔂�10��ɐݒ�
	InitFlag = FALSE;	//FALSE�ɂ��Ď�TRUE�ɂȂ�܂Œʂ�Ȃ��悤�ɂ���

	g_Player.x = 110;			//�v���C���[���W������
	g_Player.y = 571;			//�v���C���[���W������
	g_Player.NowColor = 4;		//�v���C���[�̐F������

	g_Door.RotationNumber = 0;	//���[�e�[�V����������
	g_Lock.Release = 0;			//����������������

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}


}

int Stage1(void) {			//�}�b�v�摜�̕`��

	if ((InitFlag == TRUE)||(g_Player.PLAYER_MENU==TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���,�܂��́AY�{�^���������ꂽ�Ƃ��������ł���
	Stage1Init();
	g_Player.PLAYER_MENU = FALSE;
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//�}�b�v�̕`��
	//�F�u���b�N�`��
	//Change(BLUE);
	//DrawBox(800, 0, 1000, 668, GetColor(255, 255, 255), TRUE);//��
	//Change(RED);
	//DrawBox(700, 550, 750, 668, GetColor(255, 255, 255), TRUE);//��
	//Change(GREEN);
	//DrawBox(1000, 550, 1050, 668, GetColor(255, 255, 255), TRUE);//��
	Change(BLUE);
	DrawExtendGraph(400, 468, 500, 668, g_pic.Box, TRUE);
	//DrawBox(, GetColor(255, 255, 255), TRUE);//��
	Change(RED);
	DrawExtendGraph(500, 468, 600, 668, g_pic.Box, TRUE);
	//DrawBox(500, 0, 600, 668, GetColor(255, 255, 255), TRUE);//��
	Change(LIGHTBLUE);
	DrawExtendGraph(600, 468, 700, 668, g_pic.Box, TRUE);
	//DrawBox(600, 0, 700, 668, GetColor(255, 255, 255), TRUE);//��
	Door();			//�X�e�[�W�S�[������
	Lock();

	Change(g_Door.Rotation[g_MapC.StageNumber-1][0]);
	DrawBox(1150, 370, 1250, 400,GetColor(255,255,255),TRUE);
	Change(g_Door.Rotation[g_MapC.StageNumber - 1][1]);
	DrawBox(1186, 370, 1250, 400, GetColor(255, 255, 255), TRUE);
	Change(g_Door.Rotation[g_MapC.StageNumber - 1][2]);
	DrawBox(1216, 370, 1250, 400, GetColor(255, 255, 255), TRUE);

	ColorReset();

	return 0;
}