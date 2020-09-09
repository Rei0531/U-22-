#include "DxLib.h"
#include "Door.h"
#include "Color.h"
#include "Map.h"
#include "Lock.h"
#include "Draw_Door_Rotation.h"


#define PI 3.141592654

extern DoorAll g_Door;
extern MapCoordinate g_MapC;
extern LockALL g_Lock;
extern Player g_Player;

float Move_Rotation = 0.0,
Rot_anicnt = 0.0,//��]�̃A�j���p�̕ϐ�
Rot_Circle = 0.0;//���[�e�[�V�����p�̕ϐ�

//Rot_sum:���[�e�V��������
void DoorRotationBox(int Rot_sum) {

	Rot_anicnt -= 0.05;//������]������

	double RotationAngle = (PI*2.0) / (double)Rot_sum;

	if (g_Door.Picupflg == TRUE) {//�h�A�̃��[�e�[�V������i�߂�t���O��TRUE�̎�
		Rot_Circle = Move_Rotation;//���[�e�V��������J�n�ʒu���擾
		Move_Rotation += (PI * 2.0) / (double)Rot_sum;
		g_Door.Picupflg = FALSE;
	}
	//���[�e�V�������鏈��
	if (Move_Rotation > Rot_Circle) {
		Rot_Circle += 0.1;
	}

	//�X�e�[�W�N���A�������A�^�C�g����ʂɖ߂����Ƃ�,�X�e�[�W���Z�b�g���ꂽ�Ƃ�
	if (g_Lock.clearflg == TRUE || g_Player.InitFlag == TRUE || g_Player.PLAYER_RESET == TRUE) {
		Move_Rotation = 0.0;//���[�e�[�V�����摜�̈ړ��ʂ����Z�b�g����
		g_Player.PLAYER_RESET = FALSE;
		Rot_Circle = 0.0;
	}

	//���[�e�[�V�������鐔�ɍ��킹�ĕ`�悷�鐔�����߂�
	if (Rot_sum >= 1) {
		Change2(g_Door.Rotation[g_MapC.StageNumber - 1][0]);
		DrawRotaGraph(g_Door.x + 50, g_Door.y - 30, 1.0, RotationAngle * 4.0 - Rot_Circle, g_pic.Door_Rotation[Rot_sum - 1], TRUE, FALSE);
	}
	if (Rot_sum >= 2) {
		Change2(g_Door.Rotation[g_MapC.StageNumber - 1][1]);
		DrawRotaGraph(g_Door.x + 50, g_Door.y - 30, 1.0, RotationAngle * 5.0 - Rot_Circle, g_pic.Door_Rotation[Rot_sum - 1], TRUE, FALSE);
	}
	if (Rot_sum >= 3) {
		Change2(g_Door.Rotation[g_MapC.StageNumber - 1][2]);
		DrawRotaGraph(g_Door.x + 50, g_Door.y - 30, 1.0, RotationAngle * 6.0 - Rot_Circle, g_pic.Door_Rotation[Rot_sum - 1], TRUE, FALSE);
	}
	if (Rot_sum >= 4) {
		Change2(g_Door.Rotation[g_MapC.StageNumber - 1][3]);
		DrawRotaGraph(g_Door.x + 50, g_Door.y - 30, 1.0, RotationAngle * 7.0 - Rot_Circle, g_pic.Door_Rotation[Rot_sum - 1], TRUE, FALSE);
	}
	DrawRotaGraph(g_Door.x + 50, g_Door.y - 30, 0.7, Rot_anicnt, g_pic.Door_Rot_Yajirusi, TRUE, FALSE);
}
