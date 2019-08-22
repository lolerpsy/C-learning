#include<algorithm>
#include<cstdio>
#include<iostream>
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
    
    int firstunsort=0;
    for(int i=1;i<n;i++){
        if(b[i]<b[i-1]){
            firstunsort=i;
            break;
        }
    }
    bool isinsert=true;
    for(int i=firstunsort;i<n;i++){
        if(a[i]!=b[i]){
            isinsert=false;
            break;
        }
    }

    if(isinsert){
        printf("Insertion Sort\n");
        sort(a,a+firstunsort+1);
    }else{
        printf("Merge Sort\n");
        int k=1;
        while(true){
            bool same=true;
            for(int i=0;i<n;i++){
                if(a[i]!=b[i]){
                    same=false;
                    break;
                }
            }
            k*=2;
            for(int i=0;i<n/k;i++){
                sort(a+i*k,a+i*k+k);
            }
            sort(a+n/k*k,a+n);
            if(same) break;
        }
    }
    for(int i=0;i<n;i++){
        if(i) printf(" ");
        printf("%d",a[i]);
    }

    return 0;
}
