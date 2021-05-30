#include <graphics.h>
#include <time.h> 
#include <conio.h> 
#include<stdlib.h> 
using namespace std;
#define MAXSTAR 30 // ��������

// starΪ�������  PointStar��XStar��StarStarΪ������
class Star
{
public:
	Star() {};
	virtual ~Star() {};
	void OutInit();//������x���򳬳�����֮����еĳ�ʼ������
	void StarInit();//���ǵĳ�ʼ��
	void NewPos();//��ȡ��λ��
	void MoveStar();//��x�����ƶ�����

protected:
	virtual void Clear() = 0;//��������
	virtual void Draw() = 0;//������
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
	int col = 256 * step / 6; //ʹ����ɫ��ÿ���ƶ��Ĳ������Ӧ
	color = RGB(col, col, col);//RGB����ͨ����ֵ��ͬ����ɫΪ��ɫ��ֵ�Ĵ�С��Ӱ���˻�ɫ����ǳ
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
	if (x > 640) //������x�������Ĵ���
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
	settextcolor(color);//�����ı���ɫ
	outtextxy(x, y, _T("X"));//�ڻ����ϣ�x��y��λ�û����ı���X��
}
void XStar::Clear()
{
	settextcolor(0);//�����ı���ɫΪ��ɫ���Ӷ��ﵽ�˲�����Ч��
	outtextxy(x, y, _T("X"));
}
void PointStar::Draw()
{
	settextcolor(color);
	outtextxy(x, y, _T("��"));
}
void PointStar::Clear()
{
	settextcolor(0);
	outtextxy(x, y, _T("��"));
}
void StarStar::Draw()
{
	settextcolor(color);
	outtextxy(x, y, _T("��"));
}
void StarStar::Clear()
{
	settextcolor(0);
	outtextxy(x, y, _T("��"));
}
int main()
{
	srand((unsigned)time(NULL));
	initgraph(640, 480);//������СΪ 640 480
	XStar xstars[MAXSTAR];
	PointStar pstars[MAXSTAR];
	StarStar sstars[MAXSTAR];
	Star* p1[MAXSTAR];//ʹ�û���ָ����ʹ�ö�̬
	Star* p2[MAXSTAR];
	Star* p3[MAXSTAR];
	for (int i = 0; i < MAXSTAR; i++) //ִ����������ǵĳ�ʼ��
	{
		p1[i] = &xstars[i]; //����ָ�������ʼ��
		p2[i] = &pstars[i];
		p3[i] = &sstars[i];
		p1[i]->StarInit();
		p2[i]->StarInit();
		p3[i]->StarInit();
	}
	while (!_kbhit()) //�����û�����ʱ����ѭ��
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
