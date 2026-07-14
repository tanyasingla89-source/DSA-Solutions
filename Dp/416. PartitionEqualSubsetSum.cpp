class Solution {
public:
bool find(vector<int>& nums,int target,int i,vector<vector<int>>&dp)
{
    if(target==0) return true;
    if(i==0) return (nums[0]==target);
    if(dp[i][target]!=-1) return dp[i][target];
    bool np=find(nums,target,i-1,dp);
    bool p=false;
    if(target>=nums[i]){
        p=find(nums,target-nums[i],i-1,dp);
    }
    return dp[i][target]=p || np;
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        int n=nums.size();
        if(sum%2==1) return false;
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        return find(nums,sum/2,n-1,dp);
    }
};
