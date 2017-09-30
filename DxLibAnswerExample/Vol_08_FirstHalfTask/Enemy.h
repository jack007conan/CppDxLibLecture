#pragma once
#include <vector>
#include "DxLib.h"


//�e�G�̊��N���X
class Enemy{
public:
	// �G�̎�ނ�\��enum
	enum Kind{
		Stalker,
		Stop,
		Rotation,
	};

	static const double Radius;
	static const int Score;
	static const size_t StopEnemyshotRate;
	static const double StopEnemyBulletSpeed;
	static const size_t RotationEnemyshotRate;
	static const size_t RotationEnemyshotNum;
	static const double RotationEnemyBulletSpeed;
	static const size_t EffectNum;
	static const double EffectGenerateRange;
	static const double StalkerEnemySpeed;
	static const double RotationEnemyOmega;
	static const unsigned int EnemyStalkerColor;
	static const unsigned int EnemyStopColor;
	static const unsigned int EnemyRotationColor;

	double x, y; 
	Kind kind; // �G�̎��
	double vx, vy;
	double hp;
	int elapsedFrame; // ��������Ă���̌o�߃t���[��
	bool isDead; // ����ł��邩�ǂ����̃t���O

	Enemy(double _x, double _y, Kind _kind);
	void update();
	void draw() const;
	void move();
	void shot();

	// ���@���������e�Ƃ̓����蔻������
	void checkHit();

	// ��ʊO�ɏo�Ă��Ȃ����AHP�̓[���ɂȂ��Ă��Ȃ������`�F�b�N���A����ł��邩�ǂ����̃t���O���X�V����B
	void checkDead();
};



//�G�S�̂��Ǘ�����N���X
class EnemyManager{
public:
	std::vector<Enemy> enemies;
	EnemyManager();
	void add(const Enemy& ins);
	void update();
	void draw() const;
};

