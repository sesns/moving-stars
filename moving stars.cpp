#include <graphics.h>
#include <time.h> 
#include <conio.h> 
#include<stdlib.h> 
using namespace std;
#define MAXSTAR 30 // 星星总数

// star为抽象基类  PointStar和XStar和StarStar为派生类
class Star
{
public:
	Star() {};
	virtual ~Star() {};
	void OutInit();//星星在x方向超出画布之后进行的初始化操作
	void StarInit();//星星的初始化
	void NewPos();//获取新位置
	void MoveStar();//在x方向移动星星

protected:
	virtual void Clear() = 0;//擦除星星
	virtual void Draw() = 0;//画星星
	double x;
	double y;
	COLORREF color;
	double step;
};
class XStar :public Star
{
public:
	XStar() {};
	virtual ~XStar() {};
protected:
	virtual void Clear();
	virtual void Draw();
};
class PointStar :public Star
{
public:
	PointStar() {};
	virtual ~PointStar() {};
protected:
	virtual void Clear();
	virtual void Draw();
};
class StarStar :public Star
{
public:
	StarStar() {};
	virtual ~StarStar() {};
protected:
	virtual void Clear();
	virtual void Draw();
};



void Star::OutInit()
{
	x = 0;
	y = rand() % 480;
	step = rand() % 5000 / 1000 + 1;
	int col = 256 * step / 6; //使得颜色与每次移动的步数相对应
	color = RGB(col, col, col);//RGB三个通道的值相同则颜色为灰色，值的大小则影响了灰色的深浅
}
void Star::StarInit()
{
	x = rand() % 640;
	y = rand() % 480;
	step = rand() % 5000 / 1000 + 1;
	int col = 256 * step / 6;
	color = RGB(col, col, col);
}
void Star::NewPos()
{
	x = x + step;
	if (x > 640) //星星在x方向出界的处理
		this->OutInit();
}
void Star::MoveStar()
{
	this->Clear();
	this->NewPos();
	this->Draw();
}


void XStar::Draw()
{
	settextcolor(color);//设置文本颜色
	outtextxy(x, y, _T("X"));//在画布上（x，y）位置画上文本“X”
}
void XStar::Clear()
{
	settextcolor(0);//设置文本颜色为黑色，从而达到了擦除的效果
	outtextxy(x, y, _T("X"));
}
void PointStar::Draw()
{
	settextcolor(color);
	outtextxy(x, y, _T("·"));
}
void PointStar::Clear()
{
	settextcolor(0);
	outtextxy(x, y, _T("·"));
}
void StarStar::Draw()
{
	settextcolor(color);
	outtextxy(x, y, _T("★"));
}
void StarStar::Clear()
{
	settextcolor(0);
	outtextxy(x, y, _T("★"));
}
int main()
{
	srand((unsigned)time(NULL));
	initgraph(640, 480);//画布大小为 640 480
	XStar xstars[MAXSTAR];
	PointStar pstars[MAXSTAR];
	StarStar sstars[MAXSTAR];
	Star* p1[MAXSTAR];//使用基类指针来使用多态
	Star* p2[MAXSTAR];
	Star* p3[MAXSTAR];
	for (int i = 0; i < MAXSTAR; i++) //执行天空中星星的初始化
	{
		p1[i] = &xstars[i]; //基类指针数组初始化
		p2[i] = &pstars[i];
		p3[i] = &sstars[i];
		p1[i]->StarInit();
		p2[i]->StarInit();
		p3[i]->StarInit();
	}
	while (!_kbhit()) //当不敲击键盘时进行循环
	{
		for (int i = 0; i < MAXSTAR; i++)
		{
			p1[i]->MoveStar();
			p2[i]->MoveStar();
			p3[i]->MoveStar();
		}
		Sleep(30);
	}
	closegraph();

}
