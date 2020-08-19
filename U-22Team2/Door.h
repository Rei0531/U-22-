#pragma once
#include "DxLib.h"
#include "Player.h"
#include "Controller.h"
#include "Map.h"
#include "Color.h"
#include "Object.h"

struct DoorAll {			//ドアに必要な変数
public:

	//ドアの座標
	int x = 1150;		//横座標
	int y = 400;		//縦座標
	int w = 1250;		//横幅座標
	int h = 668;		//縦幅座標
	int t = 500;		//ドアの移動

	int Rotation[25][5]{			//ステージごとのドアのローテーション

		{BLUE,LIGHTBLUE,RED},		//ステージ1のドアのローテーションの順番
		{BLUE,LIGHTBLUE,RED},		//ステージ2のドアのローテーションの順番
		{ORENGE,YELLOW,PURPLE},		//ステージ3のドアのローテーションの順番
		{BLUE},						//ステージ4のドアのローテーションの順番
		{BLUE},						//ステージ5のドアのローテーションの順番
		{RED,BLUE},					//ステージ6のドアのローテーションの順番
		{GREEN,RED},				//ステージ7のドアのローテーションの順番
		{RED,BLUE,YELLOW},			//ステージ8のドアのローテーションの順番
		{RED,BLUE,LIGHTBLUE},		//ステージ9のドアのローテーションの順番
		{RED},						//ステージ10のドアのローテーションの順番
		{RED},						//ステージ11のドアのローテーションの順番
		{LIGHTBLUE},				//ステージ12のドアのローテーションの順番
		{YELLOW},					//ステージ13のドアのローテーションの順番
		{YELLOW,BLUE},				//ステージ14のドアのローテーションの順番
		{RED,BLUE},					//ステージ15のドアのローテーションの順番
		{BLUE,GREEN,YELLOW},		//ステージ16のドアのローテーションの順番
		{BLUE},						//ステージ17のドアのローテーションの順番
		{BLUE},						//ステージ18のドアのローテーションの順番
		{GREEN,LIGHTBLUE,PURPLE},	//ステージ19のドアのローテーションの順番
		{RED,YELLOW,BLUE},			//ステージ20のドアのローテーションの順番
		{BLUE,YELLOW,RED},			//ステージ21のドアのローテーションの順番
		{YELLOW,PURPLE,BLUE,RED},	//ステージ22のドアのローテーションの順番
		{BLUE,RED,GREEN,YELLOW},						//ステージ23のドアのローテーションの順番
		{YELLOW,RED,BLUE,PURPLE},	//ステージ24のドアのローテーションの順番
		{BLUE}						//ステージ25のドアのローテーションの順番
	};		//ローテーションの配列

	int ColorNumber[25]{
		3,3,3,1,1,
		2,2,3,3,1,
		1,1,1,2,2,
		3,1,1,3,3,
		3,4,4,4,1
	};			//ステージごとのドアのローテーションの数

	int RotationNumber = 0;			//現在のローテーション位置


	bool
		Picupflg = FALSE;			//スポイトフラグ
};



int Door(void);					//ドアに関するすべての関数をまとめる関数(定義）
int DoorRotation(void);			//ドアの色のローテーションの処理(定義）
