class Solution {
public:
int findmax(vector<int>& bloomDay)
{
    int maxi=INT_MIN;
    for(int i=0;i<bloomDay.size();i++)
    {
        maxi=max(maxi,bloomDay[i]);
    }
    return maxi;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=findmax(nums);
        while(low<=high)
        {
            int sum=0;
            int mid=(low+high)/2;
            for(int i=0;i<nums.size();i++)
            {
                sum=sum+(nums[i]+mid-1)/mid;
            }
            if(sum<=threshold)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};
