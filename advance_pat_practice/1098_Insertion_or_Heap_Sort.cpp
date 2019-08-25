#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int n;
    int a[105],b[105];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    int cnt=0;
    for(int i=1;i<n;i++){
        if(b[i]<b[i-1]){
            cnt=i;
            break;
        }
    }
    int j;
    for(j=cnt;j<n;j++){
        if(a[j]!=b[j]){
            break;
        }
    }

    if(j==n){
        printf("Insertion Sort\n");
        sort(a,a+cnt+1);
        for(int i=0;i<n;i++){
            if(i) printf(" ");
            printf("%d",a[i]);
        }
    }else{
        printf("Heap Sort\n");
        int i;
        sort(a,a+n);
        for(i=n-1;i>=0;i--){
            if(b[i]!=a[i]) break;
        }

        pop_heap(b,b+i+1);

        for(int k=0;k<n;k++){
            if(k) printf(" ");
            printf("%d",b[k]);
        }
    }

    return 0;
}
