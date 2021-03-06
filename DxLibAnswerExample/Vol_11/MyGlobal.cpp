#pragma once

#include <iostream>
#include "MyGlobal.h"
#include "DxLib.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int fontHandle;//フォント読み込み用変数
int mouseX = 0, mouseY = 0;//マウス座標

//キー取得用の配列
char buf[256] = { 0 };
int keyState[256] = { 0 };

const double PI2 = atan(1.0) * 4.0 * 2.0;

//キー入力状態を更新する関数
void keyUpdate()
{
	GetHitKeyStateAll(buf);
	for (int i = 0; i< 256; i++)
	{
		if (buf[i] == 1) keyState[i]++;
		else keyState[i] = 0;
	}
}

// 長さradiusでランダムな方向のベクトルを(x, y)計算し，ポインタを介して値を入れる
void randomInCircle(double radius, double * x, double * y)
{
	const int RANDOM_MAX = 65535;
	double angle = PI2 * (double)GetRand(RANDOM_MAX) / (double)RANDOM_MAX;
	double rate = (double)GetRand(RANDOM_MAX) / (double)RANDOM_MAX;
	*x = radius * rate * cos(angle);
	*y = radius * rate  * sin(angle);
}

// 点(x, y)が四角形(左上:(leftTopX, leftTopY), 右下(rightBottomX, rightBottomY))の中にあるか返す
bool checkHitPointRect(double x, double y, double leftTopX, double leftTopY, double rightBottomX, double rightBottomY)
{
	return x > leftTopX && x < rightBottomX && y > leftTopY && y < rightBottomY;
}

// (startX, startY) - (endX, endY)の単位ベクトルを求め，結果をresultX, resultYに入れる
void normalize(double startX, double startY, double endX, double endY, double *resultX, double *resultY) {
	double dx = endX - startX;
	double dy = endY - startY;
	double dist = sqrt(pow(dx, 2.0) + pow(dy, 2.0));

	// 距離が0の場合(1, 0)を結果に入れて関数を抜ける
	if (abs(dist) == 0.0) {
		*resultX = 1.0;
		*resultY = 0.0;
		return;
	}
	*resultX = dx / dist;
	*resultY = dy / dist;
}

