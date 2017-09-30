#include <iostream>
#include <algorithm>
#include "GameManager.h"
#include "MyGlobal.h"

const double Enemy::Radius = 24.0;
const int Enemy::Score = 100;
const size_t Enemy::StopEnemyshotRate = 60;
const double Enemy::StopEnemyBulletSpeed = 1.0;
const size_t Enemy::RotationEnemyshotRate = 120;
const size_t Enemy::RotationEnemyshotNum = 4;
const double Enemy::RotationEnemyBulletSpeed = 8.0;
const size_t Enemy::EffectNum = 25;
const double Enemy::EffectGenerateRange = 64.0;
const double Enemy::StalkerEnemySpeed = 0.8;
const double Enemy::RotationEnemyOmega = 0.02;
const unsigned int Enemy::EnemyStalkerColor = 0xFF0000;
const unsigned int Enemy::EnemyStopColor = 0xFF8800;
const unsigned int Enemy::EnemyRotationColor = 0xFF0088;


//�G�̊��N���X
Enemy::Enemy(double _x, double _y, Kind _kind) :
	x(_x), y(_y),
	vx(0.0), vy(0.0),
	kind(_kind),
	hp(5.0),
	elapsedFrame(0),
	isDead(false)
{
}

void Enemy::update() {
	move();
	shot();
	checkHit();
	checkDead();
	elapsedFrame++;
}

void Enemy::draw() const {
	if (kind == Stalker) {
		DrawCircle(x, y, Radius, EnemyStalkerColor);
	}
	else if (kind == Stop) {
		DrawCircle(x, y, Radius, EnemyStopColor);
	}
	else if (kind == Rotation) {
		DrawCircle(x, y, Radius, EnemyRotationColor);
	}
}

void Enemy::move() {
	if (kind == Stalker) {
		Player& player = gameManager.player;
		normalize(x, y, player.x, player.y, &vx, &vy);
		vx *= StalkerEnemySpeed;
		vy *= StalkerEnemySpeed;
		x += vx;
		y += vy;
	}
	else if (kind == Stop) {
		vx = 0.0;
		vy = 0.0;
	}
	else if (kind == Rotation) {
		double angle = elapsedFrame * 0.02;
		vx = 1.0 * cos(angle);
		vy = 1.0 * sin(angle);
	}
	x += vx; y+= vy;
}

void Enemy::shot() {
	if (kind == Stalker) {

	}
	else if (kind == Stop) {
		// �v���C���[�Ɍ����ăV���b�g������
		if (elapsedFrame % StopEnemyshotRate == 0) {
			double bx, by;
			Player& p = gameManager.player;
			normalize(x, y, p.x, p.y, &bx, &by);
			bx *= StopEnemyBulletSpeed;
			by *= StopEnemyBulletSpeed;
			gameManager.eBulletManager.add(EnemyBullet(x, y, bx, by));
		}
	}
	else if (kind == Rotation) {
		// 4�����ɃV���b�g������
		if (elapsedFrame % RotationEnemyshotRate == 0) {
			for (size_t i = 0; i < RotationEnemyshotNum; i++) {
				Vec2 firstVel = Vec2(RotationEnemyBulletSpeed, 0).rotated( * (double)i / (double)RotationEnemyshotNum);
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

