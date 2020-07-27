#include "Color.h"
#include "Map.h"
#include "Door.h"

extern MapCoordinate g_MapC;
extern DoorAll g_Door;

int Rotation_Box(int Shift) {

	int Rotation_num = g_Door.RotationNumber % g_Door.ColorNumber[g_MapC.StageNumber - 1];//通常のローテーション順番を格納

	Rotation_num += Shift;//ずらしたい値をプラスする

	//ローテーションが正常になるように調整する//例：Shiftが2、通常のローテション番号が1の時、1+2の3で0から数えて4回になるが
	//ステージによっては4回もローテションしない場合もある。ので%で決められたローテーション回数で割り正常にずらした値を求める
	Rotation_num = Rotation_num% g_Door.ColorNumber[g_MapC.StageNumber - 1];

	return g_Door.Rotation[g_MapC.StageNumber - 1][Rotation_num];//ずらした値を返す

}
