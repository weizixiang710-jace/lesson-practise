#include <iostream>

using namespace std;

class score
{
/**
    在public以上都是私有區域 所以需要friend去做辨別
    在類別內部將一個外部函式宣告為 friend 時，
    就是給予這個函式特權，讓它能夠直接存取
   
     [A：回傳值型態 ][B：函式名稱 ][C：參數列表 ]
     [    score    ][ operator+ ][ (const score& a, const score& b); ]
     回傳值型態是可以自由更改的 不需要跟class同名
**/
    friend score operator+(const score& a, const score& b);
    friend score operator+(const score& a, int b);
    friend score operator+(int a, const score& b);

    int math;
    int computer;
    int total;

public:
    // 建構子
    score(int a = 0, int b = 0)
    {
        math = a;
        computer = b;
        total = math + computer;
    }
};

// 1. 處理 tom = peter + mary;
score operator+(const score& a, const score& b)
{
    return score(a.math + b.math, a.computer + b.computer);
}

// 2. 處理 tom = peter + 10;
score operator+(const score& a, int b)
{
    return score(a.math + b, a.computer + b);
}

// 3. 處理 tom = 10 + peter;
score operator+(int a, const score& b)
{
    return score(a + b.math, a + b.computer);
}

int main()
{
    score peter(10,20);
    score mary(20,35);
    score tom;

    tom=peter+mary;
    tom=peter+10;
    tom=10+peter;

    return 0;
}
