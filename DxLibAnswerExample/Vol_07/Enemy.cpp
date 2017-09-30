#include "Enemy.h"

Enemy::Enemy(const Vec2& _pos):
	x(_x), y(_y),
	velocity(RandomVec2(5.0))
{
	// RandomVec2(double length)
	// ���alength(�����5.0)��2�����x�N�g����Ԃ�
}

void Enemy::update() {
	x += vx; y+= vy;
}

void Enemy::draw() {
	DrawCircle(x, y, 30, GetColor(255, 0, 0));
}
