# include <Siv3D.hpp>
# include "GameManager.h"

void Main()
{
	const Font font(18);

	while (System::Update())
	{
		// Z, X, Cキーを押すと、自機を追う敵、その場で回転する敵、まっすぐ進む敵を生成
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

		font( L"敵の数:", gameManager.enemyManager.getEnemyNum()).draw();
	}
}
