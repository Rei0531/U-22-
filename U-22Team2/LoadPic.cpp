#include "LoadPic.h"
#include "Map.h"
#include"Enemy.h"

int LoadPictue(void) {		//�摜�̓ǂݍ���
	if ((g_pic.Map = LoadGraph("image/Stage_Deffault.jpg")) == -1) return -1;	//�X�e�[�W�̊�{�w�i
	if (LoadDivGraph("image/Player.png", 20, 5, 4, 100, 200, g_pic.Player) == -1) return -1;//�v���C���[�̕����摜

	if ((g_pic.Title = LoadGraph("image/Title.png")) == -1) return -1;//�^�C�g�����
	if (LoadDivGraph("image/TitleChar.png", 3, 1, 3, 759, 94, g_pic.TitleChar) == -1) return -1;//�^�C�g���̕����摜
	if ((g_pic.StageClear = LoadGraph("image/stageimage(���j.png")) == -1)return -1;//�X�e�[�W�N���A���

	if ((g_pic.Menu = LoadGraph("image/Menu.png")) == -1)return -1;//���j���[���
	if (LoadDivGraph("image/MenuChar.PNG", 3, 1, 3, 600, 200, g_pic.MenuChar) == -1) return -1;//���j���[�����̕����摜
	if (LoadDivGraph("image/StageNumber.PNG", 30, 10, 3, 179, 173, g_pic.StageNum) == -1) return -1;//�X�e�[�W�ԍ��̕����摜

	if ((g_pic.Door_Nobu = LoadGraph("image/doanobu.png")) == -1)return -1;//���m�u
	if ((g_pic.Door_keyhole = LoadGraph("image/ita.png")) == -1)return -1;//����

	if ((g_pic.Box = LoadGraph("image/Box2.png")) == -1)return -1;//�ؔ�
	if ((g_pic.Box_Move = LoadGraph("image/Box_Move.png")) == -1)return -1;//�����ؔ�
	if ((g_pic.Pin = LoadGraph("image/Pin.png")) == -1)return -1;//�s���}�����Ƃ���

	if (LoadDivGraph("image/All_Object.png", 10, 10, 1, 150, 150, g_pic.Object) == -1) return -1;//�I�u�W�F�N�g�̕����摜

	if ((g_pic.shower = LoadGraph("image/shower.png")) == -1)return-1;	//�V�����[�̉摜
	if ((g_pic.shower_m = LoadGraph("image/shower_water.png")) == -1)return-1;	//�V�����[�̉摜


	if ((g_pic.Reba = LoadGraph("image/lever(2).png")) == -1)return-1;//���o�[

	if ((g_pic.C_Switch = LoadGraph("image/ChangeSwitch.png")) == -1)return-1;//�F�𔽉f����X�C�b�`

	if ((g_pic.Rot_Box = LoadGraph("image/RotationBox.png")) == -1)return-1;//���[�e�[�V�����{�b�N�X

	if ((g_pic.Bomb = LoadGraph("image/Bomb.png")) == -1)return-1;					//���e�̉摜
	if ((g_pic.BombEffect = LoadGraph("image/bakudan_effect.png")) == -1) return -1;	//�����̉摜

	if ((g_pic.OneTimeSwitch_OFF = LoadGraph("image/Switch_OFF.png")) == -1)return -1;		//��x����̃X�C�b�`ON�̉摜
	if ((g_pic.OneTimeSwitch_ON = LoadGraph("image/Switch_ON.png")) == -1)return -1;		//OFF�̉摜

	if ((g_pic.Warp_Area = LoadGraph("image/Warp.png")) == -1)return -1;//���[�v�̉摜
	
	if (LoadDivGraph("image/ChangeObject.png", 3, 3, 1, 225, 225, g_pic.ChengObject) == -1) return -1;//�ό`����I�u�W�F�N�g
	if (LoadDivGraph("image/ChangeObject_sirusi.png", 4, 4, 1, 75, 75, g_pic.ChengObjectmark) == -1) return -1;//�ό`����I�u�W�F�N�g�@���

	if ((g_pic.item = LoadGraph("image/kaihuku.png")) == -1)return-1;//�X�|�C�g�񕜃A�C�e��

	return 0;
}