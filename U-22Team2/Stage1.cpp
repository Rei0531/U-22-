#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;

static bool InitFlag = TRUE;//Init�֐���ʂ��Ă���������ϐ�/TRUE������/FALSE���_��

void Stage1Init() {
	//�v���C���[�̏����ʒu
	//�I�u�W�F�N�g�̏����ʒu��`��
	g_Player.Interact = 10;//�v���C���[���C���^���N�g�ł���񐔂�10��ɐݒ�
	InitFlag = FALSE;	//FALSE�ɂ��Ď�TRUE�ɂȂ�܂Œʂ�Ȃ��悤�ɂ���
}

int Stage1(void) {			//�}�b�v�摜�̕`��

	if (InitFlag == TRUE) {//Init�t���O��TRUE�̎��ɏ������ł���
	Stage1Init();
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
	DrawBox(400, 0, 500, 668, GetColor(255, 255, 255), TRUE);//��
	Change(RED);
	DrawBox(500, 0, 600, 668, GetColor(255, 255, 255), TRUE);//��
	Change(LIGHTBLUE);
	DrawBox(600, 0, 700, 668, GetColor(255, 255, 255), TRUE);//��
	Door();			//�X�e�[�W�S�[������
	Lock();
	ColorReset();

	return 0;
}