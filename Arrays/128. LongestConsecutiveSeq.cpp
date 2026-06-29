class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        int maxcount=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            if(i>0 && nums[i]==nums[i-1]+1)
            {
                count++;
            }
            else
            {
                count=1;
            }
            maxcount=max(maxcount,count);
        }
        return maxcount;
    }
};
