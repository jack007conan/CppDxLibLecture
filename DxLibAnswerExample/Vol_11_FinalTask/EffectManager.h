#pragma once
#include <vector>
#include <memory>
#include "IEffect.h"

//�G�t�F�N�g���Ǘ�����N���X
class EffectManager {
public:
	std::vector<std::shared_ptr<IEffect>> effects;
	EffectManager();
	void add(const std::shared_ptr<IEffect>& ptr);
	void update();
	void draw() const;
};

