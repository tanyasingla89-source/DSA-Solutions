class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int len1=strs[0].length();
        int len2=strs[strs.size()-1].length();
        int j=0;
        while(j<len1 && j<len2)
        {
            if(strs[0][j]==strs[strs.size()-1][j])
            {
                j++;
            }
            else 
            {
                break;
            }
        }
        return strs[0].substr(0,j);
    }
};
