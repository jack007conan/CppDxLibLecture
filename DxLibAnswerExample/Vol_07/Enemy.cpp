#include "Enemy.h"

Enemy::Enemy(double _x, double _y):
	x(_x), y(_y),
	velocity(RandomVec2(5.0))
{
	// RandomVec2(double length)
	// 半径length(今回は5.0)の2次元ベクトルを返す
}

void Enemy::update() {
	x += vx; y+= vy;
}

void Enemy::draw() {
	DrawCircle(x, y, 30, GetColor(255, 0, 0));
}
