class test{

    int value;
//public: 上方，預設是 private（私有的）
  public:
    set (int a)//成員
    {
      value=a;
      /**value = a; 這行程式碼做的事情叫做「賦值（指定）」，
      它是一個動作，意思是「把 a 的數值複製一份，塞進 value 裡面**/
    }

    test(int a)//建構子
    {
      value=a;
    }
};
test data;//物件
/**
 寫下 test data; 的那一瞬間，在電腦的記憶體裡，就真的出現了一個叫 data 的抽屜。
 因為它是按照 test 的設計圖做的，所以 data 這個抽屜的肚子裡，自動就包含了一個叫做 value 的格子
 所以他們是相關的
**/

//請問下列何者錯誤A: A B D

A test.data=0;
/**錯誤原因： 語法邏輯完全顛倒。test 是類別名稱（型態），data 是物件名稱（變數）。
在 C++ 中，我們只能用「物件.成員」來存取，不能用「類別.物件」。**/
B data.value=0;
/**如果把 public: 移動到 int value; 的上面 
把 public: 移到最上面，代表大括號裡面的所有東西（包括 value、set、test）通通都變成了 public
也就是說value變成了可以拿到的東西**/
C data.set(10);

D data->value=0;
/**錯誤原因： 1. ->（箭頭運算子）是用於指標（Pointer）的。但這裡的 data 是一個普通物件，不是指標，應該用點記號 .。
2. 承 B 選項，value 是 private，就算改成點，外部也碰不到。**/
---------------------------------------------------------------------------------------------------
class test{

    public:
      int value;
  
    private:
    set (int a)
    {
        value=a;
    }
};

test data;

A data.value=10;
//現在int value; 已經是公開的了所以可以拿到
B data->value=10;

C data.set(20);

D data=10; 
----------------------------------------------------------------------------------------------------
  class test{
    
      int value1,value2;
    public:

    test()//預設值
    {
        value1=10;
        value2=20;
    }
    test(int a)//當輸入一個數字時
    {
        value1=a;
        value2=0;
    }
    test(int a,int b)//當輸入二個數字時
    {
        value1=a;
        value2=b;
    }
    /**
    test data; ➡️ 沒有給參數 ➡️ 觸發 test() ➡️ 得到 value1=10, value2=20

    test data(5); ➡️ 給了一個參數 ➡️ 觸發 test(int a) ➡️ 得到 value1=5, value2=0

    test data(5, 6); ➡️ 給了兩個參數 ➡️ 觸發 test(int a, int b) ➡️ 得到 value1=5, value2=6
    **/
};
test data;

-----------------------------------------------------------------------------------------------

  #include <bits/stdc++.h>

using namespace std;

class score 
{
    friend int operator +(int a,score&b);
    int math ;
    int computer;
    int total;
public:
    score(int a=0,int b=0)
    {
        math=a;
        computer=b;
        total=math+computer;
        
    }
};

int operator +(int a,score&b)
{
    return a+b.total;
}

int main(int argc ,char** argv)
{
    score peter(10,20);
    score mary(20,35);
    
}
A cout<<peter+10<<endl;

B cout<<peter+marry<<endl;

C cout<<10+marry<<endl;

D cout<<marry +peter<<endl; 








  


