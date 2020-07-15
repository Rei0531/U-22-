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
extern Controller g_Pad;

static bool InitFlag = TRUE;//Init�֐���ʂ��Ă���������ϐ�/TRUE������/FALSE���_��
//�I�u�W�F�N�g�̏����ʒu
static int 
obj1x1 = 600,
obj1x2 = obj1x1 + 150,
obj2x1 = 750,
obj2x2 = obj2x1 + 150,
obj3x1 = 900,
obj3x2 = obj3x1 + 150,
obj4x1 = 1050,
obj4x2 = obj4x1 + 150,
objALLy1 = 518,
objALLy2 = 668;


static int Speed = 2,
	move_x = 0,
	move_cnt = 0,
	move_max = 120;

static int SwitchFlag = 0;		//���o�[��ON�AOFF
static int SwitchWait = 0;		//���o�[�̑ҋ@����

void Stage7Init() {
	//�v���C���[�̏����ʒu
	//�I�u�W�F�N�g�̏����ʒu��`��
	g_Player.Interact = 999;//�v���C���[���C���^���N�g�ł���񐔂�10��ɐݒ�
	InitFlag = FALSE;	//FALSE�ɂ��Ď�TRUE�ɂȂ�܂Œʂ�Ȃ��悤�ɂ���

	g_Player.x = 110;			//�v���C���[���W������
	g_Player.y = 571;			//�v���C���[���W������
	g_Player.NowColor = 6;		//�v���C���[�̐F������

	g_Door.RotationNumber = 0;	//���[�e�[�V����������
	g_Lock.Release = 0;			//����������������


	SwitchFlag = 0;			//�X�C�b�`������

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//�h�A�̈ʒu
	g_Door.x = 100;
	g_Door.y = 170;
	g_Door.w = 200;
	g_Door.h = 370;


	//���̈ʒu���Z�b�g
	obj1x1 = 500;
	obj1x2 = obj1x1 + 100;
	obj2x1 = 750;
	obj2x2 = obj2x1 + 100;
	obj3x1 = 350;
	obj3x2 = obj3x1 + 100;
	obj4x1 = 900;
	obj4x2 = obj4x1 + 100;
	objALLy1 = 568;
	objALLy2 = 668;

	g_Object.Init();//�I�u�W�F�N�g�̈ړ��ʃ��Z�b�g
}

