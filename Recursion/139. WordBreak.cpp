class Solution {
public:
bool solve(string s,unordered_set<string>&dict,vector<int>&memo,int start)
{
    if(start==s.length()) return true;
    if(memo[start]!=-1) return memo[start];
    string word="";
    for(int i=start;i<s.length();i++)
    {
        word+=s[i];
        if(dict.count(word) && solve(s,dict,memo,i+1))
        {
            return memo[start]=true;
        }
    }
    return memo[start]=false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        vector<int>memo(s.length(),-1);
        return solve(s,dict,memo,0);
    }
};
