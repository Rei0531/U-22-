#pragma once
#include "DxLib.h"
#include "Controller.h"
#include "constant.h"
#include "Player.h"

extern Controller g_Pad;
extern Player g_Player;
extern int GameState;

const static int SELECT_Y = 430;    //�u�X�e�[�W�Z���N�g�v������y�ʒu
const static int THANKS_Y = 480;    //�u�X�y�V�����T���N�X�v������y�ʒu
const static int END_Y = 530;    //�u�I���v������y�ʒu

typedef enum {
    eTitle_Select,       //�X�e�[�W�Z���N�g
    eTitle_SpecialThanks,    //�X�y�V�����T���N�X
    eTitle_End,      //�I��

    eTitle_Num,        //�{���ڂ̐�
} eTitle;

static int NowSelect = eTitle_Select;    //���݂̑I�����(�����̓Q�[���I��)


void Title_Update();
void Title_Draw();

int GameTitle(void);