#include "GameManager.h"

GameManager::GameManager()
{
}

void GameManager::update() {
	// A, S, D�L�[�������ƁA���@��ǂ��G�A���̏�ŉ�]����G�A�܂������i�ޓG�𐶐�
	if (Input::KeyA.clicked) {
		gameManager.enemyManager.add(std::make_shared<EnemyStalker>(GetRand(640), GetRand(480)));
	}
	if (Input::KeyS.clicked) {
		gameManager.enemyManager.add(std::make_shared<EnemyStop>(GetRand(640), GetRand(480)));
	}
	if (Input::KeyD.clicked) {
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

	DrawFormatStringToHandle(10, 30 * 3, GetColor(255, 255, 255), fontHandle, "A, S, D�œG�𐶐�");
	DrawFormatStringToHandle(10, 30 * 4, GetColor(255, 255, 255), fontHandle, "Z�ŃV���b�g");
}

void GameManager::load() {
	fontHandle = CreateFontToHandle("Segoe UI", 20, 5, DX_FONTTYPE_ANTIALIASING_4X4);//�t�H���g��ǂݍ���
}

GameManager gameManager;