#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int prime[100010];

int main(){

    fill(prime,prime+100010,1);
    for(int i=2;i<100010;i++){
        if(prime[i]){
            for(int j=2;j*i<100010;j++){
                prime[i*j]=0;
            }
        }
    }

    int n;
    scanf("%d",&n);
    printf("%d=",n);
    if(n==1) printf("1");
    int cntp=0;
    for(int i=2;n>=2;i++){
        int cnt=0,flag=0;
        while(n%i==0 && prime[i]==1){
            cnt++;
            n/=i;
            flag=1;
        }
        if(flag){
            if(cntp) printf("*");
            printf("%d",i);
            cntp++;
        }
        if(cnt>1) printf("^%d",cnt);
    }


    return 0;
}
