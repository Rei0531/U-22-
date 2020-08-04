#include "DxLib.h"
#include "Controller.h"
#include "LoadPic.h"
#include "constant.h"
#include "Title.h"
#include "LoadSound.h"


extern Sound g_Snd;

static bool //��x�����h�~
DOWN = FALSE,//���L�[
UP = FALSE,//��L�[
B = FALSE;//B�{�^��

static bool Sndflg = FALSE;//���Đ��t���O
extern image g_pic;
extern Controller g_Pad;

void Title_Update() {

    if (CheckSoundMem(g_Snd.MenuOpen) == 0 && Sndflg == FALSE) {
        PlaySoundMem(g_Snd.MenuOpen, DX_PLAYTYPE_BACK);
        Sndflg = TRUE;//���Đ��t���O��TRUE�ɂ��ē�x�Đ��h�~
    }

    if (g_Pad.KEY_DOWN == TRUE && DOWN == FALSE) {//���L�[��������Ă�����
        DOWN = TRUE;
        NowSelect = (NowSelect + 1) % eTitle_Num;//�I����Ԃ��������
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
    }
    if (g_Pad.KEY_UP == TRUE && UP == FALSE) {//��L�[��������Ă�����
        UP = TRUE;
        NowSelect = (NowSelect + (eTitle_Num - 1)) % eTitle_Num;//�I����Ԃ���グ��
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
    }


    DOWN = (g_Pad.KEY_DOWN == TRUE) ? TRUE : FALSE;//���L�[��������Ă�����

    UP = (g_Pad.KEY_UP == TRUE) ? TRUE : FALSE;//��L�[��������Ă�����

    if (g_Pad.KEY_B == TRUE && B == FALSE) {//B�{�^���������ꂽ��
        B = TRUE;//�ēx�{�^����������
        Sndflg = FALSE;//���j���[�I�[�v���̃t���O��FALSE�ɂ��čēx�֐��ɓ�������������悤�ɂ���
        switch (NowSelect) {//���ݑI�𒆂̏�Ԃɂ���ď����𕪊�
        case eTitle_Select://�Z���N�g�I�𒆂Ȃ�
            //�{���͂����ɃZ���N�g��ʈȍ~����
            GameState = GAME_MAIN;//�Z���N�g��ʂ���s������
            break;
        case eTitle_SpecialThanks://�X�y�V�����T���N�X�I�𒆂Ȃ�
            GameState = GAME_MAIN;
            break;
        case eTitle_End:
            DxLib_End();//�I������
            break;

        }
    }

    B = (g_Pad.KEY_B == TRUE) ? TRUE : FALSE;//B�{�^����������Ă�����/�ēxB�{�^����������悤��
}
void Title_Draw() {
    static int MenuX = 634, MenuY = 200;
    static int BoxX = 0;//�I���J�[�\���̃v���X����ʂ̈ʒu;
    DrawRotaGraph(MenuX, SELECT_Y,0.5,0,g_pic.TitleChar[0],TRUE,FALSE);
    DrawRotaGraph(MenuX, THANKS_Y, 0.5, 0, g_pic.TitleChar[1], TRUE, FALSE);
    DrawRotaGraph(MenuX, END_Y, 0.5, 0, g_pic.TitleChar[2], TRUE, FALSE);
    int y = 0;
    switch (NowSelect) {//���݂̑I����Ԃɏ]���ď����𕪊�
    case eTitle_Select://�Z���N�g�I�𒆂Ȃ�
        y = SELECT_Y;    //�Z���N�g�̍��W���i�[
        BoxX = -175;
        break;
    case eTitle_SpecialThanks://���Z�b�g�I�𒆂Ȃ�
        y = THANKS_Y;    //�X�y�V�����T���N�X�̍��W���i�[
        BoxX = -210;
        break;
    case eTitle_End://�I���I�𒆂Ȃ�
        y = END_Y;      //�I���̍��W���i�[
        BoxX = -70;
    }

    DrawRotaGraph(MenuX + BoxX, y - 5,1.0,0,g_pic.Pin,TRUE,TRUE);
}

int GameTitle(void) {
	DrawRotaGraph(SCREEN_WIDHT / 2, SCREEN_HEIGHT / 2, 1.0, 0,g_pic.Title, TRUE, FALSE); //�^�C�g���摜�`��
    Title_Update();
    Title_Draw();
	return 0;
}