# DXライブラリで学ぶC++

今回は以下のC++の諸機能を学ぶ。  
* string
* bool
* 関数オーバーロード
* コンストラクタのオーバーロード


## string型

C++標準ライブラリ(STL)のstring型を使うと、char型に比べ、より簡単に文字列を扱うことが出来る。  
+演算子で文字列の結合、==演算子で文字列の比較が出来る。  
string型を使用するときは、stringヘッダーをインクルードする。（string.hではないことに注意！）  

```cpp
#include <iostream>
#include <string>

int main(){
    std::string str1 = "いかろちゃん";
    std::string str2 = "かわいい";
    
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
    
    std::string str3;
    // +で文字列の結合ができる
    str3 = str1 + str2;
    
    std::cout << str3 << std::endl;
    
    // ==で文字列の比較ができる trueなので1が出力される
    std::cout << (str3 == (str1+str2)) << std::endl;
    
    return 0;
}
```


> std::to_string関数を使うと、int型、double型等の変数をstring型に変換できる。

```cpp
#include <iostream>
#include <string>

int main(){
    std::string str = "いかろちゃんかわいい";
	int ix = 23;
	double dx = 3.14;
	
	str += " ";
	str += std::to_string(ix);
	str += " ";
	str += std::to_string(dx);
    
    std::cout << str << std::endl;
    
    return 0;
}
```


DxLibでの使用例。```DrawFormatStringToHandle```関数の```FormatString ```引数は```const char*```型で、string型ではないので、string型のメンバ関数```c_str```関数を用いて```const char*```型で文字列を取得し、```DrawFormatStringToHandle```関数に値を渡す。  

(DxLibテンプレートプロジェクトのmain.cppを書き換え)  

```cpp
#include <iostream>
#include <string>
#include "DxLib.h"
#include "MyGlobal.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);//Log.txtを生成しないように設定
	ChangeWindowMode(TRUE);//非全画面にセット
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);//画面サイズ指定
	if (DxLib_Init() == 1) { return -1; }//初期化に失敗時にエラーを吐かせて終了
	SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に


	fontHandle = CreateFontToHandle("Segoe UI", 20, 5, DX_FONTTYPE_ANTIALIASING_4X4);//フォントを読み込み

	std::string text = "やきそば！";

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();//裏画面消す

		GetMousePoint(&mouseX, &mouseY); //マウス座標更新
		keyUpdate();//(自作関数)キー更新

		DrawFormatStringToHandle(20, 20, GetColor(255, 255, 255), fontHandle, "Z, Xで文字追加");

		// キー入力で文字追加
		if (keyState[KEY_INPUT_Z] == 1) {
			text += "そば！";
		}
		if (keyState[KEY_INPUT_X] == 1) {
			text += "うどん！";
		}

		// 文字列を表示
		DrawFormatStringToHandle(20, 60, GetColor(255, 255, 255), fontHandle, text.c_str());

		ScreenFlip();//裏画面を表画面にコピー
	}

	DxLib_End();
	return 0;
}
```

## bool型

C++には真偽を表すためだけの型、bool型が存在する。  


```cpp
#include <iostream>

int main(){

	bool b = true;

	if (b){
		std::cout << "条件文は真" << std::endl;
	}
	else{
		std::cout << "条件文は偽" << std::endl;
	}

	return 0;
}
```

以下のように、条件を満たすかどうかの真・偽を返す関数の返り値の型としてbool型を使うことが多い。

```cpp
#include <iostream>

// 偶数だったらtrue,そうでなければfalseを返す関数
bool isEven(int num){
	return (num % 2) == 0;
}

int main(){

	if (isEven(10)){
		std::cout << "条件文は真" << std::endl;
	}
	else{
		std::cout << "条件文は偽" << std::endl;
	}

	return 0;
}	
```


## 関数オーバーロード

C++では、引数が異なる同じ名前の関数を定義できる。そのように関数を多重定義することを関数オーバーロードという。
実行中に、引数によって呼ばれる関数が選択される。

```cpp
#include <iostream>

//絶対値を返す関数、myAbsを3通りにオーバーロードする
int myAbs(int n){
	std::cout << "int型のmyAbsが呼ばれました" << std::endl;
	if(n > 0){
		return n;
	}else{
		return -n;
	}
}

float myAbs(float n){
	std::cout << "float型のmyAbsが呼ばれました" << std::endl;
	if(n > 0){
		return n;
	}else{
		return -n;
	}
}

double myAbs(double n){
	std::cout << "double型のmyAbsが呼ばれました" << std::endl;
	if(n > 0){
		return n;
	}else{
		return -n;
	}
}


int main(){

	int a = -10;
	float b = -2.71f;
	double c = -3.14;
	
	std::cout << myAbs(a) << std::endl << std::endl;
	std::cout << myAbs(b) << std::endl << std::endl;
	std::cout << myAbs(c) << std::endl << std::endl;


	return 0;

}
```

> 引数の数によって呼ばれる関数が変わる。

