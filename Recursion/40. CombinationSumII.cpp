class Solution {
public:
void print(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&r,int i,int n,int sum)
{
    if(sum>=target)
    {
        if(sum==target)
        {
            ans.push_back(r);
        }
        return;
    }
    for(int j=i;j<n;j++)
    {
        if(j>i && candidates[j]==candidates[j-1]) continue;
        sum+=candidates[j];
        r.push_back(candidates[j]);
        print(candidates,target,ans,r,j+1,n,sum);
        sum-=candidates[j];
        r.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>r;
        sort(candidates.begin(),candidates.end());
        print(candidates,target,ans,r,0,candidates.size(),0);
        return ans;
    }
};
