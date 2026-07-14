class Solution {
public:
int find(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp)
{
    if(i==0 && j==0) return grid[0][0];
    if(i<0 || j<0) return INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    int up = INT_MAX, left = INT_MAX;
    if(i>0) up=grid[i][j]+find(grid,i-1,j,dp);
    if(j>0) left=grid[i][j]+find(grid,i,j-1,dp);
    return dp[i][j]=min(left,up);
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return find(grid,m-1,n-1,dp);
    }
};
