#pragma once
#include "DxLib.h"
#include "Player.h"

class Enemy {
public:
	double x, y;
	double vx, vy;
	Player *playerPtr;
	Enemy(const Vec2& _pos);
	void update();
	void draw();

	// �v���C���[�ւ̃|�C���^���擾����֐�
	void setPlayerPtr(Player *ptr_);
};