#include <iostream>
#include "DxLib.h"

#include "MyGlobal.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
	SetGraphMode(640, 480, 32);//��ʃT�C�Y�w��
	SetOutApplicationLogValidFlag(FALSE);//Log.txt�𐶐����Ȃ��悤�ɐݒ�
	if (DxLib_Init() == 1) { return -1; }//�������Ɏ��s���ɃG���[��f�����ďI��


	fontHandle = CreateFontToHandle("Segoe UI", 20, 5, DX_FONTTYPE_ANTIALIASING_4X4);//�t�H���g��ǂݍ���

	double x = 320.0;
	double y = 240.0;
	const double SPEED = 5.0;

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();//����ʏ���
		SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�

		GetMousePoint(&mouseX, &mouseY); //�}�E�X���W�X�V
		keyUpdate();//(����֐�)�L�[�X�V

		// �㉺���E�L�[�ňړ�
		if (keyState[KEY_INPUT_LEFT] > 0) {
			x -= SPEED;
		}
		if (keyState[KEY_INPUT_RIGHT] > 0) {
			x += SPEED;
		}
		if (keyState[KEY_INPUT_UP] > 0) {
			y -= SPEED;
		}
		if (keyState[KEY_INPUT_DOWN] > 0) {
			y += SPEED;
		}

		// Z�L�[���������t���[���Ń����_���Ɉړ�
		if (keyState[KEY_INPUT_Z] == 1) {
			x += GetRand(100);
		}

		// x, y�ɐԂ̉~��`��
		DrawCircle(x, y, 20, GetColor(255, 0, 0));

		//����ɕ����i�}�E�X�̍��W�j��`��
		DrawFormatStringToHandle(20, 20, GetColor(255, 255, 255), fontHandle, "X:%.0f Y:%.0f", x, y);

		ScreenFlip();//����ʂ�\��ʂɃR�s�[
	}

	DxLib_End();
	return 0;
}