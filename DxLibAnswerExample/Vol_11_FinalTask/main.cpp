#include "GameManager.h"

void Main() {
	// �t�H���g�����[�h
	gameManager.load();

	while (System::Update()) {
		gameManager.update();
		gameManager.draw();
	}
}
