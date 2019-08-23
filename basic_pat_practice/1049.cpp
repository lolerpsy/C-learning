#include<cstdio>
using namespace std;

int main(){
    int n;
    double sum=0.0,temp=0.0;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%lf",&temp);
        sum+=temp*i*(n-i+1);
    }

    printf("%.2lf",sum);

    return 0;
}
