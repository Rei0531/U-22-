#pragma once



struct GimmickAll {			//�M�~�b�N�ɕK�v�ȕϐ�
public:

	//�V�����[�p�̕ϐ�_______�Q�Q�Q�Q
	int shower_X;					//�����W
	int shower_Y = 670 - 256;		//�c���W�i�n�ʂ̏c���W-�摜�̏c�̑傫���j
	int shower_C;					//�F
	int shower_x;	//�h��Ԃ�����̍��W
	int shower_y;	//
	int shower_w;	//
	int shower_h;	//

	//���o�[�p�̕ϐ�_______�Q�Q�Q�Q
	int SwitchFlag = 0;		//���o�[��ON�AOFF
	int SwitchWait = 0;		//���o�[�̑ҋ@����
	int SwitchColor;		//���o�[�̐F

	//�X���C�h���鏰�̗p�̕ϐ�_______�Q�Q�Q�Q
	int Speed = 2;
	int move_x = 0;
	int move_cnt = 0;
	int move_max = 160;


};

int Shower(void);		//�h��Ԃ��V�����[�̏���
int Lever(void);		//���o�[�̏���
int SlideBlock(void);	//�������̏���