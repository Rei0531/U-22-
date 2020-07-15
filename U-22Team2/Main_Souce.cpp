//#include "DxLib.h"
//#include "Player.h"		//�w�b�_�t�@�C���̓ǂݍ��݁F�v���C���[�����̃v���g�^�C�v�錾
//#include "Enemy.h"		//�w�b�_�t�@�C���̓ǂݍ��݁F�G�����̃v���g�^�C�v�錾
#include "LoadPic.h"		//�w�b�_�t�@�C���̓ǂݍ��݁F�\���̂ł̉摜�̒�`
#include "Map.h"			//�w�b�_�t�@�C���̓ǂݍ��݁F�}�b�v�����̃v���g�^�C�v�錾
#include "Controller.h"
#include "Player.h"
#include "constant.h"
#include "Enemy.h"
#include "Title.h"
#include "Lock.h"
#include "LoadSound.h"
#include "Object.h"

//�f�o�b�O�p�̃}�E�X���W�擾�ϐ��錾
Controller g_Pad;
Player g_Player;
Sound g_Snd;
Object g_Object;
extern Controller g_Pad;
extern Player g_Player;
extern  int GameState= GAME_TITLE;


/***************************************************************

*�֐��v���g�^�C�v�̐錾

****************************************************************/
int Main(void);		//���C������
int Title(void);	//�^�C�g������
int Menu(void);		//���j���[����
int Init(void);		//����������
int Clear(void);	//�N���A����
int Over(void);		//�I�[�o�[����
int End(void);		//�G���h����
/*******************************
*�v���O�����̊J�n
********************************/
//�v���O������WinMain����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	SetWindowSizeChangeEnableFlag(TRUE, 1);
	if (DxLib_Init() == -1)  return -1;		//DX���C�u��������������
	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���
	SetGraphMode(SCREEN_WIDHT, SCREEN_HEIGHT, 32);		//�Q�[����ʎ��̂̃T�C�Y

	/*****�摜�̓ǂݍ���*****/
	if (LoadPictue() == -1)return -1;		//�摜�ǂݍ��݊֐����Ăяo��/���s������G���[
	if (LoadSound() == -1)return -1;		//�����ǂݍ��݊֐����Ăяo��

	//�Q�[�����[�v
	while (ProcessMessage() == 0 && GameState != END) {

		ClearDrawScreen();		//��ʂ̏�����

		//�}�E�X�̈ʒu���擾
		GetMousePoint(&g_Pad.MouseX, &g_Pad.MouseY);		//�f�o�b�O�p�Ƃ��A�摜�z�u�p�Ƀ}�E�X���W�擾

		ControllerVlue();//�R���g���[���[�̓��͏�Ԃ��擾

		switch (GameState) {
		case GAME_TITLE:
			Title();
			//�^�C�g������
			break;
		case GAME_MENU:
			//�Q�[�����j���[����
			break;
		case GAME_INIT:
			//�Q�[����������
			break;
		case GAME_MAIN :
			Main();
			//�Q�[�����C������
			break;
		case GAME_CLEAR:
			Clear();
			//�Q�[���N���A����
			break;
		case GAME_OVER:
			//�Q�[���I�[�o�[�`�揈��
			break;
		case GAME_END:
			//�G���h�`�揈��
			break;
		}
		DrawFormatString(0, 0, 0xff0fff, "X %d ", g_Pad.MouseX);
		DrawFormatString(0, 20, 0xff0fff, "Y %d ", g_Pad.MouseY);
		//DrawFormatString(0, 40, 0xff0000, "Color %d ", c);
		DrawFormatString(0, 60, 0xff0fff, "g_Player.x %d ", g_Player.x);
		DrawFormatString(0, 80, 0xff0fff, "g_Player.y %d ", g_Player.y);
		ScreenFlip();		//����ʂ̓��e��\��ʂɔ��f
	}
	DxLib_End();			//DX���C�u�����g�p�̏I������
	return 0;				//�\�t�g�̏���
}
int Title(void) {
	GameTitle();
	return 0;
}
int Menu(void) {
	return 0;
}
int Init(void) {
	return 0;
}
int Main(void) {
	Map();
	PlayerDraw();
	return 0;
}
int Clear(void) {
	Goal();
	return 0;
}
int Over(void) {
	return 0;
}
int End(void) {
	return 0;
}