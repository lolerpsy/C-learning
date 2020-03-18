#include<cstdio>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        int ans[1001];
        ans[0]=0;ans[1]=1;ans[2]=2;
        for(int i=3;i<=n;i++){
            ans[i]=ans[i-1]+ans[i-2];
        }
        return ans[n];
    }
};

int main(){
    Solution s;
    printf("%d",s.climbStairs(40));
}