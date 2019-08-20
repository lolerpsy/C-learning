#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int pos[100010];

int main(){
    int n;
    scanf("%d",&n);
    int num=0,left=n-1;
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        pos[t]=i;
        if(t!=0 && pos[t]==t) left--;
    }
    int k=1;
    while(left>0){
        if(pos[0]==0){
            for(int i=k;i<n;i++){
                if(pos[i]!=i){
                    k=i;
                    break;
                }
            }
            swap(pos[0],pos[k]);
            num++;
        }

        while(pos[0]!=0){
            swap(pos[0],pos[pos[0]]);
            left--;
            num++;
        }
    }

    printf("%d\n",num);
}
