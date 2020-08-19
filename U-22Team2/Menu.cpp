#include "Menu.h"
#include "LoadSound.h"


extern Sound g_Snd;
extern image g_pic;

static bool DOWN = FALSE,//���L�[
            UP = FALSE,//��L�[
            B = FALSE;//B�{�^��

static bool Sndflg = FALSE;//���Đ��t���O

//�X�V
bool Menu_Update() {

    if (CheckSoundMem(g_Snd.MenuOpen) == 0 && Sndflg == FALSE) {
        PlaySoundMem(g_Snd.MenuOpen, DX_PLAYTYPE_BACK);
        Sndflg = TRUE;//���Đ��t���O��TRUE�ɂ��ē�x�Đ��h�~
    }

    if (g_Pad.KEY_DOWN == TRUE && DOWN == FALSE) {//���L�[��������Ă�����
        DOWN = TRUE;
        NowSelect = (NowSelect + 1) % eMenu_Num;//�I����Ԃ��������
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
    }
    if (g_Pad.KEY_UP == TRUE && UP == FALSE) {//��L�[��������Ă�����
        UP = TRUE;
        NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//�I����Ԃ���グ��
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
    }

    DOWN = (g_Pad.KEY_DOWN == TRUE) ? TRUE : FALSE;//���L�[��������Ă�����

    UP = (g_Pad.KEY_UP == TRUE) ? TRUE : FALSE;//��L�[��������Ă�����

    if (g_Pad.KEY_B == TRUE && B == FALSE) {//B�{�^���������ꂽ��
        Sndflg = FALSE;//���j���[�I�[�v���̃t���O��FALSE�ɂ��čēx�֐��ɓ�������������悤�ɂ���
        switch (NowSelect) {//���ݑI�𒆂̏�Ԃɂ���ď����𕪊�
        case eMenu_Select://�Z���N�g�I�𒆂Ȃ�
            //�{���͂����ɃZ���N�g��ʈȍ~����
            GameState = GAME_TITLE;//�V�[�����Z���N�g��ʂɕύX
            g_Player.PLAYER_MENU = FALSE;//���j���[���J���t���O��FALSE�ɂ���
            g_Player.InitFlag = TRUE;//�X�e�[�WInit�����̃t���O��TRUE�ɂ���
            g_Player.PLAYER_RESET = TRUE;//���Z�b�g������TRUE�ɂ���
            break;
        case eMenu_Reset://���Z�b�g�I�𒆂Ȃ�
            g_Player.PLAYER_MENU = FALSE;//���j���[���J���t���O��FALSE�ɂ���
            g_Player.PLAYER_RESET = TRUE;  //���Z�b�g����������TRUE�ɂ���
            PlaySoundMem(g_Snd.Reset, DX_PLAYTYPE_BACK);
            return TRUE;    //�X�e�[�W���������Z�b�g���鏈���̃t���O��TRUE�ɂ���
            break;
        case eMenu_End:
            g_Player.PLAYER_MENU = FALSE;//���j���[���J���t���O��FALSE�ɂ���
            PlaySoundMem(g_Snd.MenuClose, DX_PLAYTYPE_BACK);//���j���[������Ƃ��̉�
            break;

        }
    }

    B = (g_Pad.KEY_B == TRUE) ? TRUE : FALSE;//B�{�^����������Ă�����/�ēxB�{�^����������悤��

    return FALSE;
}

//�`��
void Menu_Draw() {

    static int MenuX = 440, MenuY = 200;	

    //���j���[��ʂ̕`��
    DrawExtendGraph(MenuX, MenuY, MenuX + 400, MenuY + 400,g_pic.Menu,TRUE);
    DrawRotaGraph(MenuX + 200, GAME_Y, 0.3, 0, g_pic.MenuChar[0], TRUE, FALSE);
    DrawRotaGraph(MenuX + 200, RESET_Y, 0.3, 0, g_pic.MenuChar[1], TRUE, FALSE);
    DrawRotaGraph(MenuX + 200, END_Y, 0.3, 0, g_pic.MenuChar[2], TRUE, FALSE);
    DrawExtendGraph(500, 250, 756, 378, g_pic.MenuBotan, TRUE);

    int y = 0;
    switch (NowSelect) {//���݂̑I����Ԃɏ]���ď����𕪊�
    case eMenu_Select://�Z���N�g�I�𒆂Ȃ�
        y = GAME_Y;    //�Z���N�g�̍��W���i�[
        break;
    case eMenu_Reset://���Z�b�g�I�𒆂Ȃ�
        y = RESET_Y;    //���Z�b�g�̍��W���i�[
        break;
    case eMenu_End://�I���I�𒆂Ȃ�
        y = END_Y;      //�I���̍��W���i�[
    }
    DrawRotaGraph(MenuX + 90, y, 1.0, 0, g_pic.Pin, TRUE, TRUE);
}