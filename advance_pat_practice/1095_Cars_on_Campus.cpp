#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

typedef struct record{
    int hh,mm,ss,time;
    string plate;
    bool status;
}rec;

rec re[10010];
int a[90000];

bool comp(rec a,rec b){
    if(a.plate!=b.plate) return a.plate<b.plate;
    else return a.time<b.time;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        cin>>re[i].plate;
        scanf("%d:%d:%d",&re[i].hh,&re[i].mm,&re[i].ss);
        re[i].time=re[i].hh*60*60+re[i].mm*60+re[i].ss;
        string line;
        cin>>line;
        if(line=="in") re[i].status=true;
        else re[i].status=false;
    }

    sort(re,re+n,comp);

    int cars[90000]={0};
    map<string,int> m;
    for(int i=1;i<n;i++){
        if(re[i-1].plate==re[i].plate && re[i-1].status==true && re[i].status==false){
            m[re[i].plate]+=(re[i].time-re[i-1].time);
            for(int j=re[i-1].time;j<re[i].time;j++){
                cars[j]++;
            }
        }
    }

    for(int i=0;i<k;i++){
        int h,m,s;
        scanf("%d:%d:%d",&h,&m,&s);
        printf("%d\n",cars[h*60*60+m*60+s]);
    }

    int maxduring=0;
    string maxname;
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second>maxduring){
            maxduring=it->second;
            maxname=it->first;
        }
    }

    cout<<maxname;
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second==maxduring && it->first!=maxname){
            cout<<" "<<it->first;
        }
    }
    printf(" %02d:%02d:%02d",maxduring/3600,maxduring%3600/60,maxduring%60);

    return 0;
}
