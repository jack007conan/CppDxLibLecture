#include "GameManager.h"
#include "MyGlobal.h"
#include "EnemyStalker.h"
#include "EnemyStop.h"
#include "EnemyRotation.h"


GameManager::GameManager()
{
}

void GameManager::update() {
	// A, S, Dキーを押すと、自機を追う敵、その場で回転する敵、まっすぐ進む敵を生成
	if (keyState[KEY_INPUT_A] == 1) {
		gameManager.enemyManager.add(std::make_shared<EnemyStalker>(GetRand(SCREEN_WIDTH), GetRand(SCREEN_HEIGHT)));
	}
	if (keyState[KEY_INPUT_S] == 1) {
		gameManager.enemyManager.add(std::make_shared<EnemyStop>(GetRand(SCREEN_WIDTH), GetRand(SCREEN_HEIGHT)));
	}
	if (keyState[KEY_INPUT_D] == 1) {
		gameManager.enemyManager.add(std::make_shared<EnemyRotation>(GetRand(SCREEN_WIDTH), GetRand(SCREEN_HEIGHT)));
	}

	player.update();
	enemyManager.update();
	playerBulletManager.update();
	enemyBulletManager.update();
	effectManager.update();
	scoreManager.update();
}

void GameManager::draw() const {
	player.draw();
	enemyManager.draw();
	playerBulletManager.draw();
	enemyBulletManager.draw();
	effectManager.draw();
	scoreManager.draw();

	DrawFormatStringToHandle(10, 30 * 1, GetColor(255, 255, 255), fontHandle, "A, S, Dで敵を生成");
	DrawFormatStringToHandle(10, 30 * 2, GetColor(255, 255, 255), fontHandle, "Zでショット");
}

void GameManager::load() {
	fontHandle = CreateFontToHandle("Segoe UI", 20, 5, DX_FONTTYPE_ANTIALIASING_4X4);//フォントを読み込み
}

GameManager gameManager;