#pragma once
#include "DxLib.h"
//�֐��̐錾
enum Color {
	RED,			//0
	ORENGE,			//1
	YELLOW,			//2
	GREEN,			//3
	LIGHTBLUE,		//4
	BLUE,			//5
	PURPLE,			//6
	BLACK,			//7
	NONCOLOR,		//8
	WHITE,			//9
	MOVE			//10/��������{�b�N�X�̔���J���[
};

enum Color2 {		//�v���C���[�ɃX�|�C�g����Ȃ��F
	RED2,			//0
	ORENGE2,		//1
	YELLOW2,		//2
	GREEN2,			//3
	LIGHTBLUE2,		//4
	BLUE2,			//5
	PURPLE2,		//6
	BLACK2,			//7
	NONCOLOR2,		//8
};

void Change(int Color);
void Change2(int Color2); //�v���C���[�ɃX�|�C�g����Ȃ��F
void ColorReset();




//�֐��̒�`

