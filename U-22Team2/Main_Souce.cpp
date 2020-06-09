#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"
#include "Map.h"


/************************************************************************

*�񋓑̂̐錾

*************************************************************************/
typedef enum GAME_MODE {
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
int GameState = GAME_TITLE;


/***************************************************************

*�֐��v���g�^�C�v�̐錾

****************************************************************/
int Main(void);

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
	SetGraphMode(1280, 768, 32);		//�Q�[����ʎ��̂̃T�C�Y

	/*****�摜�̓ǂݍ���*****/
	//if (LoadImages() == -1)return -1;		//�摜�ǂݍ��݊֐����Ăяo��
	//if (LoadVoice() == -1)return -1;		//�����ǂݍ��݊֐����Ăяo��

	//�Q�[�����[�v
	while (ProcessMessage() == 0 && GameState != END) {

		ClearDrawScreen();		//��ʂ̏�����

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
		case GAME_END:
			//�G���h�`�揈��
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
		}
		ScreenFlip();		//����ʂ̓��e��\��ʂɔ��f
	}
	DxLib_End();			//DX���C�u�����g�p�̏I������
	return 0;				//�\�t�g�̏���
}

int Main(void) {

	Map();

	WaitKey();					//�L�[���͑҂�

	return 0;
}