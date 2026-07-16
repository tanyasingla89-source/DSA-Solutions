class Solution {
public:
int find(int i,int target,vector<int>& coins,vector<vector<int>>&dp)
{
    if(target==0) return 1;
    if(i<0) return 0;
    if(dp[i][target]!=-1) return dp[i][target];
    int np=find(i-1,target,coins,dp);
    int p=0;
    if(coins[i]<=target)
    {
        p=find(i,target-coins[i],coins,dp);
    }
    return dp[i][target]=p+np;
}
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return find(coins.size()-1,amount,coins,dp);
    }
};
