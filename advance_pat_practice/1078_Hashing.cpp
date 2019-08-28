#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;



int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    if( m==1 ) m=2;//1要特判为非素数，第二个测试点
    else{
        while(1){
            bool isprime=true;
            for(int i=2;i*i<=m;i++){
                if(m%i==0){
                    isprime=false;
                    break;
                }
        }
        if(isprime) break;
        m++;
        }
    }

    vector<int> hash(m,-1);//声明hash表，初始化为-1

    int pcnt=0;
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        int key=t%m;
        int d=0;
        bool in=false;
        while(d<m){//可以证明，如果d在0-m之间没有找到，那么在任意整数都找不到空位
            if(hash[(key+d*d)%m]==-1){
                hash[(key+d*d)%m]=t;
                in=true;
                break;
            }
            d++;
        }
        if(in){//输出
            if(pcnt) printf(" ");
            printf("%d",(key+d*d)%m);
            pcnt++;
        }else{
            if(pcnt) printf(" ");
            printf("-");
            pcnt++;
        }
    }

    return 0;
}
