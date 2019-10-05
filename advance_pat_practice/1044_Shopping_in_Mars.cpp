#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n,m,a[100010]={0};
    scanf("%d %d",&n, &m);
    for(int i= 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    int sum = 0,begin = 0,minlost = 0x3fffffff;
    bool found = false;
    for(int i = 0; i < n;) {
        sum += a[i];
        if( sum == m) {
            found = true;
            printf("%d-%d\n",begin+1,i+1);
            sum -= a[begin];
            i++;
            begin++;
        }else if(sum > m){
            if(sum - m < minlost){
                minlost = sum - m;
            }
            sum -= a[i];
            sum -= a[begin];
            begin++;
        }else{
            i++;
        }
    }
    if(!found){
        int sum = 0,begin = 0;
        for(int i = 0; i < n;) {
            sum += a[i];
            if( sum == m + minlost) {
                printf("%d-%d\n",begin+1,i+1);
                sum -= a[begin];
                i++;
                begin++;
            }else if(sum > m + minlost){
                sum -= a[i];
                sum -= a[begin];
                begin++;
            }else{
                i++;
            }
        }
    }
    return 0;
}
