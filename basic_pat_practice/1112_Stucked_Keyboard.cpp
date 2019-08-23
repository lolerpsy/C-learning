#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int k;
    cin>>k;
    string s;
    cin>>s;
    s=s+"#";
    int hash[200]={0};
    char now=s[0];
    int nownum=1;
    for(int i=1;i<s.length();i++){
        if(s[i]!=now){
            if(nownum%k==0 && hash[now-0]==0) hash[now-0]=2;
            else if(nownum%k!=0) hash[now-0]=1;
            now=s[i];
            nownum=1;
        }else nownum++;
    }

    bool isprinted[200];
    fill(isprinted,isprinted+200,false);
    for(int i=0;i<s.length()-1;i++){
        if(hash[s[i]-0]==2 && !isprinted[s[i]-0]){
            cout<<s[i];
            isprinted[s[i]-0]=true;
        }
    }
    cout<<"\n";
    for(int i=0;i<s.length()-1;){
        cout<<s[i];
        if(hash[s[i]-0]==1) i++;
        else if(hash[s[i]-0]==2) i+=k;
    }

    return 0;
}
