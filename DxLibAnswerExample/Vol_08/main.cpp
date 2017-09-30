# include <Siv3D.hpp>
# include "GameManager.h"

void Main()
{
	const Font font(18);

	while (System::Update())
	{
		// Z, X, C�L�[�������ƁA���@��ǂ��G�A���̏�ŉ�]����G�A�܂������i�ޓG�𐶐�
		if (Input::KeyZ.clicked) {
			gameManager.enemyManager.add(RandomVec2(Window::Width(), Window::Height() / 2.0), Enemy::Stalker);
		}
		if (Input::KeyX.clicked) {
			gameManager.enemyManager.add(RandomVec2(Window::Width(), Window::Height() / 2.0), Enemy::Rotation);
		}
		if (Input::KeyC.clicked) {
			gameManager.enemyManager.add(RandomVec2(Window::Width(), Window::Height() / 2.0), Enemy::Straight);
		}

		gameManager.update();
		gameManager.draw();

		font( L"�G�̐�:", gameManager.enemyManager.getEnemyNum()).draw();
	}
}
