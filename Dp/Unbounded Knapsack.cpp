class Solution {
public:
    int find(vector<int>& wt, vector<int>& val, int i, int W, vector<vector<int>>& dp)
    {
        if(i == 0)
        {
            return (W / wt[0]) * val[0];
        }
        
        if(dp[i][W] != -1) return dp[i][W];
        
        int notTake = find(wt, val, i-1, W, dp);
        int take = INT_MIN;
        if(wt[i] <= W)
        {
            take = val[i] + find(wt, val, i, W - wt[i], dp);   // stays at i — unbounded
        }
        
        return dp[i][W] = max(take, notTake);
    }
    
    int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return find(wt, val, n-1, W, dp);
    }
};
