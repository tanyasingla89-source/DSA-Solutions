class Solution {
public:
void print(vector<int>& nums,vector<vector<int>>&ans,int i,int n)
{
    if(i==n)
    {
        ans.push_back(nums);
        return;
    }
    for(int j=i;j<n;j++)
    {
        swap(nums[j],nums[i]);
        print(nums,ans,i+1,n);
        swap(nums[j],nums[i]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        print(nums,ans,0,nums.size());
        return ans;
    }
};
