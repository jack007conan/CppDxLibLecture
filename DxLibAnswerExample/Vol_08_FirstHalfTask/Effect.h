#pragma once


//�����~����u�`�悷��G�t�F�N�g
class WhiteCircleEffect{
public:
	static const int LifeTime;
	static const double Radius;
	static const unsigned int Color;

	double x, y;
	int elapsedFrame; // ��������Ă���̌o�߃t���[��
	bool isDead; // ����ł��邩�ǂ����̃t���O

	WhiteCircleEffect(double _x, double _y);
	void update();
	
	// ����ł��邩�ǂ����̃t���O���X�V
	void checkDead();
	void draw() const;
};

