#pragma once
#include "DxLib.h"

class Enemy {
public:
	static const double Radius;

	// �G�̎�ނ�ݒ�
	enum Kind
	{
		Stalker,
		Rotation,
		Straight
	};
	Kind kind;
	double x, y;
	double vx, vy;
	int eFrame;
	Enemy(double _x, double _y, Kind _kind);
	void update();
	void draw();
};
