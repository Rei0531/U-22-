#include "DxLib.h"
#include "Door.h"
#include "Color.h"
#include "Map.h"
#include "Draw_Door_Rotation.h"

extern DoorAll g_Door;
extern MapCoordinate g_MapC;

//Rot_sum:���[�e�V��������
void DoorRotation(int Rot_sum) {

	int
		RotationNum = Rot_sum,//���[�e�[�V�������鐔
		X_Size = 100 / RotationNum;//���[�e�[�V�����̃{�b�N�X�̉��̃T�C�Y

	//���[�e�[�V�������鐔�ɍ��킹�ĕ`�悷�鐔�����߂�
	if (Rot_sum >= 1) {
		Change(g_Door.Rotation[g_MapC.StageNumber - 1][0]);
		DrawBox(g_Door.x, g_Door.y - 30, g_Door.x + X_Size, g_Door.y, GetColor(255, 255, 255), TRUE);
	}
	if (Rot_sum >= 2) {
		Change(g_Door.Rotation[g_MapC.StageNumber - 1][1]);
		DrawBox(g_Door.x + X_Size, g_Door.y - 30, g_Door.x + X_Size * 2, g_Door.y, GetColor(255, 255, 255), TRUE);
	}
	if (Rot_sum >= 3) {
		Change(g_Door.Rotation[g_MapC.StageNumber - 1][2]);
		DrawBox(g_Door.x + X_Size * 2, g_Door.y - 30, g_Door.x + X_Size * 3, g_Door.y, GetColor(255, 255, 255), TRUE);
	}
	if (Rot_sum >= 4) {
		Change(g_Door.Rotation[g_MapC.StageNumber - 1][3]);
		DrawBox(g_Door.x + X_Size * 3, g_Door.y - 30, g_Door.x + X_Size * 4, g_Door.y, GetColor(255, 255, 255), TRUE);
	}
}
