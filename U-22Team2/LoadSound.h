#pragma once
#include "DxLib.h"
struct Sound {
public:
	int Suc;		//�C���^���N�g��������SE
	int Mis;		//�C���^���N�g���s����SE
	int flg;		//����炷�t���O 0:�点�� 1:�点�Ȃ�
	int Key_Success;//���J������
	int Key_Miss;	//���J�����s
	int leva;		//���o�[��SE
	int BoxDrag;	//������������SE
	int Shower;		//�V�����[��SE
	int Walk;		//����
	int Reset;		//���Z�b�g��
	int MenuOpen;	//���j���[�I�[�v��
	int MenuClose;	//���j���[�N���[�Y
	int Switch;		//�X�C�b�`
	int Warp;		//���[�v
	int Landing;	//���n
	int MenuMove;	//���j���[���ړ�
	int Menu_decision;	//���j���[����
	int Bomb;		//���e
	int StageBGM;	//�X�e�[�WBGM
	int HeartGet;	//�񕜃A�C�e���擾
	int ChangeBlockPlay;	//�ό`�I�u�W�F�N�g�쓮
};

int LoadSound(void);	//�֐��̒�`