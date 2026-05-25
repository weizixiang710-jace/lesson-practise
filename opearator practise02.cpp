#include <iostream>

using namespace std;

class ComplexNumber {
    friend ostream & operator <<(ostream & out, const ComplexNumber &a);
    friend istream & operator >>(istream & in, ComplexNumber &a);


    friend ComplexNumber operator+(const ComplexNumber &a, const ComplexNumber &b);
    friend ComplexNumber operator-(const ComplexNumber &a, const ComplexNumber &b);
    friend ComplexNumber operator*(const ComplexNumber &a, const ComplexNumber &b);
    friend ComplexNumber operator/(const ComplexNumber &a, const ComplexNumber &b);


    friend bool operator==(const ComplexNumber &a, const ComplexNumber &b);
    friend bool operator!=(const ComplexNumber &a, const ComplexNumber &b);

    float r, i;
/**
    說說甚麼是 "建構子"
    簡單來說：建構子就是一個物件的「出生證明與初始化設定」。
    當你用類別（Class）創造出一個新物件時，這個函式會「自動被呼叫」，用來把物件的初始狀態設定好。
    如果把「類別」比喻成藍圖，那「建構子」就是工廠的自動化生產線，確保每個做出來的產品（物件）
    一出生就裝好了該有的零件和電池。
**/
/**
    名稱必須跟 Class（類別）一模一樣。
    它「沒有」回傳值型態。（連 void 都不用寫，直接不寫）。
    不能被手動呼叫。 它是在你寫的那一瞬間，由系統自動啟動的。
**/
public:

    ComplexNumber(float a = 0.0, float b = 0.0) //這就是建構子                         
{                        
        r = a;
        i = b;
    }
};

istream & operator >>(istream & in, ComplexNumber &a) {
    in >> a.r >> a.i;
    return in;
}

ostream & operator <<(ostream & out, const ComplexNumber &a) {
    if (a.r == 0) {
        if (a.i == 0) out << a.r;
        else out << a.i << "i";
    }
    else {
        if (a.i == 0) out << a.r;
        else {
            if (a.i > 0) out << a.r << "+" << a.i << "i";
            else out << a.r << a.i << "i";
        }
    }
    return out;
}

ComplexNumber operator+(const ComplexNumber &a, const ComplexNumber &b) {
    return ComplexNumber(a.r + b.r, a.i + b.i);
}
// 這裡就是真正的運算：
    // 把 a 的實部加 b 的實部 (a.r + b.r)
    // 把 a 的虛部加 b 的虛部 (a.i + b.i)

ComplexNumber operator-(const ComplexNumber &a, const ComplexNumber &b) {
    return ComplexNumber(a.r - b.r, a.i - b.i);
}

ComplexNumber operator*(const ComplexNumber &a, const ComplexNumber &b) {
    float real= a.r * b.r - a.i * b.i;
    float imag = a.i * b.r + a.r * b.i;
    return ComplexNumber(real, imag);
}

ComplexNumber operator/(const ComplexNumber &a, const ComplexNumber &b) {
    float denominator = b.r * b.r + b.i * b.i;
    if (denominator == 0) {
        cout << "\n[錯誤] 除數不能為零！返回預設值 0。\n";
        return ComplexNumber(0, 0);
    }
    float realPart = (a.r * b.r + a.i * b.i) / denominator;
    float imagPart = (a.i * b.r - a.r * b.i) / denominator;
    return ComplexNumber(realPart, imagPart);
}

bool operator==(const ComplexNumber &a, const ComplexNumber &b) {
    return (a.r == b.r && a.i == b.i);
}

bool operator!=(const ComplexNumber &a, const ComplexNumber &b) {
    return !(a == b);
}

int main() {
    ComplexNumber a(3, 4);
    ComplexNumber b(1, -2);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "a + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a * b = " << (a * b) << endl;
    cout << "a / b = " << (a / b) << endl;

    cout << "a == b 結果: " << (a == b ? "相同" : "不同") << endl;
    cout << "a != b 結果: " << (a != b ? "不同" : "相同") << endl;

    return 0;
}
