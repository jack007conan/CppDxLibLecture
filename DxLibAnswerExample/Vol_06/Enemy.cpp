# include "Enemy.h"

Enemy::Enemy(const Vec2& _pos):
	pos(_pos),
	velocity(RandomVec2(5.0))
{
	// RandomVec2(double length)
	// ���alength(�����5.0)��2�����x�N�g����Ԃ�
}

void Enemy::update() {
	pos += velocity;
}

void Enemy::draw() {
	Circle(pos, 30.0).draw(Color(255, 0, 0));
}
