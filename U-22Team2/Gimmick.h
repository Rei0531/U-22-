#pragma once
#include "MoveBox.h"



struct GimmickAll {			//ギミックに必要な変数
public:
	//スポイトボタンの変数
	int CC_SwitchColor = 9;//デフォルトで白色の9を格納

	//シャワー用の変数_______＿＿＿＿
	int shower_X;					//横座標
	int shower_Y = 670 - 256;		//縦座標（地面の縦座標-画像の縦の大きさ）
	int shower_C;					//色
	int shower_x;	//塗りつぶす判定の座標
	int shower_y;	//
	int shower_w;	//
	int shower_h;	//

			//シャワー2用の変数_______＿＿＿＿
	int shower_X2[2]{ 0,0 };					//横座標
	int shower_Y2[2]{ 0,0 };		//縦座標（地面の縦座標-画像の縦の大きさ）
	int shower_C2[2]{ 0,0 };					//色
	int shower_x2[2]{ 0,0 };	//塗りつぶす判定の座標
	int shower_y2[2]{ 0,0 };	//
	int shower_w2[2]{ 0,0 };	//
	int shower_h2[2]{ 0,0 };	//

			//スライドする床2の用の変数_______＿＿＿＿
	int q2_color[2]{ RED2,BLUE2 };
	int flg[2]{ 0,0 };
	int q2_move_x[2]{ 0,0 };
	int q2_x[2]{ 0,0 };		//スライドするブロックの座標
	int q2_w[2]{ 0,0 };		//スライドするブロックの座標
	int q2_y[2]{ 0,0 };		//スライドするブロックの座標
	int q2_h[2]{ 0,0 };		//スライドするブロックの座標


	//レバー用の変数_______＿＿＿＿
	int g_LeverX = 0;		//レバーのX座標
	int g_LeverY = 0;		//レバーのY座標
	int g_L_BoxX1 = 0;		//レバーで反応する箱
	int g_L_BoxY1 = 0;
	int g_L_BoxX2 = 0;
	int g_L_BoxY2 = 0;
	int g_L2_BoxX1 = 0;
	int g_L2_BoxY1 = 0;
	int g_L2_BoxX2 = 0;
	int g_L2_BoxY2 = 0;
	int g_L3_BoxX1 = 0;
	int g_L3_BoxY1 = 0;
	int g_L3_BoxX2 = 0;
	int g_L3_BoxY2 = 0;
	int g_L4_BoxX1 = 0;
	int g_L4_BoxY1 = 0;
	int g_L4_BoxX2 = 0;
	int g_L4_BoxY2 = 0;
	int g_L5_BoxX1 = 0;
	int g_L5_BoxY1 = 0;
	int g_L5_BoxX2 = 0;
	int g_L5_BoxY2 = 0;
	
	int OTSBox_Color = 0;
	int OTSBox_Color2 = 0;
	int OTSBox_Color3 = 0;
	int OTSBox_Color4 = 0;
	int OTSBox_Color5 = 0;

	int SwitchFlag = 0;		//レバーのON、OFF
	int SwitchWait = 0;		//レバーの待機時間
	int SwitchColor = 0;		//レバーの色

	//スライドする床の用の変数_______＿＿＿＿
	int Speed = 4;
	int move_x = 0;
	int move_cnt = 0;
	int move_max = 160;
	int SliObjx1 = 0;		//スライドするブロックの座標
	int SliObjx2 = 0;		//スライドするブロックの座標
	int SliObjy1 = 0;		//スライドするブロックの座標
	int SliObjy2 = 0;		//スライドするブロックの座標
	int GetObjx1 = 0;		//色取るためのブロックの座標
	int GetObjx2 = 0;		//色取るためのブロックの座標
	int GetObjy1 = 0;		//色取るためのブロックの座標
	int GetObjy2 = 0;		//色取るためのブロックの座標
	//一度限りのスイッチ用の変数_____________
	int g_OTSwitchFlag = 0;			//一度限りのスイッチのON/OFFフラグ

	int OTS_X1 = 0;					//一度限りのスイッチX/Y軸
	int OTS_Y1 = 0;
	int OTS_X2 = 0;
	int OTS_Y2 = 0;
	int OTS_WallX1 = 0;				//一度限りのスイッチで消える壁のX/Y軸
	int OTS_WallY1 = 0;
	int OTS_WallX2 = 0;
	int OTS_WallY2 = 0;
	int OTS_C_WallX1 = 0;			//一度限りのスイッチで表れる壁のX/Y軸
	int OTS_C_WallY1 = 0;
	int OTS_C_WallX2 = 0;
	int OTS_C_WallY2 = 0;
	//爆弾用の変数___________________________
	int g_Bombflg = 0;				//ボムの設置、所持、使用フラグ

	int B_EffectCount = 0;
	int B_WallX1 = 0;				//|	
	int B_WallY1 = 0;				//|--壊せる壁の座標
	int B_WallX2 = 0;				//|
	int B_WallY2 = 0;				//|
	int BombX1 = 0;			//|
	int BombX2 = 0;			//|--ボムの座標
	int BombY1 = 0;			//|
	int BombY2 = 0;			//|

	//変形オブジェクト用の変数＿＿＿＿
	int cheobj_flg;	 //変形するオブジェクトのフラグ
	int cheobj_x;
	int cheobj_y = 670 - 225;
	int cheobj_c;
	int cheobj_ani = 0;
	int cheobj_zeroflg = 0;
	int cheobj_sirusi;

	//回復アイテム用の変数_______
	int item_x;
	int item_y = 670 - 50;
	int item_flg;

	//ワープ用の変数_______
	int SetNum = 0;
};

int Shower(void);		//塗りつぶしシャワーの処理
int Shower2(int k);
int Lever(void);		//レバーの処理
int SlideBlock(int SlaColor);	//動く床の処理
int SlideBlock2(int k);	//動く床の処理
int CC_Switch(int Color, int x,int y);	//プレイヤーの押した色を反映するスイッチの処理//引数：押した時点のプレイヤーの色を渡す
int OneTimeSwitch(void); //一度限りのスイッチ
int Bomb(void);			//ボックス破壊の爆弾
int ChangeBlock(void); //変形するオブジェクト
int kaihuku(int x, int y);	//スポイト回復アイテム
int Warp(int x1, int y1,int x2,int y2);	//スポイト回復アイテム
int Warp2(int x_1, int y_1,int x_2,int y_2);	//スポイト回復アイテム
