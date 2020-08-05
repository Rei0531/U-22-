#include "DxLib.h"
#include "Controller.h"
#include "LoadPic.h"
#include "constant.h"
#include "Title.h"
#include "LoadSound.h"
#include "StageSelect.h"
#include "Map.h"


extern Sound g_Snd;
static bool Sndflg = FALSE;//���Đ��t���O
extern image g_pic;
extern Controller g_Pad;
extern MapCoordinate g_MapC;

void Stage_Update() {

    static bool //��x�����h�~
        DOWN = FALSE,//���L�[
        UP = FALSE,//��L�[
        LEFT = FALSE,//���L�[
        RIGHT = FALSE,//�E�L�[
        B = TRUE;//B�{�^��

    //if (CheckSoundMem(g_Snd.MenuOpen) == 0 && Sndflg == FALSE) {
    //    PlaySoundMem(g_Snd.MenuOpen, DX_PLAYTYPE_BACK);
    //    Sndflg = TRUE;//���Đ��t���O��TRUE�ɂ��ē�x�Đ��h�~
    //}

    if (g_Pad.KEY_DOWN == TRUE && DOWN == FALSE) {//���L�[��������Ă�����
        DOWN = TRUE;
        NowStage = (NowStage + 6) % Stage_Num;//�I����Ԃ��������
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
    }
    if (g_Pad.KEY_UP == TRUE && UP == FALSE) {//��L�[��������Ă�����
        UP = TRUE;
        NowStage = (NowStage + (Stage_Num - 6)) % Stage_Num;//�I����Ԃ���グ��
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
    }
    if (g_Pad.KEY_LEFT == TRUE && LEFT == FALSE) {//���L�[��������Ă�����
        LEFT = TRUE;
        NowStage = (NowStage + (Stage_Num - 1)) % Stage_Num;//�I����Ԃ���グ��
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
    }
    if (g_Pad.KEY_RIGHT == TRUE && RIGHT == FALSE) {//��L�[��������Ă�����
        RIGHT = TRUE;
        NowStage = (NowStage + 1) % Stage_Num;//�I����Ԃ��������
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
    }


    DOWN = (g_Pad.KEY_DOWN == TRUE) ? TRUE : FALSE;//���L�[��������Ă�����

    UP = (g_Pad.KEY_UP == TRUE) ? TRUE : FALSE;//��L�[��������Ă�����

    LEFT = (g_Pad.KEY_LEFT == TRUE) ? TRUE : FALSE;//���L�[��������Ă�����

    RIGHT = (g_Pad.KEY_RIGHT == TRUE) ? TRUE : FALSE;//�E�L�[��������Ă�����


    if (g_Pad.KEY_B == TRUE && B == FALSE) {//B�{�^���������ꂽ��
        B = TRUE;//�ēx�{�^����������
        Sndflg = FALSE;//���j���[�I�[�v���̃t���O��FALSE�ɂ��čēx�֐��ɓ�������������悤�ɂ���
        g_MapC.StageNumber = NowStage+1;
        GameState = GAME_MAIN;
        //switch (NowStage) {//���ݑI�𒆂̏�Ԃɂ���ď����𕪊�
        ////case eTitle_Select://�Z���N�g�I�𒆂Ȃ�
        ////    //�{���͂����ɃZ���N�g��ʈȍ~����
        ////    GameState = GAME_MAIN;//�Z���N�g��ʂ���s������
        ////    break;
        ////case eTitle_SpecialThanks://�X�y�V�����T���N�X�I�𒆂Ȃ�
        ////    GameState = GAME_MAIN;
        ////    break;
        ////case eTitle_End:
        ////    DxLib_End();//�I������
        ////    break;

        //}
    }

    B = (g_Pad.KEY_B == TRUE) ? TRUE : FALSE;//B�{�^����������Ă�����/�ēxB�{�^����������悤��

}
void Stage_Draw() {
    static int MenuX = 634, MenuY = 200;
    static int BoxX = 0;//�I���J�[�\���̃v���X����ʂ̈ʒu;
    //DrawRotaGraph(MenuX, SELECT_Y, 0.5, 0, g_pic.TitleChar[0], TRUE, FALSE);
    //DrawRotaGraph(MenuX, THANKS_Y, 0.5, 0, g_pic.TitleChar[1], TRUE, FALSE);
    //DrawRotaGraph(MenuX, END_Y, 0.5, 0, g_pic.TitleChar[2], TRUE, FALSE);
    //�X�e�[�W�̂т傤���@
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            DrawBox(168 + j * 168,26 + i * 156,268 + j * 168,126 + i * 156,0xff0000,TRUE);
        }
    }
    //switch (NowStage) {//���݂̑I����Ԃɏ]���ď����𕪊�
    //case eTitle_Select://�Z���N�g�I�𒆂Ȃ�
    //    //y = SELECT_Y;    //�Z���N�g�̍��W���i�[
    //    BoxX = -175;
    //    break;
    //case eTitle_SpecialThanks://���Z�b�g�I�𒆂Ȃ�
    //   // y = THANKS_Y;    //�X�y�V�����T���N�X�̍��W���i�[
    //    BoxX = -210;
    //    break;
    //case eTitle_End://�I���I�𒆂Ȃ�
    //    //y = END_Y;      //�I���̍��W���i�[
    //    BoxX = -70;
    //}

    DrawFormatString(0, 100, 0xff0fff, "NowStage %d ", NowStage+1);
    int
        x = NowStage%6,
        y = NowStage/6;
    DrawBox(168 + x * 168, 26 + y * 156, 268 + x * 168, 126 + y * 156, 0x0000ff, TRUE);
   // DrawRotaGraph(168 +  NowStage * 168 + BoxX, y - 5, 1.0, 0, g_pic.Pin, TRUE, TRUE);
    //DrawBox(168 + j * 168, 156 + i * 156, 268 + j * 168, 256 + i * 156, 0x0000ff, FALSE);
}

int StageSelect(void) {
    //DrawRotaGraph(SCREEN_WIDHT / 2, SCREEN_HEIGHT / 2, 1.0, 0, g_pic.Title, TRUE, FALSE); //�^�C�g���摜�`��
    DrawBox(0,0,1280,768,0xffffff,TRUE);//�����w�i
    Stage_Update();
    Stage_Draw();
    return 0;
}