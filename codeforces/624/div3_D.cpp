#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int t,a,b,c,A,B,C;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&a,&b,&c);
        int ans=0x3fffffff;
        for(int i=1;i<10001;i++){
            for(int j=i;j<20002;j+=i){
                for(int k=j;k<40004;k+=j){
                    if(abs(a-i)+abs(b-j)+abs(c-k)<ans){
                        ans=abs(a-i)+abs(b-j)+abs(c-k);
                        A=i;B=j;C=k;
                    }
                }
            }
        }
        printf("%d\n%d %d %d\n",ans,A,B,C);
    }

    return 0;
}