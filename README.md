# moving-stars
a small c++ project which is an application of polymorphism

# 基本思路
### 1.初始化星星在画布的位置、颜色深浅  
### 2.使用_kbhit()控制while循环  
### 3.设置内循环，其中用指针与多态调用星星的移动函数  

# 星星类的设计
### 1.使用一个抽象基类star，成员函数有  
&ensp;&ensp;&ensp;&ensp;void OutInit();//星星在x方向超出画布之后进行的初始化操作  
&ensp;&ensp;&ensp;&ensp;void StarInit();//星星的初始化  
&ensp;&ensp;&ensp;&ensp;void NewPos();//获取新位置  
&ensp;&ensp;&ensp;&ensp;void MoveStar();//在x方向移动星星  
&ensp;&ensp;&ensp;&ensp;virtual void Clear() = 0;//擦除星星  
&ensp;&ensp;&ensp;&ensp;virtual void Draw() = 0;//画星星  
### 2.移动星星的思路  
&ensp;&ensp;&ensp;&ensp;擦除星星  
&ensp;&ensp;&ensp;&ensp;获取新位置  
&ensp;&ensp;&ensp;&ensp;画星星  
### 3.派生类虚函数设计(以画X型星星为例)  
&ensp;&ensp;&ensp;&ensp;settextcolor(color);//设置文本颜色  
&ensp;&ensp;&ensp;&ensp;outtextxy(x, y, _T("X"));//在画布上（x，y）位置画上文本“X”  
### 4.擦除星星的思路  
&ensp;&ensp;&ensp;&ensp;设置文本颜色时颜色值为0代表黑色，用黑色即可实现擦除效果  
  
