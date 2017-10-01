#include <algorithm>
#include <memory>
#include "DxLib.h"
#include "GameManager.h"
#include "MyGlobal.h"
#include "IEnemy.h"
#include "WhiteCircleEffect.h"

const size_t IEnemy::EffectNum = 25;
const double IEnemy::EffectGenerateRange = 64.0;


//�G�̊��N���X
IEnemy::IEnemy(double _x, double _y, double _vx, double _vy, double _radius, double _hp, int _score, unsigned int _color) :
	x(_x), y(_y),
	vx(_vx), vy(_vy),
	radius(_radius),
	hp(_hp),
	score(_score),
	color(_color),
	elapsedFrame(0),
	isDead(false)
{
}

void IEnemy::update() {
	move();
	shot();
	checkHit();
	checkDead();
	elapsedFrame++;
}

void IEnemy::draw() const {
	DrawCircle(x, y, radius, color);
}

void IEnemy::checkHit() {
	for (const auto& bullet : gameManager.playerBulletManager.playerBullets) {
		// ���ꂼ��̃v���C���[�̒e�Ƃ̓����蔻������
		if (checkHitCircles(x, y, radius, bullet->x, bullet->y, bullet->radius) && bullet->isDead == false) {
			hp -= bullet->Attack;
			gameManager.effectManager.add(std::make_shared<WhiteCircleEffect>(bullet->x, bullet->y));
			bullet->isDead = true;
		}
	}
}

void IEnemy::checkDead() {
	// ��ʊO�ɍs���������m�F
	// �G�̉~��̓����蔻��ƁA��ʃT�C�Y���̎l�p�̓����蔻�肩���ʓ��ɂ��邩���肵�Ă���
	//if (!Circle(pos, radius).intersects(Rect(Window::Size()))) {
	if (!checkHitPointRect(x, y, 0.0, 0.0, 640.0, 480.0)) {
		isDead = true;
	}
	//HP���[�������m�F
	if (hp < 1e-10) {
		// �[����������X�R�A�����Z
		gameManager.scoreManager.addScore(score);
		// �G�t�F�N�g����
		for (size_t j = 0; j < EffectNum; j++) {
			double ix, iy;
			randomInCircle(EffectGenerateRange, &ix, &iy);
			gameManager.effectManager.add(std::make_shared<WhiteCircleEffect>(x + ix, y + iy));
		}
		isDead = true;
	}
}

