#pragma once
#include <vector>
#include <memory>
#include "DxLib.h"

// エフェクトの基底クラス
class IParticleEffect {
public:
	double x, y;
	int lifeTime;
	int elapsedFrame;
	bool isDead;

	IParticleEffect(double _x, double _y, int _lifeTime);
	virtual ~IParticleEffect() = default;
	virtual void update();
	virtual void draw() const = 0;

	// 死んでいるかどうかのフラグを更新
	void checkDead();
};

//白い円を一瞬描画するエフェクト
class WhiteCircle : public IParticleEffect{
public:
	static const int LifeTime;
	static const double Radius;
	static const unsigned int

	WhiteCircle(double _x, double _y);
	~WhiteCircle() = default;
	void draw() const override;
};

//エフェクトを管理するクラス
class EffectManager{
public:
	std::vector<std::shared_ptr<IParticleEffect>> effects;
	EffectManager();
	void add(const std::shared_ptr<IParticleEffect>& ptr);
	void update();
	void draw() const;
};

