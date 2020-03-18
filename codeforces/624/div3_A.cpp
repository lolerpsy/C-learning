#include<cstdio>
using namespace std;
int f(int a,int b){
    if(a==b) return 0;
    if(a>b) return (a-b)%2==0?1:2;
    return (b-a)%2==1?1:2;
}
int main(){
    int n;
    scanf("%d",&n);
    int a,b;
    while(n--){
        scanf("%d %d",&a,&b);
        printf("%d\n",f(a,b));
    }
    return 0;
}