#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        bool flag=true;
        int t,re[1010]={0},re1[1010]={0},re3[2020]={0};
        scanf("%d",&t);
        for(int j=1;j<=t;j++){
            int temp;
            scanf("%d",&temp);
            re[temp]++;
            re1[temp-j]++;
            re3[temp+1]++;
        }
        for(int j=0;j<=t;j++){
            if(re[j]>=2 || re1[j]>=2){
                flag=false;
                break;
            }
        }
        for(int j=0;j<2020;j++){
            if(re3[j]>=2){
                flag=false;
                break;
            }
        }
        printf("%s",flag?"YES\n":"NO\n");
    }

    return 0;
}
