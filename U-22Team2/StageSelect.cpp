#include "DxLib.h"
#include "Controller.h"
#include "LoadPic.h"
#include "constant.h"
#include "Title.h"
#include "LoadSound.h"
#include "StageSelect.h"
#include "Map.h"
#include "Color.h"


extern Sound g_Snd;
static bool Sndflg = FALSE;//���Đ��t���O
extern image g_pic;
extern Controller g_Pad;
extern MapCoordinate g_MapC;

bool //��x�����h�~
DOWN = FALSE,//���L�[
UP = FALSE,//��L�[
LEFT = FALSE,//���L�[
RIGHT = FALSE,//�E�L�[
B = TRUE,//B�{�^��
A = FALSE,//A�{�^��
Y = FALSE;//Y�{�^��

void Stage_Decision(void);		//�X�e�[�W�Z���N�g���艉�o

int HtPflg = 1;
int stage_decision_flg = 0;	//�X�e�[�W�Z���N�g����t���O
int anicount = 0;			//���o�̎��Ԋ֌W�̕ϐ�

void Stage_Update() {

    //if (CheckSoundMem(g_Snd.MenuOpen) == 0 && Sndflg == FALSE) {
    //    PlaySoundMem(g_Snd.MenuOpen, DX_PLAYTYPE_BACK);
    //    Sndflg = TRUE;//���Đ��t���O��TRUE�ɂ��ē�x�Đ��h�~
    //}

    if (g_Pad.KEY_RIGHT == TRUE && RIGHT == FALSE && HtPflg > 0) HtPflg++;  //�E�B���h�E���J���Ă鎞�Ɂ��Ŏ��̃y�[�W��
    if (g_Pad.KEY_LEFT == TRUE && LEFT == FALSE && HtPflg > 1) HtPflg--;    //�E�B���h�E���J���Ă鎞�Ɂ��őO�̃y�[�W��

    if (HtPflg > 3) HtPflg = 0;     //�S�y�[�W�ڂŕ���

    if (HtPflg == 0) {//�E�B���h�E���J���ĂȂ����Ɉړ��\

        if (g_Pad.KEY_DOWN == TRUE && DOWN == FALSE) {//���L�[��������Ă�����
            DOWN = TRUE;
            NowStage = (NowStage + 5) % Stage_Num;//�I����Ԃ�5������
            PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
        }
        if (g_Pad.KEY_UP == TRUE && UP == FALSE) {//��L�[��������Ă�����
            UP = TRUE;
            NowStage = (NowStage + (Stage_Num - 5)) % Stage_Num;//�I����Ԃ�5�グ��
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
    }


    DOWN = (g_Pad.KEY_DOWN == TRUE) ? TRUE : FALSE;//���L�[��������Ă�����

    UP = (g_Pad.KEY_UP == TRUE) ? TRUE : FALSE;//��L�[��������Ă�����

    LEFT = (g_Pad.KEY_LEFT == TRUE) ? TRUE : FALSE;//���L�[��������Ă�����

    RIGHT = (g_Pad.KEY_RIGHT == TRUE) ? TRUE : FALSE;//�E�L�[��������Ă�����

    if (g_Pad.KEY_Y == TRUE && Y == FALSE && HtPflg == 0) {//�X�^�[�g�{�^���������ƃE�B���h�E���J��
        Y = TRUE;
        HtPflg = 1;
    }

    if (g_Pad.KEY_Y == TRUE && Y == FALSE && HtPflg > 0) {//�J���Ă��鎞�ɉ����ƕ���
        Y = TRUE;
        HtPflg = 0;
    }

    Y = (g_Pad.KEY_Y == TRUE) ? TRUE : FALSE;//���[�_�[�̃p�N��

    if (HtPflg == 0) {//�E�B���h�E�J���Ă��Ȃ��Ȃ�
        if (g_Pad.KEY_B == true && B == false) {//B�{�^���������ꂽ��
            B = TRUE;//�ēx�{�^����������
            Sndflg = FALSE;//���j���[�I�[�v���̃t���O��FALSE�ɂ��čēx�֐��ɓ�������������悤�ɂ���
            g_MapC.StageNumber = NowStage + 1;
            //GameState = GAME_MAIN;

            //�X�e�[�W�Z���N�g���艹
            PlaySoundMem(g_Snd.Menu_decision, DX_PLAYTYPE_BACK);
            stage_decision_flg = 1;

        }

        B = (g_Pad.KEY_B == TRUE) ? TRUE : FALSE;//B�{�^����������Ă�����/�ēxB�{�^����������悤��

        if (g_Pad.KEY_A == TRUE && A == FALSE) {//A�{�^���������ꂽ��
            GameState = GAME_TITLE;
            A = TRUE;//�ēx�{�^����������
            B = TRUE;//B�{�^��
        }
        A = (g_Pad.KEY_A == TRUE) ? TRUE : FALSE;//A�{�^����������Ă�����/�ēxA�{�^����������悤��

    }
}
void Stage_Draw() {
    static int MenuX = 634, MenuY = 200;
    static double anicnt = 0;//���F����]�J�E���g
    static int FreamCnt = 0;
    static int BoxX = 0;//�I���J�[�\���̃v���X����ʂ̈ʒu;
    int cnt = 0;
    int
        x = NowStage % 5,
        y = NowStage / 5;

    anicnt += 0.02;//���F�̌���]

    //static int r = 0, g = 0, b = 0;
    //if (FreamCnt % 60 == 0) {
    //    r = GetRand(255);
    //    g = GetRand(255);
    //    b = GetRand(255);
    //}

    DrawRotaGraph(268 + x * 168, 76 + y * 156, 1.5, anicnt, g_pic.Select_Back, TRUE, FALSE);//���F�̔w�i

    //�X�e�[�W�̂т傤���@
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            DrawBox(218 + j * 168, 26 + i * 156, 318 + j * 168, 126 + i * 156, 0xffffff, TRUE);//�����l�p
            DrawBox(218 + j * 168, 26 + i * 156, 318 + j * 168, 126 + i * 156, 0x000000 , FALSE);//�g��
            DrawRotaGraph(268 + j * 168, 76 + i * 156,0.5,0, g_pic.StageNum[cnt++ % Stage_Num],TRUE,FALSE);
        }
    }

    //�X�e�[�W�Z���N�g�̑傫�Ȃ�\��
    DrawExtendGraph(218 + x * 168, 26 + y * 156, 318 + x * 168, 126 + y * 156, g_pic.StageNum[NowStage], TRUE);
}

