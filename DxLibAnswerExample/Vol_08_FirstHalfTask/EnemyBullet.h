#pragma once

class EnemyBullet{
public:
	static const double Radius;
	static const unsigned int Color;
	static const int LifeTime;

	double x, y;
	double vx, vy;
	int elapsedFrame; // ��������Ă���̌o�߃t���[��
	bool isDead; // ����ł��邩�ǂ����̃t���O

	EnemyBullet(double _x, double _y, double _vx, double _vy);
	void update();
	void move();
	void checkDead();
	void draw() const;
};

