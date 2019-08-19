#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    
    int a[100010];
    int hash[10010]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        hash[a[i]]++;
    }

    bool no=true;
    for(int i=0;i<n;i++){
        if(hash[a[i]]==1){
            printf("%d\n",a[i]);
            no=false;
            break;
        }
    }
    if(no) printf("None\n");

    return 0;
}
