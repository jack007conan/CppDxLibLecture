#include "DxLib.h"
#include "Enemy.h"

Enemy::Enemy(double _x, double _y):
	x(_x), y(_y)
{
}

void Enemy::update() {
	//�������Ɉړ�
	y += 1.0;
}

//�G�l�~�[�i�~�j��`��
void Enemy::draw() {
	DrawCircle(x, y, 30, GetColor(255, 0, 0));
}