int Stage7(void) {			//�}�b�v�摜�̕`��

	if ((InitFlag == TRUE) || (g_Player.PLAYER_MENU == TRUE)) {//Init�t���O��TRUE�̎��ɏ������ł���,�܂��́AY�{�^���������ꂽ�Ƃ��������ł���
		Stage7Init();
		g_Player.PLAYER_MENU = FALSE;
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//�}�b�v�̕`��
	//�F�u���b�N�`��
	Change(YELLOW);
	DrawExtendGraph(obj4x1, objALLy1, obj4x2, objALLy2, g_pic.Box, TRUE);
	DrawExtendGraph(obj1x1 + g_Object.YELLOW_x, objALLy1, obj1x2 + g_Object.YELLOW_x, objALLy2, g_pic.Box_Move, TRUE);
	DrawExtendGraph(obj1x1 + g_Object.YELLOW_x, objALLy1 - 100, obj1x2 + g_Object.YELLOW_x, objALLy2 - 100, g_pic.Box_Move, TRUE);
	Change(BLUE);
	DrawExtendGraph(obj3x1, objALLy1, obj3x2, objALLy2, g_pic.Box, TRUE);
	DrawExtendGraph(obj2x1 + g_Object.BLUE_x, objALLy1, obj2x2 + g_Object.BLUE_x, objALLy2, g_pic.Box_Move, TRUE);
	DrawExtendGraph(obj2x1 + g_Object.BLUE_x, objALLy1-100, obj2x2 + g_Object.BLUE_x, objALLy2 - 100, g_pic.Box_Move, TRUE);


	//����������___________________________________________________________________________________________________
	Change(RED);
	move_x -= Speed;
	move_x -= Speed;
	if (move_cnt++ > move_max) {
		move_cnt = 0;
		Speed = Speed * (-1);
	}
	DrawExtendGraph(800 + move_x, 320, 950 + move_x, 370, g_pic.Box, TRUE);//������
	DrawExtendGraph(1180,265,1280,370, g_pic.Box,TRUE);//�F���悤�̐�

	//�V�����[����___________________________________________________________________________________________________
	Change(PURPLE);
	if ((70 < g_Player.x & 210 > g_Player.x) & (440 < g_Player.y & 680 > g_Player.y)) {
		g_Player.NowColor = PURPLE;
	}
	DrawExtendGraph(70, 440, 210, 680, g_pic.syawa, TRUE);

	//���o�[����___________________________________________________________________________________________________
	Change(BLUE);
	if ((g_Player.x > 0) & (g_Player.x < 200) & (g_Pad.KEY_B == TRUE)
		& (SwitchFlag == 0) & (SwitchWait == 0) & (g_Player.NowColor == BLUE)) { //�X�C�b�`�t���O��OFF�ł���ҋ@���Ԃ��O�ł���X�C�b�`�Əd�Ȃ��Ă���
		SwitchFlag = 1;														  //���o�[�̐F�Ǝ�l���������ł����ԂŃC���^���N�g�������Ɣ���������
		SwitchWait = 10;
	}
	else if ((g_Player.x > 0) & (g_Player.x < 200) & (g_Pad.KEY_B == TRUE)	  //�X�C�b�`��ON�̏ꍇ��OFF�ɐ؂�ւ���
		& (SwitchFlag == 1) & (SwitchWait == 0) & (g_Player.NowColor == BLUE)) {  //���o�[��ON�܂���OFF�ɂȂ����ꍇ�ҋ@���Ԃ������
		SwitchFlag = 0;
		SwitchWait = 10;
	}

	if (SwitchFlag == 0) {
		DrawRotaGraph(51, 337, 0.7, 0, g_pic.Reba, TRUE, FALSE);
	}
	else if (SwitchFlag == 1) {
		DrawRotaGraph(51, 337, 0.7, 0, g_pic.Reba, TRUE, TRUE);
		Change(WHITE);
		DrawExtendGraph(200, 270, 300, 370, g_pic.Box, TRUE);
	}
	Change(YELLOW);
	DrawExtendGraph(200, 270, 300, 370, g_pic.Box, TRUE);
	if (SwitchWait != 0) {													//�ҋ@���Ԃ�����ꍇ���炵������
		SwitchWait--;
	}

	//���E�̕ǁi�����u���b�N�j
	Change(NONCOLOR);
	DrawBox(0,370,300,420,GetColor(255,255,255),TRUE);
	DrawBox(1080, 370, 1280, 420, GetColor(255, 255, 255), TRUE);
	Door();			//�X�e�[�W�S�[������
	Lock();


	static int
		RotationNum = 4,//���[�e�[�V�������鐔
		X_Size = 100 / RotationNum;//���[�e�[�V�����̃{�b�N�X�̉��̃T�C�Y

	Change(g_Door.Rotation[g_MapC.StageNumber - 1][0]);
	DrawBox(g_Door.x, g_Door.y-30, g_Door.x + X_Size, g_Door.y, GetColor(255, 255, 255), TRUE);
	Change(g_Door.Rotation[g_MapC.StageNumber - 1][1]);
	DrawBox(g_Door.x + X_Size, g_Door.y - 30, g_Door.x + X_Size*2, g_Door.y, GetColor(255, 255, 255), TRUE);
	Change(g_Door.Rotation[g_MapC.StageNumber - 1][2]);
	DrawBox(g_Door.x + X_Size * 2, g_Door.y - 30, g_Door.x + X_Size * 3, g_Door.y, GetColor(255, 255, 255), TRUE);
	Change(g_Door.Rotation[g_MapC.StageNumber - 1][3]);
	DrawBox(g_Door.x + X_Size * 3, g_Door.y - 30, g_Door.x + X_Size * 4, g_Door.y, GetColor(255, 255, 255), TRUE);

	ColorReset();

	return 0;
}