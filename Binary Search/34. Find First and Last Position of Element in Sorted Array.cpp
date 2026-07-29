class Solution {
public:
int lb(vector<int>&nums,int t)
{
    int low=0;
    int high=nums.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]>=t)
        {
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;
}
int ub(vector<int>&nums,int t)
{
    int low=0;
    int high=nums.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]>t)
        {
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        int l=lb(nums,target);
        if(l==nums.size() || nums[l]!=target) return {-1,-1};
        else return{l,ub(nums,target)-1};
    }
};
