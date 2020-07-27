#include "Color.h"
#include "Map.h"
#include "Door.h"

extern MapCoordinate g_MapC;
extern DoorAll g_Door;

int Rotation_Box(int Shift) {

	int Rotation_num = g_Door.RotationNumber % g_Door.ColorNumber[g_MapC.StageNumber - 1];//�ʏ�̃��[�e�[�V�������Ԃ��i�[

	Rotation_num += Shift;//���炵�����l���v���X����

	//���[�e�[�V����������ɂȂ�悤�ɒ�������//��FShift��2�A�ʏ�̃��[�e�V�����ԍ���1�̎��A1+2��3��0���琔����4��ɂȂ邪
	//�X�e�[�W�ɂ���Ă�4������[�e�V�������Ȃ��ꍇ������B�̂�%�Ō��߂�ꂽ���[�e�[�V�����񐔂Ŋ��萳��ɂ��炵���l�����߂�
	Rotation_num = Rotation_num% g_Door.ColorNumber[g_MapC.StageNumber - 1];

	return g_Door.Rotation[g_MapC.StageNumber - 1][Rotation_num];//���炵���l��Ԃ�

}
