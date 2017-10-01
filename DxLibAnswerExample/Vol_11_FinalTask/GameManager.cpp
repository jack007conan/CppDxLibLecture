#include "GameManager.h"
#include "MyGlobal.h"
#include "EnemyStalker.h"
#include "EnemyStop.h"
#include "EnemyRotation.h"


GameManager::GameManager()
{
}

void GameManager::update() {
	// A, S, D�L�[�������ƁA���@��ǂ��G�A���̏�ŉ�]����G�A�܂������i�ޓG�𐶐�
	if (keyState[KEY_INPUT_A] == 1) {
		gameManager.enemyManager.add(std::make_shared<EnemyStalker>(GetRand(640), GetRand(480)));
	}
	if (keyState[KEY_INPUT_S] == 1) {
		gameManager.enemyManager.add(std::make_shared<EnemyStop>(GetRand(640), GetRand(480)));
	}
	if (keyState[KEY_INPUT_D] == 1) {
		gameManager.enemyManager.add(std::make_shared<EnemyRotation>(GetRand(640), GetRand(480)));
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

	DrawFormatStringToHandle(10, 30 * 1, GetColor(255, 255, 255), fontHandle, "A, S, D�œG�𐶐�");
	DrawFormatStringToHandle(10, 30 * 2, GetColor(255, 255, 255), fontHandle, "Z�ŃV���b�g");
}

void GameManager::load() {
	fontHandle = CreateFontToHandle("Segoe UI", 20, 5, DX_FONTTYPE_ANTIALIASING_4X4);//�t�H���g��ǂݍ���
}

GameManager gameManager;