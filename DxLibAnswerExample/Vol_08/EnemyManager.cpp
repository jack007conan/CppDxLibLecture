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

	// 画面外の敵を削除
	auto rmvIter = std::remove_if(enemies.begin(), enemies.end(), [](const Enemy& enemy) {

		// 敵の円状の当たり判定と画面サイズの四角の当たり判定を取り、当たっていなかったら画面外にいると判定
		return !Circle(enemy.pos, enemy.Radius).intersects(Rect(Window::Size()));
	});

	enemies.erase(rmvIter, enemies.end());
}