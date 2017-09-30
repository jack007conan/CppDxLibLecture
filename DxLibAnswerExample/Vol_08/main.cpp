#include "DxLib.h"
#include "GameManager.h"
#include "MyGlobal.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
	SetGraphMode(640, 480, 32);//��ʃT�C�Y�w��
	SetOutApplicationLogValidFlag(FALSE);//Log.txt�𐶐����Ȃ��悤�ɐݒ�
	if (DxLib_Init() == 1) { return -1; }//�������Ɏ��s���ɃG���[��f�����ďI��


	fontHandle = CreateFontToHandle("Segoe UI", 20, 5, DX_FONTTYPE_ANTIALIASING_4X4);//�t�H���g��ǂݍ���

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();//����ʏ���
		SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�

		GetMousePoint(&mouseX, &mouseY); //�}�E�X���W�X�V
		keyUpdate();//(����֐�)�L�[�X�V

		// Z, X, C�L�[�������ƁA���@��ǂ��G�A���̏�ŉ�]����G�A�܂������i�ޓG�𐶐�
		if (keyState[KEY_INPUT_Z] == 1) {
			gameManager.enemyManager.add(Enemy(GetRand(640), GetRand(480), Enemy::Stalker));
		}
		if (keyState[KEY_INPUT_X] == 1) {
			gameManager.enemyManager.add(Enemy(GetRand(640), GetRand(480), Enemy::Rotation));
		}
		if (keyState[KEY_INPUT_C] == 1) {
			gameManager.enemyManager.add(Enemy(GetRand(640), GetRand(480), Enemy::Straight));
		}

		gameManager.update();
		gameManager.draw();

		DrawFormatStringToHandle(20, 20, GetColor(255, 255, 255), fontHandle, "Z, X C�œG���� �G�̐�:%d", gameManager.enemyManager.getEnemyNum());

		ScreenFlip();//����ʂ�\��ʂɃR�s�[
	}

	DxLib_End();
	return 0;
}