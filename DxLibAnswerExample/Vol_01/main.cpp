#include <iostream>
#include "DxLib.h"

#include "MyGlobal.h"

class Player {
public:
	double x, y, speed;

	Player() {
		x = 320.0;
		y = 360.0;
		speed = 5.0;
	}
	void update() {
		// �㉺���E�L�[�ňړ�
		if (keyState[KEY_INPUT_LEFT] > 0) {
			x -= speed;
		}
		if (keyState[KEY_INPUT_RIGHT] > 0) {
			x += speed;
		}
		if (keyState[KEY_INPUT_UP] > 0) {
			y -= speed;
		}
		if (keyState[KEY_INPUT_DOWN] > 0) {
			y += speed;
		}
	}

	//���@�i�~�j��`��
	void draw() {
		DrawCircle(x, y, 30.0, GetColor(0, 0, 255));
	}
};


class Enemy {
public:
	double x, y;

	Enemy(double _x, double _y) {
		x = _x;
		y = _y;
	}

	void update() {
		//�������Ɉړ�
		y += 1.0;
	}

	//�G�l�~�[�i�~�j��`��
	void draw() {
		DrawCircle(x, y, 30.0, GetColor(255, 0, 0));
	}
};



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);//Log.txt�𐶐����Ȃ��悤�ɐݒ�
	ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);//��ʃT�C�Y�w��
	if (DxLib_Init() == 1) { return -1; }//�������Ɏ��s���ɃG���[��f�����ďI��
	SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�


	fontHandle = CreateFontToHandle("Segoe UI", 20, 5, DX_FONTTYPE_ANTIALIASING_4X4);//�t�H���g��ǂݍ���

	Player player;
	Enemy enemy(320.0, 120.0);

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();//����ʏ���

		GetMousePoint(&mouseX, &mouseY); //�}�E�X���W�X�V
		keyUpdate();//(����֐�)�L�[�X�V

		player.update();
		enemy.update();

		player.draw();
		enemy.draw();

		ScreenFlip();//����ʂ�\��ʂɃR�s�[
	}

	DxLib_End();
	return 0;
}