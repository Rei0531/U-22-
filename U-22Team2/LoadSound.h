#pragma once
#include "DxLib.h"
struct Sound {
public:
	int Suc;		//�C���^���N�g��������SE
	int Mis;		//�C���^���N�g���s����SE
	int flg;		//����炷�t���O 0:�点�� 1:�点�Ȃ�
	int Key_Success;//���J������
	int Key_Miss;	//���J�����s
};

int LoadSound(void);	//�֐��̒�`