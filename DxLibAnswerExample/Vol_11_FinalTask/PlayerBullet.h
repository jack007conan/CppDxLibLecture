#pragma once
#include "IBullet.h"

// �v���C���[�̒e
class PlayerBullet : public IBullet {
public:
	static const double Radius;
	static const double Attack;
	static const unsigned int Color;
	static const int LifeTime;

	PlayerBullet(double _x, double _y, double _vx, double _vy);
	~PlayerBullet() = default;
};