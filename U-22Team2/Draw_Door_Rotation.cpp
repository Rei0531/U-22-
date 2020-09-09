#include "DxLib.h"
#include "Door.h"
#include "Color.h"
#include "Map.h"
#include "Lock.h"
#include "Draw_Door_Rotation.h"


#define PI 3.141592654

extern DoorAll g_Door;
extern MapCoordinate g_MapC;
extern LockALL g_Lock;
extern Player g_Player;

float Move_Rotation = 0.0,
Rot_anicnt = 0.0,//回転のアニメ用の変数
Rot_Circle = 0.0;//ローテーション用の変数

//Rot_sum:ローテションす数
void DoorRotationBox(int Rot_sum) {

	Rot_anicnt -= 0.05;//矢印を回転させる

	double RotationAngle = (PI*2.0) / (double)Rot_sum;

	if (g_Door.Picupflg == TRUE) {//ドアのローテーションを進めるフラグがTRUEの時
		Rot_Circle = Move_Rotation;//ローテションする開始位置を取得
		Move_Rotation += (PI * 2.0) / (double)Rot_sum;
		g_Door.Picupflg = FALSE;
	}
	//ローテションする処理
	if (Move_Rotation > Rot_Circle) {
		Rot_Circle += 0.1;
	}

	//ステージクリアした時、タイトル画面に戻ったとき,ステージリセットされたとき
	if (g_Lock.clearflg == TRUE || g_Player.InitFlag == TRUE || g_Player.PLAYER_RESET == TRUE) {
		Move_Rotation = 0.0;//ローテーション画像の移動量をリセットする
		g_Player.PLAYER_RESET = FALSE;
		Rot_Circle = 0.0;
	}

	//ローテーションする数に合わせて描画する数を決める
	if (Rot_sum >= 1) {
		Change2(g_Door.Rotation[g_MapC.StageNumber - 1][0]);
		DrawRotaGraph(g_Door.x + 50, g_Door.y - 30, 1.0, RotationAngle * 4.0 - Rot_Circle, g_pic.Door_Rotation[Rot_sum - 1], TRUE, FALSE);
	}
	if (Rot_sum >= 2) {
		Change2(g_Door.Rotation[g_MapC.StageNumber - 1][1]);
		DrawRotaGraph(g_Door.x + 50, g_Door.y - 30, 1.0, RotationAngle * 5.0 - Rot_Circle, g_pic.Door_Rotation[Rot_sum - 1], TRUE, FALSE);
	}
	if (Rot_sum >= 3) {
		Change2(g_Door.Rotation[g_MapC.StageNumber - 1][2]);
		DrawRotaGraph(g_Door.x + 50, g_Door.y - 30, 1.0, RotationAngle * 6.0 - Rot_Circle, g_pic.Door_Rotation[Rot_sum - 1], TRUE, FALSE);
	}
	if (Rot_sum >= 4) {
		Change2(g_Door.Rotation[g_MapC.StageNumber - 1][3]);
		DrawRotaGraph(g_Door.x + 50, g_Door.y - 30, 1.0, RotationAngle * 7.0 - Rot_Circle, g_pic.Door_Rotation[Rot_sum - 1], TRUE, FALSE);
	}
	DrawRotaGraph(g_Door.x + 50, g_Door.y - 30, 0.7, Rot_anicnt, g_pic.Door_Rot_Yajirusi, TRUE, FALSE);
}
