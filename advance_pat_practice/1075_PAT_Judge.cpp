#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef struct tester{
    bool pass=false;
    int fullnum=0;
    int id;
    int point[5]={-2,-2,-2,-2,-2};
    int total=0;
}user;

bool comp1(user a,user b){
    if(a.total!=b.total) return a.total>b.total;
    else if(a.fullnum!=b.fullnum) return a.fullnum>b.fullnum;
    else return a.id<b.id;
}

int sum1(int a[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        if(a[i]>0) sum+=a[i];
    }
    return sum;
}

int main(){
    int n,k,m;
    int p[5];
    scanf("%d %d %d",&n,&k,&m);

    for(int i=0;i<k;i++){
        scanf("%d",&p[i]);
    }

    user users[10010];
    for(int i=0;i<m;i++){
        int t1,t2,t3;
        scanf("%d %d %d",&t1,&t2,&t3);
        if(users[t1].point[t2-1]!=p[t2-1] && t3==p[t2-1]) users[t1].fullnum++;
        //注意只有第一次提交满分满分次数才加1，最后一个测试点有这个坑
        if(t3>users[t1].point[t2-1]) users[t1].point[t2-1]=t3;
        if(t3>=0) users[t1].pass=true;
    }

    int cnt=0;
    for(int i=1;i<=n;i++){
        users[i].total=sum1(users[i].point,k);
        users[i].id=i;
        if(!users[i].pass) users[i].total=-1;
        else cnt++;
    }

    sort(users+1,users+n+1,comp1);

    int rank=1;
    printf("%d %05d %d",rank,users[1].id,users[1].total);
    for(int i=0;i<k;i++){
        if(users[1].point[i]==-1) printf(" 0");
        else if(users[1].point[i]==-2)printf(" -");
        else printf(" %d",users[1].point[i]);
    }
    printf("\n");
    for(int j=2;j<=cnt;j++){
        if(users[j].total<users[j-1].total) rank=j;
        printf("%d %05d %d",rank,users[j].id,users[j].total);
        for(int i=0;i<k;i++){
            if(users[j].point[i]==-1) printf(" 0");
            else if(users[j].point[i]==-2)printf(" -");
            else printf(" %d",users[j].point[i]);
        }
        printf("\n");
    }

    return 0;
}
