#include "Enemy.h"

Enemy::Enemy(double _x, double _y):
	x(_x), y(_y),
	vx(0.0), vy(1.0)
{
}

void Enemy::update() {
	x += vx; y+= vy;
}

//�G�l�~�[�i�~�j��`��
void Enemy::draw() {
	DrawCircle(x, y, 30, GetColor(255, 0, 0));
}
