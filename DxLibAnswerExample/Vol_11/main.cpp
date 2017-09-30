﻿#include <vector>
#include <algorithm>
#include <memory>
#include "DxLib.h"
#include "MyGlobal.h"
#include "Enemy.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);//Log.txtを生成しないように設定
	ChangeWindowMode(TRUE);//非全画面にセット
	SetGraphMode(640, 480, 32);//画面サイズ指定
	if (DxLib_Init() == 1) { return -1; }//初期化に失敗時にエラーを吐かせて終了

	fontHandle = CreateFontToHandle("Segoe UI", 20, 5, DX_FONTTYPE_ANTIALIASING_4X4);//フォントを読み込み

	std::vector<std::shared_ptr<IEnemy>> vec;

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();//裏画面消す
		SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に

		GetMousePoint(&mouseX, &mouseY); //マウス座標更新
		keyUpdate();//(自作関数)キー更新

					// Z, X, Cキーが押されたらランダムな座標に敵を生成
		if (keyState[KEY_INPUT_Z] == 1) {
			vec.emplace_back(std::make_shared<EnemySinMove>(GetRand(640), GetRand(480)));
		}
		if (keyState[KEY_INPUT_X] == 1) {
			vec.emplace_back(std::make_shared<EnemyRotation>(GetRand(640), GetRand(480)));
		}
		if (keyState[KEY_INPUT_C] == 1) {
			vec.emplace_back(std::make_shared<EnemyStraight>(GetRand(640), GetRand(480)));
		}

		// 画面外の敵を削除
		auto rmvIter = std::remove_if(vec.begin(), vec.end(), [](const std::shared_ptr<IEnemy>& enemy) {
			return !checkHitPointRect(enemy->x, enemy->y, 0.0, 0.0, 640.0, 480.0);
		});

		vec.erase(rmvIter, vec.end());

		for (const auto& enemy : vec) {
			enemy->update();
		}

		for (const auto& enemy : vec) {
			enemy->draw();
		}

		DrawFormatStringToHandle(20, 40, 0xFFFFFF, fontHandle, "Z, X, Cで敵生成 敵の数:%3d", vec.size());

		ScreenFlip();//裏画面を表画面にコピー
	}

	DxLib_End();
	return 0;
}