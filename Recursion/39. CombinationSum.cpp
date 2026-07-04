class Solution {
public:
void print(vector<int>& candidates, int t,vector<vector<int>>&ans,vector<int>&r,int i,int n,int sum)
{
    if(sum>=t)
    {
        if(sum==t)
        {ans.push_back(r);}
        return;
    }
    for(int j=i;j<n;j++)
    {
        sum+=candidates[j];
        r.push_back(candidates[j]);
        print(candidates,t,ans,r,j,n,sum);
        sum-=candidates[j];
        r.pop_back();
    }
    
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>r;
        print(candidates,target,ans,r,0,candidates.size(),0);
        return ans;
    }
};
