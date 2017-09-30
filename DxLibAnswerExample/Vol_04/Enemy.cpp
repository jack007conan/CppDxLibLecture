#include "Enemy.h"
#include "MyGlobal.h"

Enemy::Enemy(double _x, double _y):
	x(_x), y(_y),
	vx(0.0), vy(0.0)
{
}

void Enemy::update() {
	// �v���C���[����G�̃x�N�g���������A���K���������̂�Speed���|���ď�Ɉ��̑��x�œ����悤�ɂ���
	// �i�x�N�g�����悭�킩��Ȃ����ցF�v���C���[�����ւ̑��x���o���Ă邾���ł��j
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
