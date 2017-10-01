#pragma once
#include <vector>
#include <memory>
#include "IEnemy.h"

//�G�S�̂��Ǘ�����N���X
class EnemyManager {
public:
	std::vector<std::shared_ptr<IEnemy>> enemies;
	EnemyManager();
	void add(const std::shared_ptr<IEnemy>& ptr);
	void update();
	void draw() const;
};

