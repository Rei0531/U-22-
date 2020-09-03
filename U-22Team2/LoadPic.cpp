#include "LoadPic.h"
#include "Map.h"
#include"Enemy.h"

int LoadPictue(void) {		//画像の読み込み
	if ((g_pic.Map = LoadGraph("image/Stage_Deffault.jpg")) == -1) return -1;	//ステージの基本背景
	if (LoadDivGraph("image/Player02.png", 20, 5, 4, 100, 200, g_pic.Player) == -1) return -1;//プレイヤーの分割画像

	//if ((g_pic.Title = LoadGraph("image/Title.png")) == -1) return -1;//タイトル画面
	if (LoadDivGraph("image/Title_name.png", 13, 13, 1, 128, 128 , g_pic.TitleName) == -1) return -1;//タイトル名の文字分割画像
	if ((g_pic.StageClear = LoadGraph("image/Stageclear.png")) == -1)return -1;//ステージクリア画面
	if (LoadDivGraph("image/Goal.Txt.PNG", 3, 1, 3, 1144, 341, g_pic.GoalTxt) == -1) return -1;//クリア後の文字分割画像
	if (LoadDivGraph("image/TitleChar.png", 3, 1, 3, 759, 94, g_pic.TitleChar) == -1) return -1;//タイトルの文字分割画像

	if (LoadDivGraph("image/Stage1Txt_ALL.png", 2, 2, 1, 512, 256, g_pic.Stage1Txt) == -1) return -1;//ステージ1のチュートリアル分割画像
	
	if ((g_pic.How_to_play_background = LoadGraph("image/How_to_play_background.png")) == -1) return -1;//遊び方説明の背景画像
	if (LoadDivGraph("image/How_to_play.png", 3, 3, 1, 512, 256, g_pic.How_to_play) == -1)return -1;//遊び方説明分割画像
	if ((g_pic.StartBotan = LoadGraph("image/STARTBotan.png")) == -1)return-1;//スタートボタン画像
	if ((g_pic.NextPage = LoadGraph("image/NextPage.png")) == -1) return -1;//次のページ画像
	if ((g_pic.BackPage = LoadGraph("image/BackPage.png")) == -1)return -1;	//前のページ画像
	if ((g_pic.LvUPtxt = LoadGraph("image/Lv_UP_txt.png")) == -1)return -1;	//複合ステージスタート画像
	if ((g_pic.EndPage = LoadGraph("image/EndPage.png")) == -1)return -1;//閉じる　画像

	if ((g_pic.Select_Back = LoadGraph("image/Select_Back.png")) == -1)return -1;//セレクト選択中のやつ

	if (LoadDivGraph("image/All_text.png", 12, 2, 6, 512, 128, g_pic.All_text) == -1) return -1;//全ステージのギミック説明
	if ((g_pic.Box_text = LoadGraph("image/Box_text.png")) == -1)return-1;						//ステージ２のギミック説明

	if ((g_pic.Stage = LoadGraph("image/Stage.png")) == -1)return -1;//現在のステージ

	if ((g_pic.Door = LoadGraph("image/door.png")) == -1)return -1;//ドア

	if ((g_pic.SpecialThanks = LoadGraph("image/Specialthanks.png")) == -1)return -1;//スペシャルサンクスの画像
	           
	if ((g_pic.Menu = LoadGraph("image/Menu.png")) == -1)return -1;//メニュー画面
	if (LoadDivGraph("image/MenuChar.PNG", 3, 1, 3, 600, 200, g_pic.MenuChar) == -1) return -1;//メニュー文字の分割画像
	if (LoadDivGraph("image/StageNumber.PNG", 30, 10, 3, 179, 173, g_pic.StageNum) == -1) return -1;//ステージ番号の分割画像
	if ((g_pic.MenuBotan = LoadGraph("image/Botan_setumei.png")) == -1)return-1;

	if (LoadDivGraph("image/nokori2.png", 6, 6, 1, 202, 256, g_pic.Nokori) == -1) return -1;//残り回数の分割画像
	if (LoadDivGraph("image/Nokori_Num.PNG", 10, 10, 1, 170, 200, g_pic.Nokori_Num) == -1) return -1;//残り回数の分割画像

	if ((g_pic.Hand = LoadGraph("image/yubisashi2.png")) == -1)return -1;//スポイト場所表示

	if ((g_pic.Door_Nobu = LoadGraph("image/doanobu.png")) == -1)return -1;//鍵ノブ
	if ((g_pic.Door_keyhole = LoadGraph("image/ita.png")) == -1)return -1;//鍵穴
	if (LoadDivGraph("image/Rotation02.png", 4, 4, 1, 100, 100, g_pic.Door_Rotation) == -1) return -1;//ドアのローテーション
	if ((g_pic.Door_Rot_Yajirusi = LoadGraph("image/RotationYajirusi.png")) == -1)return -1;//ドアのローテーション矢印

	if (LoadDivGraph("image/Box_All.png", 4, 4, 1, 150, 150, g_pic.Box) == -1) return -1;//すべての箱

	if ((g_pic.Pin = LoadGraph("image/Pin.png")) == -1)return -1;//ピン挿したところ

	if ((g_pic.Pin2 = LoadGraph("image/Pin2.png")) == -1)return -1;//残り回数の表示のピン

	if ((g_pic.Object_Wall = LoadGraph("image/Object_Wall.png")) == -1) return -1;			//ボムとスイッチ用の壁

	if ((g_pic.shower = LoadGraph("image/shower.png")) == -1)return-1;	//シャワーの画像
	if ((g_pic.shower_m = LoadGraph("image/shower_water.png")) == -1)return-1;	//シャワーの画像

	if ((g_pic.Reba = LoadGraph("image/lever(2).png")) == -1)return-1;//レバー

	if ((g_pic.C_Switch = LoadGraph("image/ChangeSwitch.png")) == -1)return-1;//色を反映するスイッチ

	if ((g_pic.Bomb = LoadGraph("image/Bomb.png")) == -1)return-1;					//爆弾の画像
	if ((g_pic.BombEffect = LoadGraph("image/bakudan_effect.png")) == -1) return -1;	//爆風の画像

	if ((g_pic.OneTimeSwitch_OFF = LoadGraph("image/Switch_OFF.png")) == -1)return -1;		//一度限りのスイッチONの画像
	if ((g_pic.OneTimeSwitch_ON = LoadGraph("image/Switch_ON.png")) == -1)return -1;		//OFFの画像

	if ((g_pic.Warp_Area = LoadGraph("image/Warp.png")) == -1)return -1;//ワープの画像
	if ((g_pic.Warp_Area2 = LoadGraph("image/Warp_2.png")) == -1)return -1;//ワープの画像
	if (LoadDivGraph("image/ChangeObject.png", 3, 3, 1, 225, 225, g_pic.ChengObject) == -1) return -1;//変形するオブジェクト
	if (LoadDivGraph("image/ChangeObject_sirusi.png", 4, 4, 1, 75, 75, g_pic.ChengObjectmark) == -1) return -1;//変形するオブジェクト　矢印

	if ((g_pic.item = LoadGraph("image/kaihuku.png")) == -1)return-1;//スポイト回復アイテム

	return 0;
}