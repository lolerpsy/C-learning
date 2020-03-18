#include <bits/stdc++.h>
typedef long long ll;
inline int lowbit(int x){return x&(-x);}
using namespace std;
int gcd(int a,int b){
    int t;
    while(a!=0){
        t=a;
        a=b%a;
        b=t;
    }
    return b;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int x;
        scanf("%d",&x);
        for(int i=1;i<x;i++){
            bool find=false;
            if(x%i==0){
                int l=x/i-1;
                for(int j=1;j<=l;j++){
                    if(l%j==0&&gcd(l/j,j)==1){
                        printf("%d %d\n",j*i,l/j*i);
                        find=true;
                        break;
                    }
                }
            }
            if(find) break;
        }
    }
    return 0;
}
