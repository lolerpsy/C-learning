#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct factornum{//声明分数结构体
    int up,down;
}fnum;

int gcd(int a,int b){//辗转相余求最大公约数
    int t;
    while(a!=0){
        t=a;
        a=b%a;
        b=t;
    }
    return b;
}

fnum simplify(fnum a){//约分函数
    int g=gcd(abs(a.up),abs(a.down));
    if(a.up==0) {
        a.down=1;
        return a;
    }
    if(g==1) return a;
    else{
        a.up/=g;
        a.down/=g;
    }
    return a;
}

fnum sum1(fnum a,fnum b){//分数求和
    fnum ret;
    ret.up=a.up*b.down+b.up*a.down;
    ret.down=a.down*b.down;
    return simplify(ret);
}

int main(){
    int n;
    scanf("%d",&n);
    fnum sum;
    sum.up=0;
    sum.down=1;
    for(int i=0;i<n;i++){
        fnum t;
        scanf("%d/%d",&t.up,&t.down);
        sum=sum1(sum,t);
    }

    if(sum.up==0) printf("0");//输出分数
    else{
        if(sum.up<0){
            printf("-");
            sum.up=-1*sum.up;
        }
        int g=gcd(sum.up,sum.down);
        if(sum.up/sum.down>0) printf("%d",sum.up/sum.down);
        if(sum.up/sum.down && sum.up%sum.down) printf(" ");
        if(sum.up%sum.down) printf("%d/%d",sum.up%sum.down/g,sum.down/g);
    }

    return 0;
}
