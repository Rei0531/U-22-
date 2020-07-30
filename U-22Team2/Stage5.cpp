#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Object.h"
#include "LoadSound.h"
#include "Menu.h"
#include "Draw_Door_Rotation.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Controller g_Pad;
extern Sound g_Snd;

static bool InitFlag = TRUE;//Init�֐���ʂ��Ă���������ϐ�/TRUE������/FALSE���_��

int g_SwitchFlag = 0;		//���o�[��ON�AOFF
int g_SwitchWait = 0;		//���o�[�̑ҋ@����

void Stage5Init() {
	//�v���C���[�̏����ʒu
	//�I�u�W�F�N�g�̏����ʒu��`��
	g_Player.Interact = 10;//�v���C���[���C���^���N�g�ł���񐔂�10��ɐݒ�
	InitFlag = FALSE;	//FALSE�ɂ��Ď�TRUE�ɂȂ�܂Œʂ�Ȃ��悤�ɂ���

	g_Player.x = 110;			//�v���C���[���W������
	g_Player.y = 571;			//�v���C���[���W������
	g_Player.NowColor = 4;		//�v���C���[�̐F������

	g_Door.RotationNumber = 0;	//���[�e�[�V����������
	g_Lock.Release = 0;			//����������������

	g_SwitchFlag = 0;			//�X�C�b�`������

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//�h�A�̈ʒu
	g_Door.x = 1100;			//���̍����x���W
	g_Door.y = 468;				//���̍����y���W
	g_Door.w = g_Door.x + 100;	//����
	g_Door.h = g_Door.y + 200;	//�c��


}

int Stage5(void) {			//�}�b�v�摜�̕`��

	if ((InitFlag == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���
		Stage5Init();
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//�}�b�v�̕`��
	//�F�u���b�N�`��

	Change(LIGHTBLUE);
	if ((g_Player.x > 424) & (g_Player.x < 575) & (g_Pad.KEY_B == TRUE)
		& (g_SwitchFlag == 0) & (g_SwitchWait == 0) & (g_Player.NowColor == 4)) { //�X�C�b�`�t���O��OFF�ł���ҋ@���Ԃ��O�ł���X�C�b�`�Əd�Ȃ��Ă���
		g_SwitchFlag = 1;														  //���o�[�̐F�Ǝ�l���������ł����ԂŃC���^���N�g�������Ɣ���������
		g_SwitchWait = 10;
		PlaySoundMem(g_Snd.leva, DX_PLAYTYPE_BACK);
	}
	else if ((g_Player.x > 424) & (g_Player.x < 575) & (g_Pad.KEY_B == TRUE)	  //�X�C�b�`��ON�̏ꍇ��OFF�ɐ؂�ւ���
		& (g_SwitchFlag == 1) & (g_SwitchWait == 0) & (g_Player.NowColor == 4)){  //���o�[��ON�܂���OFF�ɂȂ����ꍇ�ҋ@���Ԃ������
		g_SwitchFlag = 0;
		g_SwitchWait = 10;
		PlaySoundMem(g_Snd.leva, DX_PLAYTYPE_BACK);
	}

	if (g_SwitchFlag == 0) {													  
		DrawRotaGraph(500, 623, 1.0, 0, g_pic.Reba, TRUE, FALSE);
	}
	else if (g_SwitchFlag == 1) {
		DrawRotaGraph(500, 623, 1.0, 0, g_pic.Reba, TRUE, TRUE);
		Change(WHITE);
		DrawExtendGraph(700, 558, 800, 668, g_pic.Box, TRUE);
	}
	DrawExtendGraph(700, 558, 800, 668, g_pic.Box, TRUE);
	DrawExtendGraph(700, 458, 800, 568, g_pic.Box, TRUE);
	if (g_SwitchWait != 0) {													//�ҋ@���Ԃ�����ꍇ���炵������
		g_SwitchWait--;
	}
	//DrawFormatString(0, 400, 0x000000, "g_SwitchFlag = %d", g_SwitchFlag);
	Door();			//�X�e�[�W�S�[������
	Lock();

	DoorRotationBox(1);

	ColorReset();

	if (g_Player.PLAYER_MENU == TRUE) {
		Menu_Draw();
		InitFlag = Menu_Update();
	}
	return 0;
}