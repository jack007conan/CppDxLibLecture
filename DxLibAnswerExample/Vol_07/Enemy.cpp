# include "Enemy.h"

Enemy::Enemy(const Vec2& _pos):
	pos(_pos),
	velocity(RandomVec2(5.0))
{
	// RandomVec2(double length)
	// 半径length(今回は5.0)の2次元ベクトルを返す
}

void Enemy::update() {
	pos += velocity;
}

void Enemy::draw() {
	Circle(pos, 30.0).draw(Color(255, 0, 0));
}
