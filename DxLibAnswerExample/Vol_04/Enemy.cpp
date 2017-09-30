#include "Enemy.h"
#include "MyGlobal.h"

Enemy::Enemy(double _x, double _y):
	x(_x), y(_y),
	vx(0.0), vy(0.0)
{
}

void Enemy::update() {
	// �v���C���[����G�̃x�N�g���������A���K���������̂�Speed���|���ď�Ɉ��̑��x�œ����悤�ɂ���
	// �v���C���[�����Ɉ�葬�x�ňړ�
	const double Speed = 1.5;
	normalize(x, y, playerPtr->x, playerPtr->y, &vx, &vy);
	vx *= Speed;
	vy *= Speed;
	x += vx;
	y+= vy;
}

void Enemy::draw() {
	DrawCircle(x, y, 30, GetColor(255, 0, 0));
}

// �v���C���[�ւ̃|�C���^���擾����֐�
void Enemy::setPlayerPtr(Player * ptr_){
	playerPtr = ptr_;
}
