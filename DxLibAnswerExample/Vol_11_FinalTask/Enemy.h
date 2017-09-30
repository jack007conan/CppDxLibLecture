#pragma once
#include <vector>
#include <memory>
#include <Siv3D.hpp>


//各敵の基底クラス
class IEnemy {
public:
	static const size_t EffectNum;
	static const double EffectGenerateRange;

	Vec2 pos;
	Vec2 velocity;
	double radius;
	double hp;
	int score;
	Color color;
	int eFrame; // 生成されてからの経過フレーム
	bool isDead; // 死んでいるかどうかのフラグ

	IEnemy(const Vec2& _pos, const Vec2& _velocity, double _radius, double _hp, int _score, const Color& _Color);

	virtual ~IEnemy() = default;

	void update();

	// 動き方
	virtual void move() = 0;

	// ショットの打ち方
	virtual void shot() = 0;

	// 自機が撃った弾との当たり判定を取る
	void checkHit();

	// 画面外に出ていないか、HPはゼロになっていないかをチェックし、死んでいるかどうかのフラグを更新する。
	void checkDead();

	void draw() const;
};


class EnemyStalker : public IEnemy {
public:
	static const double StalkerEnemySpeed;
	static const double Radius;
	static const double Hp;
	static const int Score;
	static const Color Color_;

	EnemyStalker(const Vec2& _pos);
	~EnemyStalker() = default;
	void move() override;
	void shot() override;
};

class EnemyStop : public IEnemy {
public:
	static const size_t EnemyshotRate;
	static const double BulletSpeed;
	static const double Radius;
	static const double Hp;
	static const int Score;
	static const Color Color_;

	EnemyStop(const Vec2 & _pos);
	~EnemyStop() = default;
	void move() override;
	void shot() override;
};

class EnemyRotation : public IEnemy {
public:
	static const size_t EnemyshotRate;
	static const size_t EnemyshotNum;
	static const double EnemyBulletSpeed;
	static const double EnemyOmega;
	static const double Radius;
	static const double Hp;
	static const int Score;
	static const Color Color_;

	EnemyRotation(const Vec2 & _pos);
	~EnemyRotation() = default;
	void move() override;
	void shot() override;
};

//敵全体を管理するクラス
class EnemyManager {
public:
	std::vector<std::shared_ptr<IEnemy>> enemies;
	EnemyManager();
	void add(const std::shared_ptr<IEnemy>& ptr);
	void update();
	void draw() const;
};

