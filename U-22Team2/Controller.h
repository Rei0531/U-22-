#pragma once
#include "DxLib.h"

struct Controller {
public:
	int NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);;		//���݂̃L�[���
	int OldKey = NowKey;		//�O�̃L�[�̏��
	int KeyFlg = NowKey & ~OldKey;	//�L�[�t���O
	int MouseX = 0;;
	int MouseY = 0;

	bool		//�L�[�t���O,TRUE,FALSE�ŕԂ��B�f�t�H���g��FALSE
		KEY_LEFT = FALSE,	//������
		KEY_RIGHT = FALSE, //�E����
		KEY_DOWN = FALSE,	//������
		KEY_UP = FALSE,		//�����
		KEY_A = FALSE,		//A�{�^������
		KEY_B = FALSE,		//B�{�^������
		KEY_X = FALSE,		//X�{�^������
		KEY_Y = FALSE,		//Y�{�^������
		KEY_LR = FALSE;	//L1,R1�{�^������

	void KEY_Init() {			//�L�[���͏�Ԃ����ׂă��Z�b�g����
			KEY_LEFT = FALSE,	//������
			KEY_RIGHT = FALSE, //�E����
			KEY_DOWN = FALSE,	//������
			KEY_A = FALSE,		//A�{�^������
			KEY_B = FALSE,		//B�{�^������
			KEY_X = FALSE,		//X�{�^������
			KEY_Y = FALSE,		//Y�{�^������
			KEY_LR = FALSE;	//L1,R1�{�^������
	}
};
void ControllerVlue(void);