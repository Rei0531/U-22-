#pragma once
/**********************************************
*�Q�[����̒萔�̐錾
***********************************************/
const int PLAYERX = 8;			//�}�b�v�X�N���[�����x,��ʒ[�v���C���[�̈ړ����x
const int SCREEN_WIDHT = 1280;	//��ʂ̉��̃T�C�Y
const int SCREEN_HEIGHT = 768;	//��ʂ̏c�̃T�C�Y
const int MAP_WIDHT = SCREEN_WIDHT * 4;	//�}�b�v�摜�̉��̃T�C�Y
const int MAP_HEIGHT = SCREEN_HEIGHT * 2;	//�}�b�v�摜�̏c�̃T�C�Y

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
static int GameState = GAME_TITLE;		//�Q�[���̏�Ԃ��i�[����ϐ�

