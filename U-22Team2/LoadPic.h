#pragma once
#include "DxLib.h"
struct image {
public:
	int Map;		//メインとなるマップ画像
	int Player[20];		//スポイトマンの画像
	int Object[10];		//オブジェクト画像
	int Title;			//タイトル画像
	int StageClear;		//ステージのクリア画像
	int TitleChar[3];	//タイトルの文字
	int TitleName[13];	//タイトル名
	int Menu;			//メニュー
	int MenuChar[3];	//メニューの文字
	int StageNum[30];	//ステージ番号の文字
	int Nokori[6];		//残り回数の文字
	int Nokori_Num[10];	//残り回数の数字
	int MenuBotan;		//メニューのボタン説明
	int Stage;			//現在のステージ表示
	int All_text[12];	//全ステージのギミック説明
	int Box_text;		//ステージ２のギミック説明
	int How_to_play_background;//遊び方説明の背景
	int How_to_play[4];	//遊び方説明
	int NextPage;		//次のページ
	int BackPage;		//前のページ
	int EndPage;		//閉じる
	int Door;			//ドアの画像
	int SpecialThanks;	//スペシャルサンクスの画像
	int StartBotan;		//スタートボタン

	int Hand;			//スポイト表示
	int Door_keyhole;	//鍵穴
	int Door_Nobu;		//ノブ
	int Door_Rotation[4];	//ドアのローテーション
	int Door_Rot_Yajirusi;	//ドアのローテーション矢印

	int Pin;//色取った場所のピン
	int Pin2;//残り回数表示用のぴん


	int Select_Back;	//セレクト画面の選択中のやつ


	int Box[3];//色々なボックス
	//int Box;//オブジェクトの木の箱
	//int Box_Move;//動く箱
	//int Box_Rot;//ローテーションするボックス

	int shower;//シャワーの画像
	int shower_m; //シャワーの水画像

	int Reba;//レバー

	int C_Switch;//色を反映するスイッチ

	int OneTimeSwitch_ON;//一度限りのスイッチONの画像
	int OneTimeSwitch_OFF;//一度限りのスイッチOFFの画像
	int Bomb;			//爆弾の画像
	int BombEffect;		//爆風の画像

	int Object_Wall;

	int Warp_Area;		//ワープ用
	int Warp_Area2;		//ワープ用

	int ChengObject[3];  //変形するオブジェクト
	int ChengObjectmark[4]; //

	int item;	//スポイト回復アイテム
};

int LoadPictue(void);	//関数の定義
