#pragma once
#include <vector>
#include "DxLib.h"

class PlayerBullet{
public:
	static const double Radius;
	static const double Attack;
	static const Color Color_;
	static const int LifeTime;

	double x, y;
	double vx, vy;
	int eFrame; // ��������Ă���̌o�߃t���[��
	bool isDead; // ����ł��邩�ǂ����̃t���O

	PlayerBullet(double _x, double _y, const Vec2& _velocity);
	void update();
	void move();
	void checkDead();
	void draw() const;
};


class PlayerBulletManager{
public:
	std::vector<PlayerBullet> playerBullets;
	PlayerBulletManager();
	void add(const PlayerBullet& ins);
	void update();
	void draw() const;
};
