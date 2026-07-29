class Solution {
public:
int floor(vector<int> nums, int x)
{
    int ans=-1;
    int low=0;
    int high=nums.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]<=x)
        {
            ans=nums[mid];
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int ceil(vector<int> nums, int x)
{
    int ans=-1;
    int low=0;
    int high=nums.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]>=x)
        {
            ans=nums[mid];
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
   int lb=floor(nums,x);
   int ub=ceil(nums,x);
   return {lb,ub};
    }
};
