class Solution {
public:
void solve(string s,unordered_set<string>&dict,vector<string>&ans,string c,int start)
{
    if(start==s.length())
    {
        ans.push_back(c);
        return;
    }
    string word="";
    for(int i=start;i<s.length();i++)
    {
        word+=s[i];
        if(dict.count(word))
        {
            string next=c.empty()?word:c+" "+word;
            solve(s,dict,ans,next,i+1);
        }
    }
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        vector<string>ans;
        solve(s,dict,ans,"",0);
        return ans;
    }
};
