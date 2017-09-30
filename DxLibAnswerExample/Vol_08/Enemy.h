#pragma once
#include <Siv3D.hpp>

class Enemy {
public:
	static const double Radius;

	// 敵の種類を設定
	enum Kind
	{
		Stalker,
		Rotation,
		Straight
	};
	Kind kind;
	Vec2 pos;
	Vec2 velocity;
	int eFrame;
	Enemy(const Vec2& _pos, Kind _kind);
	void update();
	void draw();
};
