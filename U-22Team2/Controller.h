#pragma once
#include "DxLib.h"

struct Controller {
public:
	int NowKey  = GetJoypadInputState(DX_INPUT_KEY_PAD1);;		//���݂̃L�[���
	int OldKey = NowKey;		//�O�̃L�[�̏��
	int KeyFlg = NowKey & ~OldKey;	//�L�[�t���O
};
void ControllerVlue(void);