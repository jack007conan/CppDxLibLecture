#pragma once


//�e�G�̊��N���X
class IEnemy {
public:
	static const size_t EffectNum;
	static const double EffectGenerateRange;

	double x, y;
	double vx, vy;
	double radius;
	double hp;
	int score;
	unsigned int color;
	int elapsedFrame; // ��������Ă���̌o�߃t���[��
	bool isDead; // ����ł��邩�ǂ����̃t���O

	IEnemy(double _x, double _y, double _vx, double _vy, double _radius, double _hp, int _score, unsigned int _Color);

	virtual ~IEnemy() = default;

	void update();

	// ������
	virtual void move() = 0;

	// �V���b�g�̑ł���
	virtual void shot() = 0;

	// ���@���������e�Ƃ̓����蔻������
	void checkHit();

	// ��ʊO�ɏo�Ă��Ȃ����AHP�̓[���ɂȂ��Ă��Ȃ������`�F�b�N���A����ł��邩�ǂ����̃t���O���X�V����B
	void checkDead();

	void draw() const;
};





