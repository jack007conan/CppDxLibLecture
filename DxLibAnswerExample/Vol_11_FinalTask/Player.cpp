#include <Siv3D.hpp>
#include "GameManager.h"

const double Player::Radius = 16;
const size_t Player::FireRate = 5;
const double Player::MoveSpeed = 5.0;
const Vec2 Player::BulletFirstVelocity(0.0, -15.0);
const Vec2 Player::BulletFirstDelta(0.0, -20.0);
const size_t Player::EffectNum = 25;
const double Player::EffectRange = 64.0;
const Color Player::Color_(0, 0, 255);
const Vec2 Player::FirstPos(320.0, 400.0);

Player::Player() :
	pos(FirstPos),
	fireCool(0)
{
}

void Player::update() {
	move();
	shot();
	checkHit();
}

void Player::move() {
	// �㉺���E�L�[�ňړ�
	if (Input::KeyLeft.pressed) {
		pos.x -= MoveSpeed;
	}
	if (Input::KeyRight.pressed) {
		pos.x += MoveSpeed;
	}
	if (Input::KeyUp.pressed) {
		pos.y -= MoveSpeed;
	}
	if (Input::KeyDown.pressed) {
		pos.y += MoveSpeed;
	}
}

void Player::shot() {
	fireCool++;
	if (Input::KeyZ.pressed) {
		if (fireCool >= FireRate) {
			gameManager.playerBulletManager.add(std::make_shared<PlayerBullet>(pos + BulletFirstDelta, BulletFirstVelocity));
			fireCool = 0;
		}
	}
}

void Player::checkHit() {
	//�G�e���玩�@�ւ̓����蔻��
	for (const auto& bullet : gameManager.enemyBulletManager.enemyBullets) {
		if (Circle(pos, Radius).intersects(Circle(bullet->pos, bullet->Radius)) && bullet->isDead == false) {
			// �G�t�F�N�g����
			for (size_t j = 0; j < EffectNum; j++) {
				gameManager.effectManager.add(std::make_shared<WhiteCircle>(pos + Random(0.0, EffectRange) * RandomVec2()));
			}
			// �X�R�A���Z
			gameManager.scoreManager.addDamagedNum();
			bullet->isDead = true;
		}
	}

	//�G���g���玩�@�ւ̓����蔻��
	for (const auto& bullet : gameManager.enemyManager.enemies) {
		if (Circle(pos, Radius).intersects(Circle(bullet->pos, bullet->radius)) && bullet->isDead == false) {
			// �G�t�F�N�g����
			for (size_t j = 0; j < EffectNum; j++) {
				gameManager.effectManager.add(std::make_shared<WhiteCircle>(pos + Random(0.0, EffectRange) * RandomVec2()));
			}
			// �X�R�A���Z
			gameManager.scoreManager.addDamagedNum();
			bullet->isDead = true;
		}
	}
}

void Player::draw() const {
	Circle(pos, Radius).draw(Color_);
}