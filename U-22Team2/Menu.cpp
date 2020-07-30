#include "Menu.h"

static bool DOWN = FALSE,//���L�[
            UP = FALSE;//��L�[

//�X�V
bool Menu_Update() {

    if (g_Pad.KEY_DOWN == TRUE && DOWN == FALSE) {//���L�[��������Ă�����
        DOWN = TRUE;
        NowSelect = (NowSelect + 1) % eMenu_Num;//�I����Ԃ��������
    }
    if (g_Pad.KEY_UP == TRUE && UP == FALSE) {//��L�[��������Ă�����
        UP = TRUE;
        NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//�I����Ԃ���グ��
    }

    DOWN = (g_Pad.KEY_DOWN == TRUE) ? TRUE : FALSE;//���L�[��������Ă�����

    UP = (g_Pad.KEY_UP == TRUE) ? TRUE : FALSE;//��L�[��������Ă�����

    if (g_Pad.KEY_B == TRUE) {//B�{�^���������ꂽ��
        switch (NowSelect) {//���ݑI�𒆂̏�Ԃɂ���ď����𕪊�
        case eMenu_Select://�Z���N�g�I�𒆂Ȃ�
            //�{���͂����ɃZ���N�g��ʈȍ~����
            GameState = GAME_MAIN;//�V�[�����Z���N�g��ʂɕύX
            g_Player.PLAYER_MENU = FALSE;//���j���[���J���t���O��FALSE�ɂ���
            break;
        case eMenu_Reset://���Z�b�g�I�𒆂Ȃ�
            g_Player.PLAYER_MENU = FALSE;//���j���[���J���t���O��FALSE�ɂ���
            g_Player.PLAYER_RESET = TRUE;  //���Z�b�g����������TRUE�ɂ���
            return TRUE;    //�X�e�[�W���������Z�b�g���鏈���̃t���O��TRUE�ɂ���
            break;
        case eMenu_End:
            g_Player.PLAYER_MENU = FALSE;//���j���[���J���t���O��FALSE�ɂ���
            break;

        }
    }
    return FALSE;
}

//�`��
void Menu_Draw() {
    static int MenuX = 440, MenuY = 200;
    DrawBox(MenuX, 200, MenuX+400, MenuY+400,GetColor(200,200,200),TRUE);
    DrawString(MenuX + 100, MenuY + 100, "���j���[��ʂł��B", GetColor(0, 0, 0));
    DrawString(MenuX + 150, GAME_Y, "�X�e�[�W�Z���N�g", GetColor(0, 0, 0));
    DrawString(MenuX + 150, RESET_Y, "���Z�b�g", GetColor(0, 0, 0));
    DrawString(MenuX + 150, END_Y, "�I��", GetColor(0, 0, 0));
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
    DrawString(MenuX + 120, y, "��", GetColor(0, 0, 0));
}