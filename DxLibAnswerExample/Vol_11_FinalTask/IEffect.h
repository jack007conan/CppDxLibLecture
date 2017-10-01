#pragma once

// �G�t�F�N�g�̊��N���X
class IEffect {
public:
	double x, y;
	int lifeTime;
	int elapsedFrame;
	bool isDead;

	IEffect(double _x, double _y, int _lifeTime);
	virtual ~IEffect() = default;
	virtual void update();
	virtual void draw() const = 0;

	// ����ł��邩�ǂ����̃t���O���X�V
	void checkDead();
};
