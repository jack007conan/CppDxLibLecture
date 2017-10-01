#pragma once
#include "IEffect.h"


//�����~����u�`�悷��G�t�F�N�g
class WhiteCircleEffect : public IEffect {
public:
	static const int LifeTime;
	static const double Radius;
	static const unsigned int Color;

	WhiteCircleEffect(double _x, double _y);
	~WhiteCircleEffect() = default;
	void draw() const override;
};