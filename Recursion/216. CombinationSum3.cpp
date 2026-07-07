class Solution {
public:
void solve(int k, int n,vector<vector<int>>&ans,vector<int>&current,int start)
{
    if(current.size()==k && n==0)
    {
        ans.push_back(current);
        return;
    }
    if(current.size()==k || n<=0)
    {
        return;
    }
    for(int i=start;i<=9;i++)
    {
        current.push_back(i);
        solve(k,n-i,ans,current,i+1);
        current.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>current;
        solve(k,n,ans,current,1);
        return ans;
    }
};
