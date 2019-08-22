#include<cstdio>
using namespace std;
int a[200010];
int main(){
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int cnt=0,begin=0;
    int ans;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int t;
        scanf("%d",&t);
        if(cnt==(n+m+1)/2) continue;
        for(int j=begin;j<n && cnt<(n+m+1)/2;j++){
            if(a[j]<t){
                ans=a[j];
                cnt++;
                begin=j+1;
            }else{
                begin=j;
                break;
            }
        }
        if(cnt<(n+m+1)/2){
            ans=t;
            cnt++;
        }
    }
    while(cnt<(n+m+1)/2){
        ans=a[begin++];
        cnt++;
    }

    printf("%d",ans);

    return 0;
}

//3 1 2 3
//2 5 6
