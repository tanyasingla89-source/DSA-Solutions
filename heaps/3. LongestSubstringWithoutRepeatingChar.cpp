class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int maxlen=0;
        map<char,int>mp;
        while(r<s.size())
        {
            if(mp.count(s[r])>0 && mp[s[r]]>=l)
            {
                l=mp[s[r]]+1;
            }
            mp[s[r]]=r;
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};
