class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=nums[0];
        int cnt=1;
        for(int i=1;i<nums.size();i++)
        {
            if(cnt==0)
            {
                c=nums[i];
                cnt=1;
            }
            else if(nums[i]==c)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        return c;
    }
};
