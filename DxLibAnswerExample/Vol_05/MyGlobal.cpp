#pragma once

#include "MyGlobal.h"
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int fontHandle; // �t�H���g�ǂݍ��ݗp�ϐ�
int mouseX = 0, mouseY = 0;// �}�E�X���W

						   // �L�[�擾�p�̔z��
char buf[256] = { 0 };
int keyState[256] = { 0 };

// �L�[���͏�Ԃ��X�V����֐�
void keyUpdate()
{
	GetHitKeyStateAll(buf);
	for (int i = 0; i < 256; i++)
	{
		if (buf[i] == 1) keyState[i]++;
		else keyState[i] = 0;
	}
}


// (startX, startY) - (endX, endY)�̒P�ʃx�N�g�������߁C���ʂ�resultX, resultY�ɓ����
void normalize(double startX, double startY, double endX, double endY, double *resultX, double *resultY) {
	double dx = endX - startX;
	double dy = endY - startY;
	double dist = sqrt(pow(dx, 2.0) + pow(dy, 2.0));

	// ������0�̏ꍇ(1, 0)�����ʂɓ���Ċ֐��𔲂���
	if (abs(dist) == 0.0) {
		*resultX = 1.0;
		*resultY = 0.0;
		return;
	}
	*resultX = dx / dist;
	*resultY = dy / dist;
}
