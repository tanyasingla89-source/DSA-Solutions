class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int count=0;
        int sum=0;
        for(int j=0;j<nums.size();j++)
        {
            sum+=nums[j];
            if(mp.count(sum-k))
            {
                count+=mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
};
