#include"DxLib.h"
#include"LoadSound.h"

extern Sound g_Snd;

int LoadSound(void) {		//���̓ǂݍ���
	if ((g_Snd.Suc = LoadSoundMem("Sound/Supoit.mp3")) == -1)return -1;					//����
	if ((g_Snd.Mis = LoadSoundMem("Sound/Supoit2.mp3")) == -1)return -1;				//���s


	if ((g_Snd.Key_Success = LoadSoundMem("Sound/kacha.mp3")) == -1)return -1;			//���J������
	if ((g_Snd.Key_Miss = LoadSoundMem("Sound/key3.mp3")) == -1)return -1;				//���J�����s

	if ((g_Snd.leva = LoadSoundMem("Sound/lever.mp3")) == -1)return -1;					//���o�[
	if ((g_Snd.BoxDrag = LoadSoundMem("Sound/Box_drag.mp3")) == -1)return -1;			//������������
	if ((g_Snd.Shower = LoadSoundMem("Sound/shower.mp3")) == -1)return -1;				//�V�����[

	if ((g_Snd.Walk = LoadSoundMem("Sound/footsteps.mp3")) == -1)return -1;				//������
	if ((g_Snd.MenuOpen = LoadSoundMem("Sound/MenuOpen.mp3")) == -1)return -1;			//���j���[�I�[�v��
	if ((g_Snd.MenuClose = LoadSoundMem("Sound/MenuClose.mp3")) == -1)return -1;		//���j���[�N���[�Y
	if ((g_Snd.Reset = LoadSoundMem("Sound/Reset.mp3")) == -1)return -1;				//���Z�b�g��
	if ((g_Snd.Switch = LoadSoundMem("Sound/Switch2.mp3")) == -1)return -1;				//�X�C�b�`
	if ((g_Snd.Warp = LoadSoundMem("Sound/Warp2.mp3")) == -1)return -1;					//���[�v

	return 0;
}