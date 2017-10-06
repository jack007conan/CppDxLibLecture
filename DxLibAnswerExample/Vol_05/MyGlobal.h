#pragma once
#include "DxLib.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern int fontHandle;
extern int mouseX, mouseY;//�}�E�X���W

 //�L�[�擾�p�z��
extern char buf[256];
extern int keyState[256];

//�L�[���͏�Ԃ��X�V����֐�
void keyUpdate();

// (startX, startY) - (endX, endY)�̒P�ʃx�N�g�������߁C���ʂ�resultX, resultY�ɓ����
void normalize(double startX, double startY, double endX, double endY, double* resultX, double* resultY);