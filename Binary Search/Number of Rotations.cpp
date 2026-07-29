class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int low=0;
        int high=nums.size()-1;
        while(low<high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>nums[high])
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }return low;
    }
};
