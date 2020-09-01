#include "Stage_All.h"
#include "Map.h"
#include "Player.h"
#include "LoadPic.h"
#include "Controller.h"
#include"Lock.h"
#include "Goal.h"
#include "LoadSound.h"
#include "Color.h"

extern Player g_Player;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern Controller g_Pad;
extern LockALL g_Lock;
extern Sound g_Snd;
extern image g_pic;


static bool LEFT = FALSE,//���L�[
RIGHT = FALSE,//�E�L�[
B = TRUE;//B�{�^��

static bool Sndflg = FALSE;//���Đ��t���O


int Goal(void) {

	Goal_Update();
	Goal_Draw();

	ControllerVlue();

    //if (g_MapC.StageNumber >= 25) {
    //    if (g_Pad.KEY_B == TRUE && B == FALSE) {
    //        g_MapC.StageNumber = 1;
    //        GameState = GAME_TITLE;
    //        g_Lock.clearflg = FALSE;
    //    }
    //}
    //else {
    //    if (g_Pad.KEY_B == TRUE && B == FALSE) {
    //        g_MapC.StageNumber += 1;
    //        GameState = GAME_MAIN;
    //        g_Lock.clearflg = FALSE;
    //    }
    //}

    //B = (g_Pad.KEY_B == TRUE) ? TRUE : FALSE;//B�{�^����������Ă�����/�ēxB�{�^����������悤��


	return 0;

}


//�X�V
void Goal_Update() {

    if (CheckSoundMem(g_Snd.MenuOpen) == 0 && Sndflg == FALSE) {
        PlaySoundMem(g_Snd.MenuOpen, DX_PLAYTYPE_BACK);
        Sndflg = TRUE;//���Đ��t���O��TRUE�ɂ��ē�x�Đ��h�~
    }

    if (g_Pad.KEY_LEFT == TRUE && LEFT == FALSE) {//���L�[��������Ă�����
        LEFT = TRUE;
        NowSelect = (NowSelect + 1) % eGoal_Num;//�I����Ԃ��������
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
    }
    if (g_Pad.KEY_RIGHT == TRUE && RIGHT == FALSE) {//�E�L�[��������Ă�����
        RIGHT = TRUE;
        NowSelect = (NowSelect + (eGoal_Num - 1)) % eGoal_Num;//�I����Ԃ���グ��
        PlaySoundMem(g_Snd.MenuMove, DX_PLAYTYPE_BACK);
    }

    LEFT = (g_Pad.KEY_LEFT == TRUE) ? TRUE : FALSE;//���L�[��������Ă�����

    RIGHT = (g_Pad.KEY_RIGHT == TRUE) ? TRUE : FALSE;//�E�L�[��������Ă�����

    if (g_Pad.KEY_B == TRUE && B == FALSE) {//B�{�^���������ꂽ��
        Sndflg = FALSE;//���j���[�I�[�v���̃t���O��FALSE�ɂ��čēx�֐��ɓ�������������悤�ɂ���
        switch (NowSelect) {//���ݑI�𒆂̏�Ԃɂ���ď����𕪊�
        case eGoal_Next://���X�e�[�W�I�𒆂Ȃ�
            //�{���͂����ɃZ���N�g��ʈȍ~����
            if (g_MapC.StageNumber >= 25) {
                if (g_Pad.KEY_B == TRUE && B == FALSE) {
                    g_MapC.StageNumber = 1;
                    GameState = GAME_TITLE;
                    g_Lock.clearflg = FALSE;
                }
            }
            else {
                if (g_Pad.KEY_B == TRUE && B == FALSE) {
                    g_MapC.StageNumber += 1;
                    GameState = GAME_MAIN;
                    g_Lock.clearflg = FALSE;
                    PlaySoundMem(g_Snd.Menu_decision, DX_PLAYTYPE_BACK);
                }
            }
            break;
        case eGoal_Back://�O�X�e�[�W�I�𒆂Ȃ�
            if (g_MapC.StageNumber <= 1) {
                if (g_Pad.KEY_B == TRUE && B == FALSE) {
                    GameState = GAME_TITLE;
                    g_Lock.clearflg = FALSE;
                }
            }
            else {
                if (g_Pad.KEY_B == TRUE && B == FALSE) {
                    g_MapC.StageNumber -= 1;
                    GameState = GAME_MAIN;
                    g_Lock.clearflg = FALSE;
                    PlaySoundMem(g_Snd.Menu_decision, DX_PLAYTYPE_BACK);
                }
            }
            break;
        case eGoal_Select://�X�e�[�W�Z���N�g�I�𒆂�������
            GameState = GAME_TITLE;
            g_Lock.clearflg = FALSE;
            break;

        }
    }

    B = (g_Pad.KEY_B == TRUE) ? TRUE : FALSE;//B�{�^����������Ă�����/�ēxB�{�^����������悤��
}

//�`��
void Goal_Draw() {

    static int MenuY = 600;

    ColorReset();
    //�N���A��ʂ̕`��
    DrawRotaGraph(SCREEN_WIDHT / 2, SCREEN_HEIGHT / 2, 1.0, 0, g_pic.StageClear, TRUE, FALSE); //�N���A�摜�`��
    DrawRotaGraph(NEXT_X, MenuY+7, 0.2, 0, g_pic.GoalTxt[0], TRUE, FALSE);
    DrawRotaGraph(BACK_X, MenuY, 0.2, 0, g_pic.GoalTxt[1], TRUE, FALSE);
    DrawRotaGraph(SELECT_X, MenuY, 0.2, 0, g_pic.GoalTxt[2], TRUE, FALSE);

    int x = 0;
    switch (NowSelect) {//���݂̑I����Ԃɏ]���ď����𕪊�
    case eGoal_Next://�Z���N�g�I�𒆂Ȃ�
        x = NEXT_X;    //�Z���N�g�̍��W���i�[
        break;
    case eGoal_Back://���Z�b�g�I�𒆂Ȃ�
        x = BACK_X;    //���Z�b�g�̍��W���i�[
        break;
    case eGoal_Select://�I���I�𒆂Ȃ�
        x = SELECT_X;      //�I���̍��W���i�[
    }
    DrawRotaGraph(x-128, MenuY, 1.0, 0, g_pic.Pin, TRUE, TRUE);
}