class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int cur = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(cur<0) cur=nums[i];
            else cur+=nums[i];
            if(cur>sum) sum=cur;
        }
        return sum;
    }
};
