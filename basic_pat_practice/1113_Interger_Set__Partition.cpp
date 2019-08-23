#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

int a[100010];
int main(){
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    sort(a,a+n);
    int left=0,right=n-1;
    int ans1,ans2=0;
    ans1=n%2;
    while(left<right){
        ans2+=a[right]-a[left];
        left++;
        right--;
    }
    if(ans1) ans2+=a[left];

    printf("%d %d",ans1,ans2);

    return 0;
}
