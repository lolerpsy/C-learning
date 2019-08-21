#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;

bool comp(string a,string b){
   return a+b<b+a;
}

int main(){
    string s[10010];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }

    sort(s,s+n,comp);

    bool printed=false;
    for(int i=0;i<n;i++){
        if(stoi(s[i])!=0 && !printed){//当第一个不为零的数出现时才开始输出
            cout<<stoi(s[i]);
            printed=true;
        }else if(printed) cout<<s[i];//输出了第一个不为零的数后全按字面量输出
    }
    if(!printed) cout<<"0";//若没有输出过，则必为零

    return 0;
}
