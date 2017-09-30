#include <iostream>
#include <algorithm>
#include "GameManager.h"

const double Enemy::Radius = 24.0;
const int Enemy::Score = 100;
const size_t Enemy::StopEnemyshotRate = 60;
const double Enemy::StopEnemyBulletSpeed = 1.0;
const size_t Enemy::RotationEnemyshotRate = 120;
const size_t Enemy::RotationEnemyshotNum = 4;
const double Enemy::RotationEnemyBulletSpeed = 8.0;
const size_t Enemy::EffectNum = 25;
const double Enemy::EffectGenerateRange = 64.0;
const double Enemy::StalkerEnemySpeed = 1.5;
const double Enemy::RotationEnemyOmega = 0.02;
const Color Enemy::EnemyStalkerColor(255, 0, 0);
const Color Enemy::EnemyStopColor(255, 128, 0);
const Color Enemy::EnemyRotationColor(255, 0, 128);


//�G�̊��N���X
Enemy::Enemy(const Vec2 & _pos, Kind _kind) :
	x(_x), y(_y),
	velocity(),
	kind(_kind),
	hp(5.0),
	eFrame(0),
	isDead(false)
{
}

void Enemy::update() {
	move();
	shot();
	checkHit();
	checkDead();
	eFrame++;
}

void Enemy::draw() const {
	if (kind == Stalker) {
		Circle(pos, Radius).draw(EnemyStalkerColor);
	}
	else if (kind == Stop) {
		Circle(pos, Radius).draw(EnemyStopColor);
	}
	else if (kind == Rotation) {
		Circle(pos, Radius).draw(EnemyRotationColor);
	}
}

void Enemy::move() {
	if (kind == Stalker) {
		velocity = StalkerEnemySpeed * (gameManager.player.pos - pos).normalized();
	}
	else if (kind == Stop) {
		velocity = Vec2(0.0, 0.0);
	}
	else if (kind == Rotation) {
		velocity = Vec2(1.0, 0.0).rotate(eFrame * RotationEnemyOmega);
	}
	x += vx; y+= vy;
}

void Enemy::shot() {
	if (kind == Stalker) {

	}
	else if (kind == Stop) {
		// �v���C���[�Ɍ����ăV���b�g������
		if (eFrame % StopEnemyshotRate == 0) {
			Vec2 firstVel = StopEnemyBulletSpeed * (gameManager.player.pos - pos).normalized();
			gameManager.eBulletManager.add(EnemyBullet(pos, firstVel));
		}
	}
	else if (kind == Rotation) {
		// 4�����ɃV���b�g������
		if (eFrame % RotationEnemyshotRate == 0) {
			for (size_t i = 0; i < RotationEnemyshotNum; i++) {
				Vec2 firstVel = Vec2(RotationEnemyBulletSpeed, 0).rotated(TwoPi * (double)i / (double)RotationEnemyshotNum);
				gameManager.eBulletManager.add(EnemyBullet(pos, firstVel));
			}
		}
	}
}


void Enemy::checkHit() {
	auto &vec = gameManager.pBulletManager.playerBullets;
	for (auto i = vec.begin(); i < vec.end(); i++) {
		// ���ꂼ��̃v���C���[�̒e�Ƃ̓����蔻������
		if (Circle(pos, Radius).intersects(Circle(i->pos, i->Radius)) && i->isDead == false) {
			hp -= i->Attack;
			gameManager.effectManager.add(WhiteCircle(i->pos));
			i->isDead = true;
		}
	}
}

void Enemy::checkDead() {
	// ��ʊO�ɍs���������m�F
	// �G�̉~��̓����蔻��ƁA��ʃT�C�Y���̎l�p�̓����蔻�肩���ʓ��ɂ��邩���肵�Ă���
	if (!Circle(pos, Radius).intersects(Rect(Window::Size()))){
		isDead = true;
	}
	//HP���[�������m�F
	if (hp < 1e-10) {
		// �[����������X�R�A�����Z
		gameManager.scoreManager.addScore(Score);
		// �G�t�F�N�g����
		for (size_t j = 0; j < EffectNum; j++) {
			gameManager.effectManager.add(WhiteCircle(pos + Random(0.0, EffectGenerateRange) * RandomVec2()));
		}
		isDead = true;
	}
}



EnemyManager::EnemyManager() {
}

void EnemyManager::add(const Enemy& ins) {
	enemies.emplace_back(ins);
}

void EnemyManager::update() {
	for (auto&& enemy : enemies) {
		enemy.update();
	}

	//�v�f�̏���
	auto iter = std::remove_if(enemies.begin(), enemies.end(), [](const Enemy& ins) {
		return ins.isDead;
	});
	enemies.erase(iter, enemies.end());
}

void EnemyManager::draw() const {
	for (auto&& enemy : enemies) {
		enemy.draw();
	}
}

