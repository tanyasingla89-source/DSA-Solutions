class Solution {
public:
void print(vector<int>& nums,vector<vector<int>>&ans,vector<int>&ds,int i,int n)
{
    ans.push_back(ds);   
    for(int j=i;j<n;j++){
        if(j>i && nums[j]==nums[j-1]) continue;
    ds.push_back(nums[j]);
    print(nums,ans,ds,j+1,n);
    ds.pop_back();
    }

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        print(nums,ans,ds,0,nums.size());
        return ans;
    }
};
