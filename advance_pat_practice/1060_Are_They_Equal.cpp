#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int format1(string &s, int k) {
    while (s.length() > 1 && s[0] == '0' && s[1] != '.')
        s = s.substr(1); //去除多余的0，不然有两个测试点通不过
    int exp = 0;
    int pos = s.find('.');
    if (pos == -1) {      //没有小数点时
        exp = s.length(); //直接在前面加上0.，阶数等于位数
        s = "0." + s;
        if (s.length() < k + 2) { //不足k位则在最后面天0，多余k位小数时取前k位
            s.insert(s.length(), k + 2 - s.length(), '0');
        } else {
            s = s.substr(0, k + 2);
        }
        if (s[2] == '0') //把0的阶数始终置为0
            exp = 0;
    } else {               //有小数点时
        if (s[0] == '0') { //当第一位是0时
            while (s[2] == '0' &&
                   s.length() > 3) { //当小数点后第一位是0时，就左移，阶数减一
                s = "0." + s.substr(3);
                exp--;
            }
            if (s[2] == '0') //把0的阶数置为0
                exp = 0;
            if (s.length() < k + 2) { //调整小数点后的位数
                s.insert(s.length(), k + 2 - s.length(), '0');
            } else {
                s = s.substr(0, k + 2);
            }
        } else { //当第一位不是0时，需要右移，相对而言就是把小数点向前移动，每移动以为，阶数加一
            for (auto it = pos; it > 0; it--) {
                exp++;
                swap(s[it], s[it - 1]);
            }
            s = '0' + s;
            if (s.length() < k + 2) { //调整小数点后的位数
                s.insert(s.length(), k + 2 - s.length(), '0');
            } else {
                s = s.substr(0, k + 2);
            }
        }
    }

    return exp;//返回阶数
}

int main() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    int exp1 = format1(a, n);
    int exp2 = format1(b, n);
    if (a == b && exp1 == exp2)// 字符串和阶数同时相等才判定两个数字相等
        cout << "YES " << a << "*10^" << exp1 << endl;
    else
        cout << "NO " << a << "*10^" << exp1 << " " << b << "*10^" << exp2
             << endl;
    return 0;
}
