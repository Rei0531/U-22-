#include "LoadPic.h"
#include "Map.h"
#include"Enemy.h"

int LoadPictue(void) {		//�摜�̓ǂݍ���
	if ((g_pic.Map = LoadGraph("image/Stage_Deffault.jpg")) == -1) return -1;	//�X�e�[�W�̊�{�w�i
	if (LoadDivGraph("image/player01.png", 5, 5, 1, 100, 200, g_pic.Player) == -1) return -1;//�v���C���[�̕����摜

	if ((g_pic.Title = LoadGraph("image/Title(proto).png")) == -1) return -1;//�^�C�g�����
	if ((g_pic.StageClear = LoadGraph("image/stageimage(���j.png")) == -1)return -1;//�X�e�[�W�N���A���

	if ((g_pic.Box = LoadGraph("image/Box2.png")) == -1)return -1;//�ؔ�
	if ((g_pic.Box_Move = LoadGraph("image/Box_Move.png")) == -1)return -1;//�����ؔ�
	if ((g_pic.Pin = LoadGraph("image/Pin.png")) == -1)return -1;//�s���}�����Ƃ���

	if (LoadDivGraph("image/All_Object.png", 10, 10, 1, 150, 150, g_pic.Object) == -1) return -1;//�I�u�W�F�N�g�̕����摜

	return 0;
}