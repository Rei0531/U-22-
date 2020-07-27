#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Gimmick.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Controller g_Pad;
extern GimmickAll gim;

static bool InitFlag = TRUE;//Init�֐���ʂ��Ă���������ϐ�/TRUE������/FALSE���_��

void Stage14Init() {
	//�v���C���[�̏����ʒu
	//�I�u�W�F�N�g�̏����ʒu��`��
	g_Player.Interact = 10;//�v���C���[���C���^���N�g�ł���񐔂�10��ɐݒ�
	InitFlag = FALSE;	//FALSE�ɂ��Ď�TRUE�ɂȂ�܂Œʂ�Ȃ��悤�ɂ���

	g_Player.x = 110;			//�v���C���[���W������
	g_Player.y = 571;			//�v���C���[���W������
	g_Player.NowColor = RED;		//�v���C���[�̐F������

	g_Door.RotationNumber = 0;	//���[�e�[�V����������
	g_Lock.Release = 0;			//����������������

	gim.cheobj_flg = 1;			//�ό`����I�u�W�F�N�g�̃t���O
	gim.cheobj_x = 800 - 225;
	gim.cheobj_c = g_Player.NowColor;

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}


}

int Stage14(void) {			//�}�b�v�摜�̕`��

	if ((InitFlag == TRUE) || (g_Player.PLAYER_MENU == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���,�܂��́AY�{�^���������ꂽ�Ƃ��������ł���
		Stage14Init();
		g_Player.PLAYER_MENU = FALSE;
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//�}�b�v�̕`��
	//�F�u���b�N�`��

	Change(YELLOW);
	DrawExtendGraph(200, 568, 300, 668, g_pic.Box, TRUE);	//3
	DrawExtendGraph(200, 468, 300, 568, g_pic.Box, TRUE);	//2
	DrawExtendGraph(200, 368, 300, 468, g_pic.Box, TRUE);	//1

	Change(YELLOW);
	DrawExtendGraph(800, 568, 900, 668, g_pic.Box, TRUE);	//3
	DrawExtendGraph(800, 468, 900, 568, g_pic.Box, TRUE);	//2
	DrawExtendGraph(800, 368, 900, 468, g_pic.Box, TRUE);	//1

	Change(RED);
	DrawExtendGraph(900, 568, 1000, 668, g_pic.Box, TRUE);	//3
	DrawExtendGraph(900, 468, 1000, 568, g_pic.Box, TRUE);	//2
	DrawExtendGraph(900, 368, 1000, 468, g_pic.Box, TRUE);	//2


	ChangeBlock();	//�ό`����I�u�W�F�N�g�̊֐�

	Door();			//�X�e�[�W�S�[������
	Lock();

	Change(g_Door.Rotation[g_MapC.StageNumber - 1][0]);
	DrawBox(1150, 370, 1250, 400, GetColor(255, 255, 255), TRUE);



	ColorReset();



	return 0;
}