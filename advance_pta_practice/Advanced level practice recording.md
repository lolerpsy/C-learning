# PAT Advanced level Practice recording


<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [1001 A+B Format(20)](#1001-ab-format20)
- [1002 A+B for Polynomials(25)](#1002-ab-for-polynomials25)
- [1019 General Palindromic Number(20)](#1019-general-palindromic-number20)
- [1027 Colors in Mars(20)](#1027-colors-in-mars20)
- [1035 Password(20)](#1035-password20)
- [1058 A+B in Hogwarts(20)](#1058-ab-in-hogwarts20)

<!-- /code_chunk_output -->

##1001 A+B Format(20)

Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input Specification:
Each input file contains one test case. Each case contains a pair of integers a and b where $−10^6≤a,b≤10^6$. The numbers are separated by a space.

Output Specification:
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input:

    -1000000 9
Sample Output:

    -999,991

基本思路：转化为字符串，按个输出。具体代码如下：

```C++ {class=line-numbers}
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char *argv[])
{
    int a, b;
    cin >> a >> b;
    string s = to_string(abs(a + b));
    if(a+b<0)
    {
        printf("-");
    }

    for (int i = 0; i < s.length(); i ++)
    {
        printf("%c", s[i]);
        if((i%3)==((s.length()-1)%3) && i!=(s.length()-1))
        {
            printf(",");
        }
    }

    return 0;
}
```

---

##1002 A+B for Polynomials(25)

This time, you are supposed to find A+B where A and B are two polynomials.

Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:
​​$K N_1 a_{N_1} N_2 a_{N_2}...N_K a_{N_K}$

where K is the number of nonzero terms in the polynomial, $N_i$ and $a_{N_i}$ are the exponents and coefficients, respectively. It is given that $1≤K≤10$，$0≤N_k<...<N_2<N_1\leq1000$.

Output Specification:
For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input:

    2 1 2.4 0 3.2
    2 2 1.5 1 0.5
Sample Output:

    3 2 1.5 1 2.9 0 3.2

多项式加法是经典的链表应用，虽然本题可以使用数组使代码简单易懂，但是这里还是提供vector写的的链表代码，有意复习数据结构知识的读者可以看一看。具体代码如下：

解法一(数组解法)：

``` C++ {class=line-numbers}
#include <cstdio>
using namespace std;

int main()
{
    const float delta = 1e-7;
    float a[1100] = {0};
    int number;
    int cnt = 0;
    int tempi;
    float temp;
    for (int i = 0; i < 2;i++){
        scanf("%d", &number);
        for (int j = 0; j < number;j++){
            scanf("%d %f", &tempi,&temp);
            a[tempi] += temp;
        }
    }

    for (int i = 0; i < 1100;i ++){
        if(a[i])
        {
            cnt++;
        }
    }

    printf("%d", cnt);

    for (int i = 1099; i >=0; i -- ){
        if(a[i]>delta || a[i]<(-1*delta)){
            printf(" %d %.1f", i ,a[i]);
        }

    }
        return 0;
}
```

解法二(使用vector)：

``` C++ {class=line-numbers}
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

struct poly
{
    float cof;
    int exp;
};

const float delta = 1e-7;

int main(int argc, const char *argv[])
{
    vector<poly> p1, p2, pp;
    int number1, number2;
    scanf("%d", &number1);
    poly temp;
    for (int i = 0; i < number1; i++)
    {
        scanf("%d %f", &temp.exp, &temp.cof);
        p1.push_back(temp);
    }

    scanf("%d", &number2);
    for (int i = 0; i < number2; i++)
    {
        scanf("%d %f", &temp.exp, &temp.cof);
        p2.push_back(temp);
    }

    auto it1 = p1.begin();
    auto it2 = p2.begin();
    while (it1 != p1.end() && it2 != p2.end())
    {
        if (it1->exp > it2->exp)
        {
            pp.push_back(*it1);
            it1++;
        }
        else if (it1->exp < it2->exp)
        {
            pp.push_back(*it2);
            it2++;
        }
        else
        {
            if ((it1->cof + it2->cof) <= delta)
            {
                it2++;
                it1++;
            }
            else
            {
                it1->cof += it2->cof;
                pp.push_back(*it1);
                it1++;
                it2++;
            }
        }
    }

    while (it1 != p1.end())
    {
        pp.push_back(*it1);
        it1++;
    }

    while(it2!=p2.end())
    {
        pp.push_back(*it2);
        it2++;
    }

    printf("%zu", pp.size());
    if (pp.size())
    {
        printf(" ");
    }
    for (int i = 0; i < pp.size(); i++)
    {
        printf("%d %.1f", pp[i].exp, pp[i].cof);
        if (i < pp.size() - 1)
        {
            printf(" ");
        }
    }

    return 0;
}

```

---

## 1019 General Palindromic Number(20)

原题地址：<https://pintia.cn/problem-sets/994805342720868352/problems/994805487143337984>

A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.

Although palindromic numbers are most often considered in the decimal system, the concept of palindromicity can be applied to the natural numbers in any numeral system. Consider a number $N>0$ in base $b≥2$, where it is written in standard notation with k+1 digits a i as $\sum_{i=0}^k(a_ib^i)$. Here, as usual, $0 ≤ a_i < b$ for all $i$ and $a_k$ is non-zero. Then N is palindromic if and only if $a_i=a_k−i$ for all $i$. Zero is written 0 in any base and is also palindromic by definition.

Given any positive decimal integer $N$ and a base b, you are supposed to tell if $N$ is a palindromic number in base $b$.

Input Specification:
Each input file contains one test case. Each case consists of two positive numbers $N$ and b, where $0<N≤10$ is the decimal number and 2≤b≤10 is the base. The numbers are separated by a space.

Output Specification:
For each test case, first print in one line Yes if $N$ is a palindromic number in base b, or No if not. Then in the next line, print $N$ as the number in base b in the form $a_ka_{k−1}...a_0$. Notice that there must be no extra space at the end of output.

Sample Input 1:

    27 2

Sample Output 1:
    Yes
    1 1 0 1 1

Sample Input 2:

    121 5

Sample Output 2:

    No
    4 4 1



进制转换之后再判断回文数，比较简单。本题用string字符串有两个点过不了，显示格式错误，不知道为什么。

*注意*：n为零的时候也是回文数字，需要特判。

具体代码如下：

```C++ {class=line-numbers}

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, b;
    scanf("%d %d", &n, &b);
    int a[100]={0};//肯定不超过100位数，可以更小，懒得算了
    int index=0;
    while(n!=0){ //进制转换的常用模板
        a[index++]=n%b;
        n/=b;
    }
    bool isp=true;
    for(int i=0;i<index/2;i++){ //回文数的判断
        if(a[i]!=a[index-i-1]){
            printf("No\n");
            isp=false;
            break;
        }
    }
    if(isp) printf("Yes\n");
    for(int i=index-1;i>=0;i--){ //倒序输出
        printf("%d",a[i]);
        if(i) printf(" ");
    }
    if(index==0) printf("0");
    return 0;
}
```

---

##1027 Colors in Mars(20)

[原题链接](https://pintia.cn/problem-sets/994805342720868352/problems/994805470349344768)

People in Mars represent the colors in their computers in a similar way as the Earth people. That is, a color is represented by a 6-digit number, where the first 2 digits are for Red, the middle 2 digits for Green, and the last 2 digits for Blue. The only difference is that they use radix 13 (0-9 and A-C) instead of 16. Now given a color in three decimal numbers (each between 0 and 168), you are supposed to output their Mars RGB values.

Input Specification:
Each input file contains one test case which occupies a line containing the three decimal color values.

Output Specification:
For each test case you should output the Mars RGB value in the following format: first output #, then followed by a 6-digit number where all the English characters must be upper-cased. If a single color is only 1-digit long, you must print a 0 to its left.

Sample Input:

    15 43 71

Sample Output:

    #123456

本题属于进制转换问题，需要注意的是，无论给出的整数是几位数，都需要转换两次。具体代码如下：

```C++ {class=line-numbers}
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(){
    string s="0123456789ABC";
    int a[3];
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    printf("#");
    for(int i=0;i<3;i++){
        printf("%c",s[a[i]/13%13]);//先高位再低位
        printf("%c",s[a[i]%13]);
    }
    return 0;
}
```

---

## 1035 Password(20)

To prepare for PAT, the judge sometimes has to generate random passwords for the users. The problem is that there are always some confusing passwords since it is hard to distinguish 1 (one) from l (L in lowercase), or 0 (zero) from O (o in uppercase). One solution is to replace 1 (one) by @, 0 (zero) by %, l by L, and O by o. Now it is your job to write a program to check the accounts generated by the judge, and to help the juge modify the confusing passwords.

Input Specification:
Each input file contains one test case. Each case contains a positive integer N (≤1000), followed by N lines of accounts. Each account consists of a user name and a password, both are strings of no more than 10 characters with no space.

Output Specification:
For each test case, first print the number M of accounts that have been modified, then print in the following M lines the modified accounts info, that is, the user names and the corresponding modified passwords. The accounts must be printed in the same order as they are read in. If no account is modified, print in one line ==There are N accounts and no account is modified== where N is the total number of accounts. However, if N is one, you must print ==There is 1 account and no account is modified== instead.

Sample Input 1:

    3
    Team000002 Rlsp0dfa
    Team000003 perfectpwd
    Team000001 R1spOdfa

Sample Output 1:

    2
    Team000002 RLsp%dfa
    Team000001 R@spodfa

Sample Input 2:

    1
    team110 abcdefg332

Sample Output 2:

    There is 1 account and no account is modified



## 1058 A+B in Hogwarts(20)

[原题链接](https://pintia.cn/problem-sets/994805342720868352/problems/994805416519647232)

If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." Your job is to write a program to compute A+B where A and B are given in the standard form of Galleon.Sickle.Knut (Galleon is an integer in $[0,10^7]$, Sickle is an integer in $[0, 17)$, and Knut is an integer in $[0, 29)$).

Input Specification:
Each input file contains one test case which occupies a line with A and B in the standard form, separated by one space.

Output Specification:
For each test case you should output the sum of A and B in one line, with the same format as the input.

Sample Input:

    3.2.1 10.16.27

Sample Output:

    14.1.28

简单的格式模拟，注意过程中的溢出，使用*long long*存放sum。具体代码如下：

```C++ {class=line-numbers}
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int g1,s1,k1,g2,s2,k2;
    scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
    long long sum=(g1+g2)*17*29+(s1+s2)*29+k1+k2;
    printf("%lld.%lld.%lld",sum/17/29,sum%(17*29)/29,sum%29);
    return 0;
}
```

---

