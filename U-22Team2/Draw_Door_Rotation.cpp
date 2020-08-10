#include "DxLib.h"
#include "Door.h"
#include "Color.h"
#include "Map.h"
#include "Draw_Door_Rotation.h"


#define PI 3.141592654

extern DoorAll g_Door;
extern MapCoordinate g_MapC;

float Move_Rotation = 0.0;

//Rot_sum:���[�e�V��������
void DoorRotationBox(int Rot_sum) {

	int
		RotationNum = Rot_sum,//���[�e�[�V�������鐔
		X_Size = 100 / RotationNum;//���[�e�[�V�����̃{�b�N�X�̉��̃T�C�Y

	float RotationAngle = (PI*2.0) / (float)Rot_sum;

	if (g_Door.Picupflg == TRUE) {//�h�A�̃��[�e�[�V������i�߂�t���O��TRUE�̎�
		Move_Rotation += (PI * 2.0) / (float)Rot_sum;
		g_Door.Picupflg = FALSE;
	}


	//���[�e�[�V�������鐔�ɍ��킹�ĕ`�悷�鐔�����߂�
	if (Rot_sum >= 1) {
		Change(g_Door.Rotation[g_MapC.StageNumber - 1][0]);
		//DrawBox(g_Door.x, g_Door.y - 30, g_Door.x + X_Size, g_Door.y, GetColor(255, 255, 255), TRUE);
		DrawRotaGraph(g_Door.x + 50, g_Door.y - 30, 1.0, RotationAngle - Move_Rotation, g_pic.Door_Rotation[Rot_sum - 1], TRUE, FALSE);
	}
	if (Rot_sum >= 2) {
		Change(g_Door.Rotation[g_MapC.StageNumber - 1][1]);
		//DrawBox(g_Door.x + X_Size, g_Door.y - 30, g_Door.x + X_Size * 2, g_Door.y, GetColor(255, 255, 255), TRUE);
		DrawRotaGraph(g_Door.x + 50, g_Door.y - 30, 1.0, RotationAngle*2.0 - Move_Rotation, g_pic.Door_Rotation[Rot_sum - 1], TRUE, FALSE);
	}
	if (Rot_sum >= 3) {
		Change(g_Door.Rotation[g_MapC.StageNumber - 1][2]);
		//DrawBox(g_Door.x + X_Size * 2, g_Door.y - 30, g_Door.x + X_Size * 3, g_Door.y, GetColor(255, 255, 255), TRUE);
		DrawRotaGraph(g_Door.x + 50, g_Door.y - 30, 1.0, RotationAngle * 3.0 - Move_Rotation, g_pic.Door_Rotation[Rot_sum - 1], TRUE, FALSE);
	}
	if (Rot_sum >= 4) {
		Change(g_Door.Rotation[g_MapC.StageNumber - 1][3]);
		//DrawBox(g_Door.x + X_Size * 3, g_Door.y - 30, g_Door.x + X_Size * 4, g_Door.y, GetColor(255, 255, 255), TRUE);
		DrawRotaGraph(g_Door.x + 50, g_Door.y - 30, 1.0, RotationAngle * 4.0 - Move_Rotation, g_pic.Door_Rotation[Rot_sum - 1], TRUE, FALSE);
	}
}
