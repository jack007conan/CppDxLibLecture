#pragma once

// �e�̊��N���X
class IBullet {
public:
	double x, y;
	double vx, vy;
	double radius;
	double attack;
	unsigned int color;
	int lifeTime;
	int elapsedFrame; // ��������Ă���̌o�߃t���[��
	bool isDead; // ����ł��邩�ǂ����̃t���O

	IBullet(double _x, double _y, double _vx, double _vy, double _radius, double attack, unsigned int _color, int _lifeTime);
	void update();
	void move();
	void checkDead();
	void draw() const;
	virtual ~IBullet() = default;
};
