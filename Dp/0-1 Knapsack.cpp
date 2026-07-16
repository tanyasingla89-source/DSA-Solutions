vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

// Base case: only item 0 available
for (int w = wt[0]; w <= maxWeight; w++) {
    dp[0][w] = val[0];
}

for (int ind = 1; ind < n; ind++) {
    for (int w = 0; w <= maxWeight; w++) {
        int notTake = 0 + dp[ind-1][w];
        int take = INT_MIN;
        if (wt[ind] <= w) {
            take = val[ind] + dp[ind-1][w - wt[ind]];
        }
        dp[ind][w] = max(take, notTake);
    }
}

return dp[n-1][maxWeight];
