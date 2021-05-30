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

# 参考  
https://blog.csdn.net/wuhong1989/article/details/95383647?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162228629216780366547515%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=162228629216780366547515&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_v2~rank_v29-15-95383647.pc_search_result_cache&utm_term=c%2B%2B%E5%A4%9A%E6%80%81%E7%BB%83%E4%B9%A0&spm=1018.2226.3001.4187

