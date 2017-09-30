#pragma once
#include "DxLib.h"

class IEnemy {
public:
	static const double Radius;
	double x, y;
	double vx, vy;
	IEnemy(const Vec2& _pos);
	virtual void update() = 0;
	virtual void draw() const = 0;
	virtual ~IEnemy() = default;
};

// Sin�O����`���ē����G
class EnemySinMove : public IEnemy {
public:
	static const double SinOmega;
	static const double SpeedX;
	static const double SpeedY;
	static const Color Color_;
	
	int eFrame;

	EnemySinMove(const Vec2& _pos);
	void update() override;
	void draw() const override;
	~EnemySinMove() = default;
};

// �~�^��������G
class EnemyRotation : public IEnemy {
public:
	static const double Speed;
	static const double RotationOmega;
	static const Color Color_;

	int eFrame;

	EnemyRotation(const Vec2& _pos);
	void update() override;
	void draw() const override;
	~EnemyRotation() = default;
};

// �����_���ȕ����ɁA�����Ɉړ�����G
class EnemyStraight : public IEnemy {
public:
	static const double Speed;
	static const Color Color_;

	EnemyStraight(const Vec2& _pos);
	void update() override;
	void draw() const override;
	~EnemyStraight() = default;
};
