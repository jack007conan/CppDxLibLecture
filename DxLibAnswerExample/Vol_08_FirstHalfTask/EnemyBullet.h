#pragma once
#include <vector>
#include <Siv3D.hpp>

class EnemyBullet{
public:
	static const double Radius;
	static const Color Color_;
	static const int LifeTime;

	Vec2 pos;
	Vec2 velocity;
	int eFrame; // ��������Ă���̌o�߃t���[��
	bool isDead; // ����ł��邩�ǂ����̃t���O

	EnemyBullet(const Vec2& _pos, const Vec2& _velocity);
	void update();
	void move();
	void checkDead();
	void draw() const;
};


class EnemyBulletManager{
public:
	std::vector<EnemyBullet> enemyBullets;
	EnemyBulletManager();

	// ���������e��ǉ�
	void add(const EnemyBullet& ins);
	void update();
	void draw() const;
};
