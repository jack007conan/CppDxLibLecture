#pragma once
#include <vector>
#include <memory>
#include "DxLib.h"


//�e�G�̊��N���X
class IEnemy {
public:
	static const size_t EffectNum;
	static const double EffectGenerateRange;

	double x, y;
	double vx, vy;
	double radius;
	double hp;
	int score;
	unsigned int color;
	int elapsedFrame; // ��������Ă���̌o�߃t���[��
	bool isDead; // ����ł��邩�ǂ����̃t���O

	IEnemy(double _x, double _y, double _vx, double _vy, double _radius, double _hp, int _score, unsigned int _Color);

	virtual ~IEnemy() = default;

	void update();

	// ������
	virtual void move() = 0;

	// �V���b�g�̑ł���
	virtual void shot() = 0;

	// ���@���������e�Ƃ̓����蔻������
	void checkHit();

	// ��ʊO�ɏo�Ă��Ȃ����AHP�̓[���ɂȂ��Ă��Ȃ������`�F�b�N���A����ł��邩�ǂ����̃t���O���X�V����B
	void checkDead();

	void draw() const;
};


class EnemyStalker : public IEnemy {
public:
	static const double StalkerEnemySpeed;
	static const double Radius;
	static const double Hp;
	static const int Score;
	static const unsigned int Color;
	

	EnemyStalker(double _x, double _y);
	~EnemyStalker() = default;
	void move() override;
	void shot() override;
};

class EnemyStop : public IEnemy {
public:
	static const size_t EnemyshotRate;
	static const double BulletSpeed;
	static const double Radius;
	static const double Hp;
	static const int Score;
	static const unsigned int Color;

	EnemyStop(double _x, double _y);
	~EnemyStop() = default;
	void move() override;
	void shot() override;
};

class EnemyRotation : public IEnemy {
public:
	static const size_t EnemyshotRate;
	static const size_t EnemyshotNum;
	static const double EnemyBulletSpeed;
	static const double EnemyOmega;
	static const double Radius;
	static const double Hp;
	static const int Score;
	static const unsigned int Color;
	

	EnemyRotation(double _x, double _y);
	~EnemyRotation() = default;
	void move() override;
	void shot() override;
};

//�G�S�̂��Ǘ�����N���X
class EnemyManager {
public:
	std::vector<std::shared_ptr<IEnemy>> enemies;
	EnemyManager();
	void add(const std::shared_ptr<IEnemy>& ptr);
	void update();
	void draw() const;
};

