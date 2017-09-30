#include "GameManager.h"

GameManager::GameManager()
{
}

void GameManager::update() {
	// A, S, D�L�[�������ƁA���@��ǂ��G�A���̏�ŉ�]����G�A�܂������i�ޓG�𐶐�
	if (Input::KeyA.clicked) {
		gameManager.enemyManager.add(Enemy(RandomVec2(Window::Width(), Window::Height() / 2.0), Enemy::Stalker));
	}
	if (Input::KeyS.clicked) {
		gameManager.enemyManager.add(Enemy(RandomVec2(Window::Width(), Window::Height() / 2.0), Enemy::Stop));
	}
	if (Input::KeyD.clicked) {
		gameManager.enemyManager.add(Enemy(RandomVec2(Window::Width(), Window::Height() / 2.0), Enemy::Rotation));
	}

	player.update();
	enemyManager.update();
	pBulletManager.update();
	eBulletManager.update();
	effectManager.update();
	scoreManager.update();
}

void GameManager::draw() const {
	player.draw();
	enemyManager.draw();
	pBulletManager.draw();
	eBulletManager.draw();
	effectManager.draw();
	scoreManager.draw();

	font(L"ASD�œG�𐶐�").draw(Vec2(10.0, 30.0 * 3.0));
	font(L"Z�ŃV���b�g").draw(Vec2(10.0, 30.0 * 4.0));
}

void GameManager::load() {
	font = Font(15);
}

GameManager gameManager;