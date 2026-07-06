class Solution {
public:
bool ispalin(string s)
{
    string s1=s;
    reverse(s1.begin(),s1.end());
    return s==s1;
}
void getprint(string s,vector<vector<string>>&ans,vector<string>&partitons)
{
    if(s.size()==0)
    {
        ans.push_back(partitons);
        return;
    }
    for(int i=0;i<s.size();i++)
    {
        string part=s.substr(0,i+1);
        if(ispalin(part))
        {
            partitons.push_back(part);
            getprint(s.substr(i+1),ans,partitons);
            partitons.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>partitons;
        getprint(s,ans,partitons);
        return ans;

    }
};
