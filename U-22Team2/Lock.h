#pragma once
#include "DxLib.h"
#include "Color.h"

struct LockALL {		//�m�u���܂߂������ɕK�v�ȕϐ�
public:
	//�E��[]���X�e�[�W���A����[]���m�u�A�����̐�
	int color[30][4]{		//�m�u�ƌ��̌�		//0�F�m�u�@�P�`����

		{BLUE},							//�X�e�[�W1
		{LIGHTBLUE,BLUE, RED},			//�X�e�[�W2
		{BLUE,YELLOW,PURPLE},			//�X�e�[�W3
		{RED},							//�X�e�[�W4
		{LIGHTBLUE},					//�X�e�[�W5
		{RED},							//�X�e�[�W6
		{YELLOW,BLUE,RED},				//�X�e�[�W7
		{RED,GREEN},					//�X�e�[�W8
		{RED,GREEN},					//�X�e�[�W9
		{RED},						//�X�e�[�W10�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W11�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W12�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W13�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W14�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W15�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W16�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W17�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W18�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W19�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W20�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W21�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W22�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W23�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W24�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W25�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W26�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W27�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W28�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W29�̃h�A�̃��[�e�[�V�����̏���
		{RED}						//�X�e�[�W30�̃h�A�̃��[�e�[�V�����̏���

	};
	int colorback[30][4]{		//�����̃o�b�N�A�b�v�o�b�N�A�b�v

		{BLUE},							//�X�e�[�W1
		{LIGHTBLUE,BLUE, RED},			//�X�e�[�W2
		{BLUE,YELLOW,PURPLE},			//�X�e�[�W3
		{RED},							//�X�e�[�W4
		{LIGHTBLUE},					//�X�e�[�W5
		{RED},							//�X�e�[�W6
		{YELLOW,BLUE,RED},				//�X�e�[�W7
		{RED,GREEN},					//�X�e�[�W8
		{RED,GREEN},					//�X�e�[�W9
		{RED},						//�X�e�[�W10�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W11�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W12�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W13�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W14�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W15�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W16�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W17�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W18�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W19�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W20�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W21�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W22�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W23�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W24�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W25�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W26�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W27�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W28�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W29�̃h�A�̃��[�e�[�V�����̏���
		{RED}						//�X�e�[�W30�̃h�A�̃��[�e�[�V�����̏���
	};
	//�X�e�[�W��/�m�u�A�����̍��v
	//	�@��	��
	int n[30]{ 1,3,3,1,1,1,3,2,2 ,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };	//�m�u�ƌ����̐�	//�X�e�[�W���ƁA�m�u�A�����̍��v������̐��ɍ��킹��
	int Release = 0; //�����̉�����

	bool
		clearflg = FALSE;

};

int Lock(void);
int UnLock(void);
int Goal(void);