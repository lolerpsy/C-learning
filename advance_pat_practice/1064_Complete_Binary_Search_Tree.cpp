#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[1010],CBT[1010];
int getlsize(int l){
    int fac=1;
    while(fac-1<l){
        fac*=2;
    }
    if(fac-1==l) return fac/2-1;
    else{
        if(fac-1-l<=fac/2/2) return fac/2-1;
        else return l-(fac/2-1) + fac/2/2-1;
    }
}
void create(int start,int end, int root){
    int l=end-start+1;
    if(l==0) return;
    int lsize = getlsize(l);
    CBT[root] = a[start + lsize];
    create(start,start+lsize-1,root*2+1);
    create(start+lsize+1,end,root*2+2);
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n,less<int>());
    create(0,n-1,0);
    for(int i=0;i<n;i++){
        if(i) printf(" ");
        printf("%d",CBT[i]);
    }
    return 0;
}