int StageSelect(void) {
    //DrawRotaGraph(SCREEN_WIDHT / 2, SCREEN_HEIGHT / 2, 1.0, 0, g_pic.Title, TRUE, FALSE); //�^�C�g���摜�`��
    DrawBox(0,0,1280,768,0xffffff,TRUE);//�����w�i
    Stage_Update();
    Stage_Draw();
    Stage_Decision();

    if (HtPflg > 0) DrawExtendGraph(235, 90, 1045, 678, g_pic.How_to_play_background, TRUE);   //�w�i�T�C�Y X=610 Y=776

    switch(HtPflg) {//�E�B���h�E�y�[�W
        case 1://�P�y�[�W��
            DrawRotaGraph(680, 384, 1.2, 0, g_pic.How_to_play[0], TRUE, FALSE);
            DrawRotaGraph(800, 550, 1.0, 0, g_pic.NextPage, TRUE);
            break;
        case 2://�Q�y�[�W��
            DrawRotaGraph(680, 384, 1.2, 0, g_pic.How_to_play[1], TRUE, FALSE);
            DrawRotaGraph(600, 555, 1.0, 0, g_pic.BackPage, TRUE);
            DrawRotaGraph(800, 550, 1.0, 0, g_pic.NextPage, TRUE);
            break;
        case 3://�R�y�[�W��
            DrawRotaGraph(680, 384, 1.2, 0, g_pic.How_to_play[2], TRUE, FALSE);
            DrawRotaGraph(600, 555, 1.0, 0, g_pic.BackPage, TRUE);
            DrawRotaGraph(800, 550, 1.0, 0, g_pic.EndPage, TRUE);
            break;
        /*case 4://�S�y�[�W��
            DrawRotaGraph(640, 384, 1.0, 0, g_pic.How_to_play[3], TRUE, FALSE);
            DrawRotaGraph(750, 600, 1.0, 0, g_pic.EndPage, TRUE);
            break;*/
    }

    DrawFormatString(1080, 50, GetColor(0,0,0),"START�{�^���ŃQ�[������");
    return 0;
}

void Stage_Decision(void) {

    if (stage_decision_flg == 1) {
        anicount += 20;
        SetDrawBlendMode(DX_BLENDMODE_ADD, anicount);

        if (anicount >= 255)stage_decision_flg = 3;

    }
    else if (stage_decision_flg == 3) {	//���o���I�������Q�[�����C����
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        stage_decision_flg = 0;
        anicount = 0;
        B = TRUE;
        GameState = GAME_MAIN;
    }

}