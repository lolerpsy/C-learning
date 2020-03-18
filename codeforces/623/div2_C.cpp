#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t,b[100],re[210],a[210];
    scanf("%d",&t);
    while(t--){
        fill(re,re+210,0);
        int n,maxb=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&b[i]);
            re[b[i]]=1;
            if(b[i]>maxb) maxb=b[i];
        }
        if(maxb>=n*2) printf("-1\n");
        else{
            int cnt=0;
            bool ans=true;
            for(int i=0;i<n;i++){
                a[cnt++]=b[i];
                bool flag=false;
                for(int j=1;j<=2*n;j++){
                    if(re[j]==0 && j>b[i]){
                        re[j]=1;
                        a[cnt++]=j;
                        flag=true;
                        break;
                    }
                }
                if(!flag){
                    ans=false;
                    break;
                }
            }
            if(!ans) printf("-1\n");
            else{
                for(int i=0;i<n*2;i++){
                    if(i!=0) printf(" ");
                    printf("%d",a[i]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}