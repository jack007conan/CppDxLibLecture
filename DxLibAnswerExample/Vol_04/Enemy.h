#pragma once
#include <Siv3D.hpp>
#include "Player.h"

class Enemy {
public:
	Vec2 pos;
	Vec2 velocity;
	Player *playerPtr;
	Enemy(const Vec2& _pos);
	void update();
	void draw();

	// �v���C���[�ւ̃|�C���^���擾����֐�
	void setPlayerPtr(Player *ptr_);
};