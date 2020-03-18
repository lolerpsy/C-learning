#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void init(string &s){
    s='#'+s+'#';
    for(int i=2;i<s.length()-1;i+=2){
        s.insert(i,1,'#');
    }
}
int manacher(string s){
    init(s);
    int len=s.length();
    vector<int> p(len);
    int mr=0,c=0;
    int ans=0;
    for(int i=0;i<s.length();i++){
        if(i<=mr){
            p[i]=min(p[2*c-i],mr-i);
        }else p[i]=0;
        while(i+p[i]<s.length() && i-p[i]>=0 && s[i+p[i]]==s[i-p[i]]){
            p[i]++;
        }
        if(i+p[i]-1>mr){
            c=i;
            mr=i+p[i]-1;
        }
        if(p[i]>ans) ans=p[i];
    }
    return ans/2;
}
int main(){
    string s;
    cin>>s;
    int ans=manacher(s);
    cout<<ans<<endl;
    return 0;
}
