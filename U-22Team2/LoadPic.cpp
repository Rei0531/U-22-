#include "LoadPic.h"
#include "Map.h"
#include"Enemy.h"

int LoadPictue(void) {		//�摜�̓ǂݍ���
	if ((g_pic.Map = LoadGraph("image/Stage_Deffault.jpg")) == -1) return -1;	//�X�e�[�W�̊�{�w�i
	if (LoadDivGraph("image/Player02.png", 20, 5, 4, 100, 200, g_pic.Player) == -1) return -1;//�v���C���[�̕����摜

	//if ((g_pic.Title = LoadGraph("image/Title.png")) == -1) return -1;//�^�C�g�����
	if (LoadDivGraph("image/Title_name.png", 13, 13, 1, 128, 128 , g_pic.TitleName) == -1) return -1;//�^�C�g�����̕��������摜
	if ((g_pic.StageClear = LoadGraph("image/Stageclear.png")) == -1)return -1;//�X�e�[�W�N���A���
	if (LoadDivGraph("image/Goal.Txt.PNG", 3, 1, 3, 1144, 341, g_pic.GoalTxt) == -1) return -1;//�N���A��̕��������摜
	if (LoadDivGraph("image/TitleChar.png", 3, 1, 3, 759, 94, g_pic.TitleChar) == -1) return -1;//�^�C�g���̕��������摜

	if (LoadDivGraph("image/Stage1Txt_ALL.png", 2, 2, 1, 512, 256, g_pic.Stage1Txt) == -1) return -1;//�X�e�[�W1�̃`���[�g���A�������摜
	
	if ((g_pic.How_to_play_background = LoadGraph("image/How_to_play_background.png")) == -1) return -1;//�V�ѕ������̔w�i�摜
	if (LoadDivGraph("image/How_to_play.png", 3, 3, 1, 512, 256, g_pic.How_to_play) == -1)return -1;//�V�ѕ����������摜
	if ((g_pic.StartBotan = LoadGraph("image/STARTBotan.png")) == -1)return-1;//�X�^�[�g�{�^���摜
	if ((g_pic.NextPage = LoadGraph("image/NextPage.png")) == -1) return -1;//���̃y�[�W�摜
	if ((g_pic.BackPage = LoadGraph("image/BackPage.png")) == -1)return -1;	//�O�̃y�[�W�摜
	if ((g_pic.LvUPtxt = LoadGraph("image/Lv_UP_txt.png")) == -1)return -1;	//�����X�e�[�W�X�^�[�g�摜
	if ((g_pic.EndPage = LoadGraph("image/EndPage.png")) == -1)return -1;//����@�摜

	if ((g_pic.Select_Back = LoadGraph("image/Select_Back.png")) == -1)return -1;//�Z���N�g�I�𒆂̂��

	if (LoadDivGraph("image/All_text.png", 12, 2, 6, 512, 128, g_pic.All_text) == -1) return -1;//�S�X�e�[�W�̃M�~�b�N����
	if ((g_pic.Box_text = LoadGraph("image/Box_text.png")) == -1)return-1;						//�X�e�[�W�Q�̃M�~�b�N����

	if ((g_pic.Stage = LoadGraph("image/Stage.png")) == -1)return -1;//���݂̃X�e�[�W

	if ((g_pic.Door = LoadGraph("image/door.png")) == -1)return -1;//�h�A

	if ((g_pic.SpecialThanks = LoadGraph("image/Specialthanks.png")) == -1)return -1;//�X�y�V�����T���N�X�̉摜
	           
	if ((g_pic.Menu = LoadGraph("image/Menu.png")) == -1)return -1;//���j���[���
	if (LoadDivGraph("image/MenuChar.PNG", 3, 1, 3, 600, 200, g_pic.MenuChar) == -1) return -1;//���j���[�����̕����摜
	if (LoadDivGraph("image/StageNumber.PNG", 30, 10, 3, 179, 173, g_pic.StageNum) == -1) return -1;//�X�e�[�W�ԍ��̕����摜
	if ((g_pic.MenuBotan = LoadGraph("image/Botan_setumei.png")) == -1)return-1;

	if (LoadDivGraph("image/nokori2.png", 6, 6, 1, 202, 256, g_pic.Nokori) == -1) return -1;//�c��񐔂̕����摜
	if (LoadDivGraph("image/Nokori_Num.PNG", 10, 10, 1, 170, 200, g_pic.Nokori_Num) == -1) return -1;//�c��񐔂̕����摜

	if ((g_pic.Hand = LoadGraph("image/yubisashi2.png")) == -1)return -1;//�X�|�C�g�ꏊ�\��

	if ((g_pic.Door_Nobu = LoadGraph("image/doanobu.png")) == -1)return -1;//���m�u
	if ((g_pic.Door_keyhole = LoadGraph("image/ita.png")) == -1)return -1;//����
	if (LoadDivGraph("image/Rotation02.png", 4, 4, 1, 100, 100, g_pic.Door_Rotation) == -1) return -1;//�h�A�̃��[�e�[�V����
	if ((g_pic.Door_Rot_Yajirusi = LoadGraph("image/RotationYajirusi.png")) == -1)return -1;//�h�A�̃��[�e�[�V�������

	if (LoadDivGraph("image/Box_All.png", 4, 4, 1, 150, 150, g_pic.Box) == -1) return -1;//���ׂĂ̔�

	if ((g_pic.Pin = LoadGraph("image/Pin.png")) == -1)return -1;//�s���}�����Ƃ���

	if ((g_pic.Pin2 = LoadGraph("image/Pin2.png")) == -1)return -1;//�c��񐔂̕\���̃s��

	if ((g_pic.Object_Wall = LoadGraph("image/Object_Wall.png")) == -1) return -1;			//�{���ƃX�C�b�`�p�̕�

	if ((g_pic.shower = LoadGraph("image/shower.png")) == -1)return-1;	//�V�����[�̉摜
	if ((g_pic.shower_m = LoadGraph("image/shower_water.png")) == -1)return-1;	//�V�����[�̉摜

	if ((g_pic.Reba = LoadGraph("image/lever(2).png")) == -1)return-1;//���o�[

	if ((g_pic.C_Switch = LoadGraph("image/ChangeSwitch.png")) == -1)return-1;//�F�𔽉f����X�C�b�`

	if ((g_pic.Bomb = LoadGraph("image/Bomb.png")) == -1)return-1;					//���e�̉摜
	if ((g_pic.BombEffect = LoadGraph("image/bakudan_effect.png")) == -1) return -1;	//�����̉摜

	if ((g_pic.OneTimeSwitch_OFF = LoadGraph("image/Switch_OFF.png")) == -1)return -1;		//��x����̃X�C�b�`ON�̉摜
	if ((g_pic.OneTimeSwitch_ON = LoadGraph("image/Switch_ON.png")) == -1)return -1;		//OFF�̉摜

	if ((g_pic.Warp_Area = LoadGraph("image/Warp.png")) == -1)return -1;//���[�v�̉摜
	if ((g_pic.Warp_Area2 = LoadGraph("image/Warp_2.png")) == -1)return -1;//���[�v�̉摜
	if (LoadDivGraph("image/ChangeObject.png", 3, 3, 1, 225, 225, g_pic.ChengObject) == -1) return -1;//�ό`����I�u�W�F�N�g
	if (LoadDivGraph("image/ChangeObject_sirusi.png", 4, 4, 1, 75, 75, g_pic.ChengObjectmark) == -1) return -1;//�ό`����I�u�W�F�N�g�@���

	if ((g_pic.item = LoadGraph("image/kaihuku.png")) == -1)return-1;//�X�|�C�g�񕜃A�C�e��

	return 0;
}