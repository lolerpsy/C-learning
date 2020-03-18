#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=nums[0],tempmax=0;
        for(int i=0;i<nums.size();i++){
            tempmax=tempmax+nums[i]>nums[i]?tempmax+nums[i]:nums[i];
            maxsum=max(tempmax,maxsum);
        }
        return maxsum;
    }
};
int main(){
    Solution s;
    vector<int> nums={-2};
    printf("%d",s.maxSubArray(nums));
    return 0;
}