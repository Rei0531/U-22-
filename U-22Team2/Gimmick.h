#pragma once



struct GimmickAll {			//ギミックに必要な変数
public:

	//シャワー用の変数_______＿＿＿＿
	int shower_X;					//横座標
	int shower_Y = 670 - 256;		//縦座標（地面の縦座標-画像の縦の大きさ）
	int shower_C;					//色
	int shower_x;	//塗りつぶす判定の座標
	int shower_y;	//
	int shower_w;	//
	int shower_h;	//

	//レバー用の変数_______＿＿＿＿
	int SwitchFlag = 0;		//レバーのON、OFF
	int SwitchWait = 0;		//レバーの待機時間
	int SwitchColor;		//レバーの色

	//スライドする床の用の変数_______＿＿＿＿
	int Speed = 2;
	int move_x = 0;
	int move_cnt = 0;
	int move_max = 160;


};

int Shower(void);		//塗りつぶしシャワーの処理
int Lever(void);		//レバーの処理
int SlideBlock(void);	//動く床の処理