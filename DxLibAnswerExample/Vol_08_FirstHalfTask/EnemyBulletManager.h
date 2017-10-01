#pragma once
#include <vector>
#include "EnemyBullet.h"

class EnemyBulletManager {
public:
	std::vector<EnemyBullet> enemyBullets;
	EnemyBulletManager();

	// ���������e��ǉ�
	void add(const EnemyBullet& ins);
	void update();
	void draw() const;
};
