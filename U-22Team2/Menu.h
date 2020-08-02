#include "DxLib.h"
#include "Controller.h"
#include "constant.h"
#include "Player.h"

extern Controller g_Pad;
extern Player g_Player;
extern int GameState;

const static int GAME_Y = 380;    //�u�Q�[���v������y�ʒu
const static int RESET_Y = 440;    //�u���Z�b�g�v������y�ʒu
const static int END_Y = 500;    //�u�I���v������y�ʒu

typedef enum {
    eMenu_Select,       //�X�e�[�W�Z���N�g
    eMenu_Reset,    //���Z�b�g
    eMenu_End,      //�I��

    eMenu_Num,        //�{���ڂ̐�
} eMenu;

static int NowSelect = eMenu_End;    //���݂̑I�����(�����̓Q�[���I��)


bool Menu_Update();
void Menu_Draw();
