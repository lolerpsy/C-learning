#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
struct customer{
    int time,duration,st;
};
bool comp1(customer a, customer b){
    return a.time < b.time;
}
using namespace std;
int main(){
    int n,k;
    scanf("%d %d",&n, &k);
    customer cus[10010];
    for(int i=0;i<n;i++){
        int a,b,c,d;
        scanf("%d:%d:%d %d",&a,&b,&c,&d);
        cus[i] = {a*3600+b*60+c,d*60,0};
    }
    sort(cus,cus + n,comp1);
    int cnt = 0;
    int totaltime[100] = {0};
    while(cnt < n && cus[cnt].time <= 17*3600){
        int mint = 0xfffffff, minw=-1;
        for(int i=0;i<k;i++){
            if(totaltime[i] < mint){
                mint = totaltime[i];
                minw = i;
            }
        }
        cus[cnt].st = max(cus[cnt].time, 8*3600 + totaltime[minw]);
        totaltime[minw] = cus[cnt].st + cus[cnt].duration - 8*3600;
        cnt++;
    }
    int sumt = 0;
    for(int i=0;i<cnt;i++){
        sumt += (cus[i].st - cus[i].time);
    }
    printf("%.1lf",sumt/60.0/cnt);
    return 0;
}
