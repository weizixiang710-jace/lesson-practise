//parent.cpp
#include "parent.h"
#include <iostream>
//這是一個工具箱 要有他才能使用裡面的工具 例如 cout
using namespace std;
//這是要去命名#include <iostream>裡面的工具
/**EX:

如果要把這個比喻修飾得更完美一點，我們可以分成兩層來看：
#include <iostream>：這才是真正的「把工具箱拿過來」放在旁邊。
using namespace std;：這像是「把工具箱的蓋子打開，允許自己直接喊工具的名字」。

🛠️ 實際的運作長這樣：
如果你只拿了工具箱（#include <iostream>），卻不打開蓋子（沒寫 using namespace std;）
當你需要拿一把叫 cout 的起子時，你就必須每次都寫全名：

「我要拿 std 工具箱裡面的 cout 起子！」（程式碼寫成 std::cout）
但如果你在檔案開頭寫了 using namespace std;，就等於是宣告：
「接下來這整張桌子上，只要我喊 cout，指的就是 std 工具箱裡的那把起子！」你就不用每次都碎念 std:: 了。

這時有一個問題就是為甚麼parent.h不用加上using namespace std; because
就像你剛才發現的，因為 parent.h 這張桌子上（程式碼內）根本沒有要組裝任何需要「起子（cout）」的東西，
它只是在畫設計圖。既然不需要工具，
它自然連把工具箱拿過來的步驟（#include）都省下來囉！

**/

parent::parent()
{
    cout<<"1";
    //ctor
}

parent::parent(int a)
{
    cout<<"5";

}

parent::~parent()
{
    //dtor
     cout<<"2";
}
//----------------------------

//parent.h
#ifndef PARENT_H
#define PARENT_H
/**
就跟上面說的一樣這裡不會有
#include <iostream>
using namespace std;
**/

class parent
{
    public:
        parent();
        parent(int a);
        /**如果要在.cpp檔上面寫parent(int a)也就是新增一個新的「帶參數的建構子」
           那必須在.h檔上面加上parent(int a)
        **/
        virtual ~parent();// 關鍵：當父類別時，解構子最好加上 virtual，釋放記憶體才不會出錯
    
    protected:

    private:
};

#endif // PARENT_H
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//child.cpp
#include "child.h"
#include <iostream>

using namespace std;

child::child()
{
    //ctor
    cout<<"a";
}

child::child(int a)
{
    cout<<"c";
}
child::~child()
{
    //dtor
    cout<<"b";
}
//----------------------

//child.h
#ifndef CHILD_H
#define CHILD_H

#include "parent.h"
class child : public parent
//// 語法：class 子類別 : public 父類別
{
    public:
        child();

        child(int a);

        ~child();

};

#endif // CHILD_H
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//main

#include <iostream>
#include "parent.h"
#include "child.h"

using namespace std;

int main()
{

    child *a; //指標變數 只是指定位子並不會有實際的動作
    parent *b;
    parent c;//因為是第一層的父類別所以只會跑第一層
    child d;/**這就不一樣了 因為是子類別所以會繼承父 也就是說他會先去繼承父的數值
               再去跑自己的第二層
    **/

    cout<<"x";//單純輸出
    a=new child(10);/**
    這個參數跟指標變數有關
  //child *a;（準備一個「大門牌」）
     意思： 宣告一個指標變數（Pointer），名字叫做 a。
    它的工作： a 本身不是一個 child 物件，
    它只是一個用來「紀錄記憶體地址」的抽屜（指標）。

  //new child();（在記憶體蓋一棟「新房子」）
      意思： new 這個關鍵字非常重要，它的意思是「去記憶體的自由世界（Heap）中，
     挖出一塊全新、乾淨的空間」，然後根據 child() 的設計圖，
     把這個 child 物件實例化
     **/
    b=new parent();
    cout<<"y";//單純輸出

    delete a;//記得他是刪除對應的數值
  //既然創造出空間了那就要刪出這個空間(EX:b=new parent();) 這就是他的工作
    /**
    這裡程式還沒有跑完 所以還是由上往下 而刪除的東西式指定的 數值是甚麼就是殺甚麼
    **/
    delete b;

  
  // a=new child(10);
  /**還有一點就是 在刪除的過程中 這行雖然子類別會去到int a的整數區域
  但是 父類別不會去到那邊 而是會去原本的預設值**/

    return 0;//別忘了還有他
  /**在整個程式碼結束後他必須把剩下的東西也帶走
  也就是parent c; child d; 刪除的順序就是以下說明 
  本日金句:(由下往上 然後先殺自己在殺爸爸)
   /**刪除的方式跟建立的時候很不同 
    不同的點在於
    1.建立時:由上往下的 刪除時:由下往上
    2.建立時:是由外的父先開始再到內的子
      **就把他想成在脫衣服 一定要從外面開始脫到裡面
      刪除時:是由內的子先開始再到外的父
      **就把他想成在穿衣服 一定要從內衣穿到外套
    **/
  

  //最後說說本代碼輸出答案　有不懂的地方一定要看這裡去反推阿
  // A:　11ax1c1yb22b22
}
