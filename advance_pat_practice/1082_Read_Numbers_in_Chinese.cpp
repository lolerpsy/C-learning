#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

string number[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string de[5]={"Qian","Bai","Shi","Yi","Wan"};

bool iszero(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]!='0') return false;
    }
    return true;
}

int pcnt=0;

void print(string a){
    if(pcnt) cout<<" ";
    cout<<a;
    pcnt++;
}

int main(){
    string s;

    cin>>s;
    if(s[0]=='-') {
        cout<<"Fu ";
        s=s.substr(1);
    }

    while(s.length()!=9) s="0"+s;
    bool f1=false,f2=false,f3=false;
    if(s[0]!='0'){
        print(number[s[0]-'0']);
        print(de[3]);
        f1=true;
    }
    string part2=s.substr(1,4);
    string part3=s.substr(5);
    // cout<<part2<<part3<<endl;

    bool lastiszero=0;
    if(f1 && part2[0]=='0' && (!iszero(part2) || !iszero(part3))) print(number[0]);
    for(int i=0;i<4;i++){
        if(part2[i]!='0') f2=true;
        if(f2) {
            if(lastiszero && part2[i]=='0') continue;
            print(number[part2[i]-'0']);
            if(i<3 && part2[i]!='0') print(de[i]);
            if(part2[i]=='0') lastiszero=1;
            else lastiszero=0;
            if(iszero(part2.substr(i+1))) break;
        }
    }
    if(f2) print(de[4]);

    lastiszero=0;
    if(part3[0]=='0' && f2 && !iszero(part3)) print(number[0]);
    for(int i=0;i<4;i++){
        if(part3[i]!='0') f3=true;
        if(f3) {
            if(lastiszero && part3[i]=='0') continue;
            print(number[part3[i]-'0']);
            if(i<3 && part3[i]!='0') print(de[i]);
            if(part3[i]=='0') lastiszero=1;
            if(iszero(part3.substr(i+1))) break;
        }
    }
    if(!f1 && !f2 && !f3){
        print(number[0]);
    }

    return 0;
}
//本题并不难，写的时候却很难受，不知是哪里出了问题。还需多加练习！！
/*
目标：
    1.把重复内容写入外部函数
    2.把判断条件弄得更清晰一些
*/
