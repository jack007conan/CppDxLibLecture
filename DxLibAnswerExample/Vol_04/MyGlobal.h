#pragma once
#include "DxLib.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern int fontHandle;
extern int mouseX, mouseY;//マウス座標

 //キー取得用配列
extern char buf[256];
extern int keyState[256];

//キー入力状態を更新する関数
void keyUpdate();

