#pragma once
#include <vector>
#include <memory>
#include "DxLib.h"


// �e�̊��N���X
class IBullet {
public:
	double x, y;
	double vx, vy;
	double radius;
	double attack;
	Color color;
	int lifeTime;
	int eFrame; // ��������Ă���̌o�߃t���[��
	bool isDead; // ����ł��邩�ǂ����̃t���O

	IBullet(const Vec2& _pos, const Vec2& _velocity, double _radius, double attack, const Color& _color, int _lifeTime);
	void update();
	void move();
	void checkDead();
	void draw() const;
	virtual ~IBullet() = default;
};

// �v���C���[�̒e
class PlayerBullet : public IBullet{
public:
	static const double Radius;
	static const double Attack;
	static const Color Color_;
	static const int LifeTime;
	
	PlayerBullet(const Vec2& _pos, const Vec2& _velocity);
	~PlayerBullet() = default;
};

// �G�̒e
class EnemyBullet : public IBullet{
public:
	static const double Radius;
	static const double Attack;
	static const Color Color_;
	static const int LifeTime;

	EnemyBullet(const Vec2& _pos, const Vec2& _velocity);
	~EnemyBullet() = default;
};


// �G�̒e���Ǘ�����N���X
class EnemyBulletManager {
public:
	std::vector<std::shared_ptr<EnemyBullet>> enemyBullets;
	EnemyBulletManager();
	void add(const std::shared_ptr<EnemyBullet>& ptr);
	void update();
	void draw() const;
};

// �v���C���[�̒e���Ǘ�����N���X
class PlayerBulletManager{
public:
	std::vector<std::shared_ptr<PlayerBullet>> playerBullets;
	PlayerBulletManager();
	void add(const std::shared_ptr<PlayerBullet>& ptr);
	void update();
	void draw() const;
};
