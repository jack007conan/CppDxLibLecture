#include "EnemyManager.h"
#include <algorithm>

void EnemyManager::update() {
	for (auto&& enemy : enemies) {
		enemy.update();
	}
	checkDelete();
}

void EnemyManager::draw() {
	for (auto&& enemy : enemies) {
		enemy.draw();
	}
}

void EnemyManager::add(const Enemy& enemy) {
	enemies.emplace_back(enemy);
}

size_t EnemyManager::getEnemyNum(){
	return enemies.size();
}

void EnemyManager::checkDelete() {
	auto it = enemies.begin();

	// ��ʊO�̓G���폜
	auto rmvIter = std::remove_if(enemies.begin(), enemies.end(), [](const Enemy& enemy) {

		// �G�̉~��̓����蔻��Ɖ�ʃT�C�Y�̎l�p�̓����蔻������A�������Ă��Ȃ��������ʊO�ɂ���Ɣ���
		return !Circle(enemy.pos, enemy.Radius).intersects(Rect(Window::Size()));
	});

	enemies.erase(rmvIter, enemies.end());
}