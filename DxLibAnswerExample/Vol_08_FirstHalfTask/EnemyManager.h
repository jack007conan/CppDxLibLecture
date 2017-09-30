#pragma once
#include <vector>
#include "Enemy.h"

class EnemyManager {
private:
	void checkDelete(); // ��ʊO�̓G�폜
public:
	std::vector<Enemy> enemies;
	void update();
	void draw() const;
	void add(const Enemy& ins);
	size_t getEnemyNum();
};