class Solution {
public:
int lb(vector<int>& nums, int target)
{
    int low=0;
    int high=nums.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]>=target)
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
int ub(vector<int>& nums, int target)
{
    int ans=-1;
    int low=0;
    int high=nums.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]>target)
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low-1;
}
    int countOccurrences(vector<int>& nums, int target) {
        int lbb=lb(nums,target);
        int ubb=ub(nums,target);
        int n=nums.size();
        if(lbb==n || nums[lbb]!=target) return -1;
        return ubb-lbb+1;
    }
};
