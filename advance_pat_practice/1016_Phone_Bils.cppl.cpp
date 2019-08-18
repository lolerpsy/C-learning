#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

typedef struct record{
    int mm,dd,hh,mi,time;
    string name;
    bool on;
}rec;

bool comp(rec a,rec b){
    if(a.name!=b.name) return a.name<b.name;
    else return a.time<b.time;
}

int price[24];

int pricecal(int a1,int a2,int a3,int b1,int b2,int b3){
    int sum1=0,sum2=0;
    int priceday=0;
    for(int i=0;i<24;i++){
        priceday+=60*price[i];
    }
    for(int i=0;i<a2;i++){
        sum1+=60*price[i];
    }
    sum1+=a3*price[a2];
    for(int i=0;i<b2;i++){
        sum2+=60*price[i];
    }
    sum2+=b3*price[b2];

    int result=(b1-a1)*priceday+sum2-sum1;

    return result;
}

int main(){
    for(int i=0;i<24;i++){
        scanf("%d",&price[i]);
    }

    int n;
    scanf("%d",&n);

    rec re[1010];
    for(int i=0;i<n;i++){
        string line;
        cin>>re[i].name;
        scanf("%d:%d:%d:%d",&re[i].mm,&re[i].dd,&re[i].hh,&re[i].mi);
        cin>>line;
        if(line=="on-line") re[i].on=true;
        else re[i].on=false;
        re[i].time=re[i].dd*24*60+re[i].hh*60+re[i].mi;
    }

    sort(re,re+n,comp);
    map<string,vector<rec> >m;
    for(int i=1;i<n;i++){
        if(re[i].name==re[i-1].name && re[i-1].on==true && re[i].on==false){
            m[re[i].name].push_back(re[i]);
            m[re[i].name].push_back(re[i-1]);
        }
    }

    for(auto it : m){
        vector<rec> temp;
        temp=it.second;
        cout<<it.first;
        printf(" %02d\n",temp[0].mm);
        int sum=0;
        for(int i=1;i<temp.size();i+=2){
            int t=(-1)*pricecal(temp[i-1].dd,temp[i-1].hh,temp[i-1].mi,temp[i].dd,temp[i].hh,temp[i].mi);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",temp[i].dd,temp[i].hh,temp[i].mi,temp[i-1].dd,temp[i-1].hh,temp[i-1].mi,temp[i-1].time-temp[i].time,t/100.0);
            sum+=t;
        }
        printf("Total amount: $%.2f\n",sum/100.0);
    }
    return 0;
}
