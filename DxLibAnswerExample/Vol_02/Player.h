#pragma once
#include "DxLib.h"

class Player {
public:
	double x, y;
	double speed;

	Player();
	void update();

	//���@�i�~�j��`��
	void draw();
};