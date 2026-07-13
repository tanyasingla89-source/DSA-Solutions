//Memoisation
class Solution {
  public:
  int f(int i,vector<int>& height,vector<int>&dp)
  {
      if(i==0)return 0;
      if(dp[i]!=-1) return dp[i];
      int l=f(i-1,height,dp)+abs(height[i]-height[i-1]);
      int r=INT_MAX;
      if(i>1)
      {
          r=f(i-2,height,dp)+abs(height[i]-height[i-2]);
      }
      return dp[i]=min(r,l);
  }
    int minCost(vector<int>& height) {
        int n=height.size();
        vector<int>dp(n,-1);
        return f(n-1,height,dp);
        
    }
};
