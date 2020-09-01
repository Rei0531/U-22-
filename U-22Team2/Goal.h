#include "DxLib.h"
#include "Controller.h"
#include "constant.h"
#include "Player.h"

extern Controller g_Pad;
extern Player g_Player;
extern int GameState;

const static int BACK_X = 320;    //�u�O�X�e�[�W�v������x�ʒu
const static int SELECT_X = BACK_X * 2;    //�u�X�e�[�W�Z���N�g�v������x�ʒu
const static int NEXT_X = BACK_X * 3;    //�u���X�e�[�W�v������x�ʒu

typedef enum {
    eGoal_Next,    //���X�e�[�W
    eGoal_Select,      //�X�e�[�W�Z���N�g
    eGoal_Back,    //�O�X�e�[�W

    eGoal_Num,        //�{���ڂ̐�
} eGoal;

static int NowSelect = eGoal_Next;    //���݂̑I�����(�����̓Q�[���I��)


void Goal_Update();
void Goal_Draw();

