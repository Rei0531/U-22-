//#include "DxLib.h"
//#include "Player.h"		//�w�b�_�t�@�C���̓ǂݍ��݁F�v���C���[�����̃v���g�^�C�v�錾
//#include "Enemy.h"		//�w�b�_�t�@�C���̓ǂݍ��݁F�G�����̃v���g�^�C�v�錾
#include "LoadPic.h"		//�w�b�_�t�@�C���̓ǂݍ��݁F�\���̂ł̉摜�̒�`
#include "Map.h"			//�w�b�_�t�@�C���̓ǂݍ��݁F�}�b�v�����̃v���g�^�C�v�錾
#include "Controller.h"
#include "Player.h"
#include "Controller.h"
#include "constant.h"

/************************************************************************

*�񋓑̂̐錾

*************************************************************************/
typedef enum GAME_MODE {		//�Q�[���̏��
	GAME_TITLE,
	GAME_MENU,
	GAME_INIT,
	GAME_END,
	GAME_MAIN,
	GAME_CLEAR,
	GAME_OVER,
	END = 99
};
/****************************************************************

*�ϐ��̐錾

****************************************************************/
int GameState = GAME_TITLE;		//�Q�[���̏�Ԃ��i�[����ϐ�


Controller g_Pad;
extern Controller g_Pad;


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
	//if (LoadVoice() == -1)return -1;		//�����ǂݍ��݊֐����Ăяo��

	//�Q�[�����[�v
	while (ProcessMessage() == 0 && GameState != END) {

		ClearDrawScreen();		//��ʂ̏�����

		//�}�E�X�̈ʒu���擾
		GetMousePoint(&g_Pad.MouseX, &g_Pad.MouseY);		//�f�o�b�O�p�Ƃ��A�摜�z�u�p�Ƀ}�E�X���W�擾

		switch (GameState) {
		case GAME_TITLE:
			Main();
			//�^�C�g������
			break;
		case GAME_MENU:
			//�Q�[�����j���[����
			break;
		case GAME_INIT:
			//�Q�[����������
			break;
		case GAME_MAIN:
			//�Q�[�����C������
			break;
		case GAME_CLEAR:
			//�Q�[���N���A����
			break;
		case GAME_OVER:
			//�Q�[���I�[�o�[�`�揈��
			break;
		case GAME_END:
			//�G���h�`�揈��
			break;
		}

		DrawFormatString(0, 0, 0xff0000, "X %d ", g_Pad.MouseX);
		DrawFormatString(0, 10, 0xff0000, "Y %d ", g_Pad.MouseY);
		DrawFormatString(0, 20, 0xff0000, "NowKey %d ", g_Pad.NowKey);
		ScreenFlip();		//����ʂ̓��e��\��ʂɔ��f
	}
	DxLib_End();			//DX���C�u�����g�p�̏I������
	return 0;				//�\�t�g�̏���
}
int Title(void) {
	return 0;
}
int Menu(void) {
	return 0;
}
int Init(void) {
	return 0;
}
int Main(void) {
	ControllerVlue();
	Map();
	Player();
	return 0;
}
int Clear(void) {
	return 0;
}
int Over(void) {
	return 0;
}
int End(void) {
	return 0;
}