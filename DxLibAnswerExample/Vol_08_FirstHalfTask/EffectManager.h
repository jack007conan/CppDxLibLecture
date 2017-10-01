#pragma once
#include <vector>
#include "Effect.h"
#include "DxLib.h"

//�G�t�F�N�g���Ǘ�����N���X
class EffectManager {
public:
	std::vector<WhiteCircleEffect> effects;
	EffectManager();
	void add(const WhiteCircleEffect& ins);
	void update();
	void draw() const;
};

