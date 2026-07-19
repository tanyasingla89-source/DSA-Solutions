class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int l=0;
        int r=0;
        int maxlen=0;
        int sum=0;
        while(r<nums.size())
        {
            sum+=nums[r];
            while(sum>k && l<=r)
            {
                sum-=nums[l];
                l++;
            }
            if(sum==k)
            {
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};
