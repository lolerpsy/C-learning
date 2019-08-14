#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int g1,s1,k1,g2,s2,k2;
    scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
    long long sum=(g1+g2)*17*29+(s1+s2)*29+k1+k2;
    printf("%lld.%lld.%lld",sum/17/29,sum%(17*29)/29,sum%29);
    return 0;
}
