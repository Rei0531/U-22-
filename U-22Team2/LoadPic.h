#pragma once
#include "DxLib.h"
struct image {
public:
	int Map;		//���C���ƂȂ�}�b�v�摜
	int Player[3];		//��l���̃l�Y�~�̉摜
	int Enemy[5];		//�Ǝ�
};

int LoadPictue(void);	//�֐��̒�`
