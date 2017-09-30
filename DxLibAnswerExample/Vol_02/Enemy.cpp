# include <Siv3D.hpp>
# include "Enemy.h"

Enemy::Enemy(Vec2 _pos):
	pos(_pos)
{
}

void Enemy::update() {
	//�������Ɉړ�
	pos.y += 1.0;
}

//�G�l�~�[�i�~�j��`��
void Enemy::draw() {
	Circle(pos, 30.0).draw(Color(255, 0, 0));
}
