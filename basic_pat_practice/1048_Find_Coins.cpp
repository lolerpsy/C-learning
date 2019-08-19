#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int hash[1010]={0};//m-i会超出500，所以要开大小为1001以上的数组
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        hash[t]++;
    }

    bool solution=false;
    for(int i=1;i<=m/2;i++){
        if((hash[i]!=0 && hash[m-i]!=0 && i!=m-i) || (i==m-i && hash[i]>=2)){
            printf("%d %d",i,m-i);
            solution=true;
            break;
        }
    }

    if(!solution) printf("No Solution\n");

    return 0;
}
