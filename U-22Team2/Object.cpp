#include "Player.h"
#include "Color.h"
#include"Door.h"
#include"Interact.h"

extern Player g_Player;
extern DoorAll g_Door;
static int SaveColor = 99;		//�ꎞ�ϐ��Ɍ��݂̐F���i�[����

int GetPointColor(int Point_x, int Point_y) {	//�n���ꂽ���W�̐F���擾���ĕԂ�
	int color, r, g, b;
	int getcolor = 99;		//���擾����F�i�[�ϐ�

	color = GetPixel(Point_x, Point_y);		//�X�|�C�g����/�����̓X�|�C�g����ꏊ
	GetColor2(color, &r, &g, &b);							//�X�|�C�g�����F��R,G,B�l�ɒ���
	SaveColor;
	switch (r + g + b) {		//R,G,B�̍��v�ŋ�ʂ���/�X�|�C�g�����F��return�ŕԂ�
	case 255:
		getcolor = RED;
		break;
	case 420:
		getcolor = ORENGE;
		break;
	case 510:
		getcolor = YELLOW;
		break;
	case 128:
		getcolor = GREEN;
		break;
	case 509:
		getcolor = LIGHTBLUE;
		break;
	case 254:
		getcolor = BLUE;
		break;
	case 256:
		getcolor = PURPLE;
		break;
	case 0:
		getcolor = BLACK;
		break;
	case WHITE:
		getcolor = WHITE;
		break;
	default:
		break;
	}
	if (g_Player.PLAYER_PICKUP == TRUE) {//�X�|�C�g���ꂽ�Ƃ�
		g_Player.PLAYER_PICKUP = FALSE;			//TRUE�ɂȂ��Ă��̊֐��ɓ��邩���x�����̏����ɂ��邽�߂ɃX�|�C�g�t���O��FALSE�ɂ���
		if ((g_Player.Hit_Up == getcolor) | (SaveColor == getcolor)) {
			g_Door.Picupflg = FALSE;	//�X�|�C�g�����F���v���C���[�Ɠ��F�Ȃ�FALSE�ɂ���
		}
		if (g_Player.Hit_Up == getcolor) {
			Interact(FALSE);
			return SaveColor; //�v���C���[���d�Ȃ��Ă���u�̐F�Ǝ擾�����F��������������//���݂̐F��Ԃ�
		}
		if (SaveColor != getcolor) {
			Interact(TRUE);
		}
		else {
			Interact(FALSE);
		}
	}

	if (SaveColor != getcolor) {//���݂̐F�Ǝ擾�����F���Ⴄ�Ƃ�
		//�C���^���N�g����������`��
		return getcolor;		//�擾�����F��Ԃ�
	}
	else {
		//�C���^���N�g���Ă��Ȃ�������`��
		return SaveColor;//�����F�̏ꍇ�͌��̐F��Ԃ�
	}
}

int GetObjectColor(void) {
	//�v���C���[�̌����Ă���������+-50�����Ƃ��납�F���擾����
	g_Player.PickUpPixel = (g_Player.PLAYER_DIRECTION) ? g_Player.x - 50 : g_Player.x + 50;//�X�|�C�g����ꏊ
	SaveColor = g_Player.NowColor;		//�ꎞ�ϐ��Ɍ��݂̐F���i�[����

	return GetPointColor(g_Player.PickUpPixel, g_Player.y);
}