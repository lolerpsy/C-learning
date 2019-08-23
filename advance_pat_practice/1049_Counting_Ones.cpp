#include<cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int ans=0,a=1,left,mid,right;
    while(n/a){
        left=n/a/10;
        right=n%a;
        mid=n/a%10;

        if(mid==0) ans+=left*a;
        else if(mid==1) ans+=left*a+right+1;
        else ans+=(left+1)*a;
        a*=10;
    }

    printf("%d",ans);
}
