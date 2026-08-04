class Solution {
public:
    int characterReplacement(string s, int k) {
        int hash[26] = {0};
        int l = 0;
        int maxf = 0;
        int ans = 0;

        for(int n = 0; n < s.size(); n++) {
            hash[s[n] - 'A']++;
            maxf = max(maxf, hash[s[n] - 'A']);

            // invalid window → shrink by 1
            if((n - l + 1) - maxf > k) {
                hash[s[l] - 'A']--;
                maxf = 0;
                l++;
            }

            ans = max(ans, n - l + 1);
        }
        return ans;
    }
};
