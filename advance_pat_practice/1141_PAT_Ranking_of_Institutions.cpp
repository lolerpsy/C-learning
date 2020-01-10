#include<cstdio>
#include<string>
#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
struct school{
    int sa,sb,sc,tws,ns;
    string name;
};
void lower1(string &a){
    for(int i=0;i<a.length();i++){
        if(isupper(a[i])) a[i]=tolower(a[i]);
    }
}
bool comp(school a,school b){
    if(a.tws!=b.tws) return a.tws>b.tws;
    else if(a.ns!=b.ns) return a.ns<b.ns;
    else return a.name<b.name;
}
school code[100010];
int main(){
    int n,cnt=1;
    scanf("%d",&n);
    unordered_map<string,int> re;
    for(int i=0;i<n;i++){
        string id,s;
        int g;
        cin>>id>>g>>s;
        lower1(s);
        if(re[s]==0){
            re[s]=cnt;
            code[cnt].name=s;
            if(id[0]=='A') code[cnt].sa=g;
            else if(id[0]=='B') code[cnt].sb=g;
            else code[cnt].sc=g;
            code[cnt].ns=1;
            cnt++;
        }else{
            if(id[0]=='A') code[re[s]].sa+=g;
            else if(id[0]=='B') code[re[s]].sb+=g;
            else code[re[s]].sc+=g;
            code[re[s]].ns++;
        }
    }
    for(int i=1;i<cnt;i++){
        code[i].tws=code[i].sa+(double)code[i].sb/3*2+(double)code[i].sc/2*3;
    }
    sort(code+1,code+cnt,comp);
    cout<<cnt-1<<endl;
    int rank=1;
    cout<<rank<<" "<<code[1].name<<" "<<code[1].tws<<" "<<code[1].ns<<endl;
    for(int i=2;i<cnt;i++){
        if(code[i].tws<code[i-1].tws) rank=i;
        cout<<rank<<" "<<code[i].name<<" "<<code[i].tws<<" "<<code[i].ns<<endl;
    }
    return 0;
}
