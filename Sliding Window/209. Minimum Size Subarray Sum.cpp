class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int r=0;
        int minlen=nums.size()+1;
        int sum=0;
        while(r<nums.size())
        {
            sum+=nums[r];
            while(sum>=target)
            {
                minlen=min(minlen,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return (minlen==nums.size()+1?0:minlen);
    }
};
