#pragma once
#include "DxLib.h"
#include "Color.h"

struct LockALL {		//�m�u���܂߂������ɕK�v�ȕϐ�
public:
	//�E��[]���X�e�[�W���A����[]���m�u�A�����̐�
	int color[25][4]{		//�m�u�ƌ��̌�		//0�F�m�u�@�P�`����

		{BLUE},							//�X�e�[�W1�@�O�F�m�u�A�P�`�F�����̐F
		{LIGHTBLUE,BLUE, RED},			//�X�e�[�W2�@�O�F�m�u�A�P�`�F�����̐F
		{ORENGE,YELLOW,PURPLE},			//�X�e�[�W3�@�O�F�m�u�A�P�`�F�����̐F
		{RED},							//�X�e�[�W4�@�O�F�m�u�A�P�`�F�����̐F
		{YELLOW},						//�X�e�[�W5�@�O�F�m�u�A�P�`�F�����̐F
		{RED},							//�X�e�[�W6�@�O�F�m�u�A�P�`�F�����̐F
		{GREEN,RED},					//�X�e�[�W7�@�O�F�m�u�A�P�`�F�����̐F
		{RED,BLUE},						//�X�e�[�W8�@�O�F�m�u�A�P�`�F�����̐F
		{LIGHTBLUE,RED,BLUE},			//�X�e�[�W9�@�O�F�m�u�A�P�`�F�����̐F
		{BLUE},						//�X�e�[�W10�́@�O�F�m�u�A�P�`�F�����̐F
		{BLUE},						//�X�e�[�W11�́@�O�F�m�u�A�P�`�F�����̐F
		{BLUE},						//�X�e�[�W12�́@�O�F�m�u�A�P�`�F�����̐F
		{RED},						//�X�e�[�W13�́@�O�F�m�u�A�P�`�F�����̐F
		{YELLOW,BLUE},				//�X�e�[�W14�́@�O�F�m�u�A�P�`�F�����̐F
		{RED,BLUE},					//�X�e�[�W15�́@�O�F�m�u�A�P�`�F�����̐F
		{GREEN,YELLOW},				//�X�e�[�W16�́@�O�F�m�u�A�P�`�F�����̐F
		{RED},						//�X�e�[�W17�́@�O�F�m�u�A�P�`�F�����̐F
		{RED},						//�X�e�[�W18�́@�O�F�m�u�A�P�`�F�����̐F
		{PURPLE,GREEN,LIGHTBLUE},	//�X�e�[�W19�́@�O�F�m�u�A�P�`�F�����̐F
		{RED,BLUE,YELLOW},			//�X�e�[�W20�́@�O�F�m�u�A�P�`�F�����̐F
		{RED,YELLOW,BLUE},			//�X�e�[�W21�́@�O�F�m�u�A�P�`�F�����̐F
		{YELLOW,BLUE,RED},			//�X�e�[�W22�́@�O�F�m�u�A�P�`�F�����̐F
		{RED,BLUE},						//�X�e�[�W23�́@�O�F�m�u�A�P�`�F�����̐F
		{YELLOW,RED,BLUE,PURPLE},	//�X�e�[�W24�́@�O�F�m�u�A�P�`�F�����̐F
		{RED}						//�X�e�[�W25�́@�O�F�m�u�A�P�`�F�����̐F

	};
	int colorback[25][4]{		//�����̃o�b�N�A�b�v�o�b�N�A�b�v
		{BLUE},							//�X�e�[�W1�@�O�F�m�u�A�P�`�F�����̐F
		{LIGHTBLUE,BLUE, RED},			//�X�e�[�W2�@�O�F�m�u�A�P�`�F�����̐F
		{ORENGE,YELLOW,PURPLE},			//�X�e�[�W3�@�O�F�m�u�A�P�`�F�����̐F
		{RED},							//�X�e�[�W4�@�O�F�m�u�A�P�`�F�����̐F
		{YELLOW},						//�X�e�[�W5�@�O�F�m�u�A�P�`�F�����̐F
		{RED},							//�X�e�[�W6�@�O�F�m�u�A�P�`�F�����̐F
		{GREEN,RED},					//�X�e�[�W7�@�O�F�m�u�A�P�`�F�����̐F
		{RED,BLUE},						//�X�e�[�W8�@�O�F�m�u�A�P�`�F�����̐F
		{LIGHTBLUE,RED,BLUE},			//�X�e�[�W9�@�O�F�m�u�A�P�`�F�����̐F
		{BLUE},						//�X�e�[�W10�́@�O�F�m�u�A�P�`�F�����̐F
		{BLUE},						//�X�e�[�W11�́@�O�F�m�u�A�P�`�F�����̐F
		{BLUE},						//�X�e�[�W12�́@�O�F�m�u�A�P�`�F�����̐F
		{RED},						//�X�e�[�W13�́@�O�F�m�u�A�P�`�F�����̐F
		{YELLOW,BLUE},				//�X�e�[�W14�́@�O�F�m�u�A�P�`�F�����̐F
		{RED,BLUE},					//�X�e�[�W15�́@�O�F�m�u�A�P�`�F�����̐F
		{GREEN,YELLOW},				//�X�e�[�W16�́@�O�F�m�u�A�P�`�F�����̐F
		{RED},						//�X�e�[�W17�́@�O�F�m�u�A�P�`�F�����̐F
		{RED},						//�X�e�[�W18�́@�O�F�m�u�A�P�`�F�����̐F
		{PURPLE,GREEN,LIGHTBLUE},	//�X�e�[�W19�́@�O�F�m�u�A�P�`�F�����̐F
		{RED,BLUE,YELLOW},			//�X�e�[�W20�́@�O�F�m�u�A�P�`�F�����̐F
		{RED,YELLOW,BLUE},			//�X�e�[�W21�́@�O�F�m�u�A�P�`�F�����̐F
		{YELLOW,BLUE,RED},			//�X�e�[�W22�́@�O�F�m�u�A�P�`�F�����̐F
		{RED,BLUE},						//�X�e�[�W23�́@�O�F�m�u�A�P�`�F�����̐F
		{YELLOW,RED,BLUE,PURPLE},	//�X�e�[�W24�́@�O�F�m�u�A�P�`�F�����̐F
		{RED}						//�X�e�[�W25�́@�O�F�m�u�A�P�`�F�����̐F
	};
	//�X�e�[�W��/�m�u�A�����̍��v
	//	�@��	��
	int n[25]{
		1,3,3,1,1,
		1,2,2,3,1,
		1,1,1,2,2,
		2,1,1,3,3,
		3,3,2,4,1 
	};	//�m�u�ƌ����̐�	//�X�e�[�W���ƁA�m�u�A�����̍��v������̐��ɍ��킹��
	int Release = 0; //�����̉�����

	bool
		clearflg = FALSE;
};

int Lock(void);
int UnLock(void);
int Goal(void);