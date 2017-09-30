#pragma once
#include "Enemy.h"
#include <vector>

class EnemyManager {
private:
	std::vector<Enemy> enemies;
	void checkDelete(); // ��ʊO�̓G�폜
public:
	void update();
	void draw();
	void add(const Enemy& enemy);
	size_t getEnemyNum();
};