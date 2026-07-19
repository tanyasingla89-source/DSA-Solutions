class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int maxlen=0;
        int noz=0;
        while(r<nums.size())
        {
            if(nums[r]==0)
            {
                noz++;
                while(noz>k)
                {
                    if(nums[l]==0)
                    {
                        noz--;
                    }
                    l++;
                }
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};
