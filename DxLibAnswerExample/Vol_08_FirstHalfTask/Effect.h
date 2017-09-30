#pragma once
#include <vector>
#include "DxLib.h"


//�����~����u�`�悷��G�t�F�N�g
class WhiteCircle{
public:
	static const int LifeTime;
	static const double Radius;
	static const unsigned int Color;

	double x, y;
	int elapsedFrame; // ��������Ă���̌o�߃t���[��
	bool isDead; // ����ł��邩�ǂ����̃t���O

	WhiteCircle(double _x, double _y);
	void update();
	
	// ����ł��邩�ǂ����̃t���O���X�V
	void checkDead();
	void draw() const;
};


//�G�t�F�N�g���Ǘ�����N���X
class EffectManager{
public:
	std::vector<WhiteCircle> effects;
	EffectManager();
	void add(const WhiteCircle& ins);
	void update();
	void draw() const;
};