```cpp
#include <iostream>

void myFunc(int a){
	std::cout << "引数１つのmyFuncが呼ばれました。引数は " << a << std::endl;
}

void myFunc(int a, int b){
	std::cout << "引数２つのmyFuncが呼ばれました。引数は " << a << " " << b << std::endl;
}

int main(){
	myFunc(1);
	myFunc(2, 3);

	return 0;
}
```


## 演習問題(コンソール)

1. 引数で受け取った値の2乗を返す関数mySquare()を作成せよ。mySquare()をint,float,double型の3通りに対応できるようオーバーロードしなさい。


## コンストラクタのオーバーロード

C++ではクラス生成時に呼び出されるコンストラクタというものを定義できる。
関数オーバーロードと同じ要領で、コンストラクタは複数定義できる。

> コンストラクタの書き方

```cpp
クラスの名前(引数){
    初期化処理...
}
```

> obj1は引数(1, 2)で初期化。obj2は引数無しで初期化なので自動的に(0, 0)が入る。

```cpp
#include <iostream>

class Vector2{
public:
	int x;
	int y;
	
	Vector2():
		x(0),
		y(0)
	{
		std::cout << "引数なしのコンストラクタが呼ばれました" << std::endl;
	}
	
	Vector2(int _x, int _y):
		x(_x),
		y(_y)
	{
		std::cout << "引数ありのコンストラクタが呼ばれました" << std::endl;
	}
};

int main(){

    Vector2 obj1(1, 2);
    std::cout << obj1.x << " " << obj1.y << std::endl;
    
    Vector2 obj2;
    std::cout << obj2.x << " " << obj2.y << std::endl;
    
    return 0;
}
```




## 演習問題(コンソール)

1. 以下の様なクラスVector3を作った。コンストラクタとデストラクタを作れ。  
コンストラクタ・デストラクタが呼ばれたら、"～が呼ばれました"と出力するようにせよ。コンストラクタは引数有りのものと引数なし（引数なしの時はx=0,y=0,z=0)のものを作ること。  
コンストラクタの初期化の部分はメンバイニシャライザを用いた形式で書くこと。

```cpp
class Vector3{
	public:
		int x, y, z;

		//以下にコンストラクタとデストラクタ書く
}
```

## 演習問題(DxLib)

1. 今回は特になし


##  Tips : インスタンスの作成と同時に関数を呼ぶ例

以下の例では、色を表すMyColorクラス、円を表すMyCircleクラスを用意し、インスタンスを作成しそのまま関数の引数に入れる例と、インスタンスの作成と同時に関数を呼ぶ例を示している。このように、C++はCに比べ、エレガントな表記が可能になる。  

```cpp
#include <iostream>

// 色を表すクラス (赤成分,緑成分,青成分):(r,g,b)
class MyColor {
public:
	int r, g, b;

	MyColor(int _r, int _g, int _b) :
		r(_r),
		g(_g),
		b(_b)
	{
	}
};

// 円を表すクラス 座標:(x,y)、半径:r
class MyCircle {
public:
	int x, y, r;

	MyCircle(int _x, int _y, int _r) :
		x(_x),
		y(_y),
		r(_r)
	{
	}

	// 自分の情報と、引数にとったMyColorの情報を出力する関数
	void showSelfAndColor(const MyColor& color) {
		std::cout << "Circle:(x, y, r) = (" << x << "," << y << "," << r << ")"
			<< " Color:(r, g, b) = (" << color.r << "," << color.g << "," << color.b << ")" << std::endl;
		std::cout << std::endl;
	}
};


int main() {

	// MyCircleのインスタンスがmyCircleA変数に、MyColorのインスタンスがmyColorA変数に入り、それをshowSelfAndColorで表示する
	MyCircle myCircleA(10, 10, 5);
	MyColor myColorA(70, 80, 90);
	myCircleA.showSelfAndColor(myColorA);

	// MyCircleのインスタンスがmyCircleB変数に入り、MyColorのインスタンスは生成とともにshowSelfAndColorの引数となり表示される
	MyCircle myCircleB(20, 20, 6);
	myCircleB.showSelfAndColor(MyColor(100, 110, 120));

	// MyCircleのインスタンスの生成と同時にshowSelfAndColor関数を呼ぶ。
	// またMyColorのインスタンスも生成とともにshowSelfAndColorの引数となり表示される
	MyCircle(30, 30, 7).showSelfAndColor(MyColor(200, 210, 220));

	return 0;
}
```



##  Tips : constメンバ関数

constメンバ関数を使うと、メンバ変数を変更できないメンバ関数を作ることができる。これを用いることで、誤ってメンバを変更することを防ぐことが出来、また多人数開発の際にメンバ変数を変更していないことを明示できるので、積極的に使うべきである。  

```cpp
#include <iostream>

class MyClass {
public:
	int a;
	MyClass(int _a);
	void func() const;
};

MyClass::MyClass(int _a) {
}

void MyClass::func() const {
	// コメントを外すとメンバ変数を変更してしまうのでコンパイルエラー
	// a = 100;
}


int main() {

	return 0;
}
```
