#include "Enemy.h"

Enemy::Enemy(const Vec2& _pos):
	x(_x), y(_y),
	velocity(0.0, 0.0)
{
}

void Enemy::update() {
	// �v���C���[����G�̃x�N�g���������A���K���������̂�Speed���|���ď�Ɉ��̑��x�œ����悤�ɂ���
	// �i�x�N�g�����悭�킩��Ȃ����ցF�v���C���[�����ւ̑��x���o���Ă邾���ł��j
	const double Speed = 1.5;
	velocity = playerPtr->pos - pos;
	velocity = Speed * velocity.normalized();
	x += vx; y+= vy;
}

void Enemy::draw() {
	DrawCircle(x, y, 30, GetColor(255, 0, 0));
}

// �v���C���[�ւ̃|�C���^���擾����֐�
void Enemy::setPlayerPtr(Player * ptr_){
	playerPtr = ptr_;
}
