#include <iostream>
#include <string>
#include "DxLib.h"
#include "MyGlobal.h"

// string�^���g����

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);//Log.txt�𐶐����Ȃ��悤�ɐݒ�
	ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);//��ʃT�C�Y�w��
	if (DxLib_Init() == 1) { return -1; }//�������Ɏ��s���ɃG���[��f�����ďI��
	SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�


	fontHandle = CreateFontToHandle("Segoe UI", 20, 5, DX_FONTTYPE_ANTIALIASING_4X4);//�t�H���g��ǂݍ���

	std::string text = "�₫���΁I";

	while (ProcessMessage() == 0) {
		ClearDrawScreen();//����ʏ���

		GetMousePoint(&mouseX, &mouseY); //�}�E�X���W�X�V
		keyUpdate();//(����֐�)�L�[�X�V

		DrawFormatStringToHandle(20, 20, GetColor(255, 255, 255), fontHandle, "Z, X�ŕ����ǉ�");

		// �L�[���͂ŕ����ǉ�
		if (keyState[KEY_INPUT_Z] == 1) {
			text += "���΁I";
		}
		if (keyState[KEY_INPUT_X] == 1) {
			text += "���ǂ�I";
		}

		// �������\��
		DrawFormatStringToHandle(20, 60, GetColor(255, 255, 255), fontHandle, text.c_str());

		ScreenFlip();//����ʂ�\��ʂɃR�s�[
	}

	DxLib_End();
	return 0;
}