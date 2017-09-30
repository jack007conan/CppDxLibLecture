#include <iostream>
#include <algorithm>
#include "Effect.h"

const int WhiteCircle::LifeTime = 5;
const double WhiteCircle::Radius = 50.0;
const Color WhiteCircle::Color(255, 255, 255, 80);



void IParticleEffect::checkDead() {
	if (elapsedFrame > lifeTime) {
		isDead = true;
	}
}

void IParticleEffect::update() {
	checkDead();
	elapsedFrame++;
}

WhiteCircle::WhiteCircle(double _x, double _y) :
	IParticleEffect(_pos, LifeTime)
{
}

void WhiteCircle::draw()const {
	DrawCircle(x, y, Radius, Color);
}


//エフェクトの管理クラス
EffectManager::EffectManager() {
}

void EffectManager::add(const std::shared_ptr<IParticleEffect>& ptr) {
	effects.emplace_back(ptr);
}

void EffectManager::update() {
	for (const auto& effect : effects) {
		effect->update();
	}

	auto iter = std::remove_if(effects.begin(), effects.end(), [](const std::shared_ptr<IParticleEffect>& ptr) {
		return ptr->isDead;
	});
	effects.erase(iter, effects.end());
}

void EffectManager::draw() const {
	for (const auto& effect : effects) {
		effect->draw();
	}
}

IParticleEffect::IParticleEffect(double _x, double _y, int _lifeTime) :
	x(_x), y(_y),
	lifeTime(_lifeTime),
	elapsedFrame(0),
	isDead(false)
{
}
