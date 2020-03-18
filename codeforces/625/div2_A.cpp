#include<bits/stdc++.h>
using namespace std;
int main(){
    int r[105],b[105];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&r[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    int ans1=0,ans2=0;
    for(int i=0;i<n;i++){
        if(r[i]==b[i]) continue;
        else if(r[i]==1) ans1++;
        else ans2++;
    }
    if(ans1==ans2 && ans2==0) printf("-1");
    else if(ans1==0) printf("-1");
    else if(ans1>ans2) printf("1");
    else {
        if((ans2+1) %ans1==0) printf("%d",(ans2+1)/ans1);
        else printf("%d",(ans2+1)/ans1+1);
    }
    return 0;
}