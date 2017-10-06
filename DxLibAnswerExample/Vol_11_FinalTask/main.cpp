#include "MyGlobal.h"
#include "GameManager.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);//Log.txt�𐶐����Ȃ��悤�ɐݒ�
	ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);//��ʃT�C�Y�w��
	if (DxLib_Init() == 1) { return -1; }//�������Ɏ��s���ɃG���[��f�����ďI��
	SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�

	// �t�H���g�����[�h
	gameManager.load();

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();//����ʏ���

		GetMousePoint(&mouseX, &mouseY); //�}�E�X���W�X�V
		keyUpdate();//(����֐�)�L�[�X�V

		gameManager.update();
		gameManager.draw();

		ScreenFlip();//����ʂ�\��ʂɃR�s�[
	}

	DxLib_End();
	return 0;
}