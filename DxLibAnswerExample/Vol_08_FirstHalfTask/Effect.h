#pragma once
#include <vector>
#include <Siv3D.hpp>


//�����~����u�`�悷��G�t�F�N�g
class WhiteCircle{
public:
	static const int LifeTime;
	static const double Radius;
	static const Color Color_;

	Vec2 pos;
	int eFrame; // ��������Ă���̌o�߃t���[��
	bool isDead; // ����ł��邩�ǂ����̃t���O

	WhiteCircle(const Vec2& _pos);
	void update();
	
	// ����ł��邩�ǂ����̃t���O���X�V
	void checkDead();
	void draw() const;
};


//�G�t�F�N�g���Ǘ�����N���X
class EffectManager{
public:
	std::vector<WhiteCircle> effects;
	EffectManager();
	void add(const WhiteCircle& ins);
	void update();
	void draw() const;
};

