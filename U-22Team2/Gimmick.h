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
	//��x����̃X�C�b�`�p�̕ϐ�_____________
	int OTSwitchFlag = 0;
	//���e�p�̕ϐ�___________________________
	int g_Bomb = 0;
};

int Shower(void);		//�h��Ԃ��V�����[�̏���
int Lever(void);		//���o�[�̏���
int SlideBlock(void);	//�������̏���
int CC_Switch(int Color, int x,int y);	//�v���C���[�̉������F�𔽉f����X�C�b�`�̏���//�����F���������_�̃v���C���[�̐F��n��
int OneTimeSwitch(void); //��x����̃X�C�b�`
int Bomb(void);			//�{�b�N�X�j��̔��e