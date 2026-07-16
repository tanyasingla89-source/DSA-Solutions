class Solution {
public:
    int find(string& word1, string& word2, int i, int j, vector<vector<int>>& dp)
    {
        if(i < 0) return j+1;   // word1 exhausted, insert remaining j+1 chars
        if(j < 0) return i+1;   // word2 exhausted, delete remaining i+1 chars
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(word1[i] == word2[j])
            return dp[i][j] = find(word1, word2, i-1, j-1, dp);
        
        int insertOp = 1 + find(word1, word2, i, j-1, dp);
        int deleteOp = 1 + find(word1, word2, i-1, j, dp);
        int replaceOp = 1 + find(word1, word2, i-1, j-1, dp);
        
        return dp[i][j] = min({insertOp, deleteOp, replaceOp});
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return find(word1, word2, n-1, m-1, dp);
    }
};
