#pragma once
#include "DxLib.h"

extern int mouseX, mouseY;//�}�E�X���W

//�L�[�擾�p�z��
extern char buf[256];
extern int keyState[256];

extern const double PI2;

//�L�[���͏�Ԃ��X�V����֐�
void keyUpdate();

// �_(x, y)���l�p�`(����:(leftTopX, leftTopY), �E��(rightBottomX, rightBottomY))�̒��ɂ��邩�Ԃ�
bool checkHitPointRect(double x, double y, double leftTopX, double leftTopY, double rightBottomX, double rightBottomY);

// (startX, startY) - (endX, endY)�̒P�ʃx�N�g�������߁C���ʂ�resultX, resultY�ɓ����
void normalize(double startX, double startY, double endX, double endY, double *resultX, double *resultY);

// ����radius�Ń����_���ȕ����̃x�N�g����(x, y)�v�Z���C�|�C���^����Ēl������
void randomInCircle(double radius, double * x, double * y);

// 2�~���ڐG���Ă��邩�Ԃ��֐�
// 2�~�Ƃ́C�~A(���S:(ax, ay),���a:ar) �Ɖ~B(���S:(bx, by),���a:br)
bool checkHitCircles(double ax, double ay, double ar, double bx, double by, double br);
