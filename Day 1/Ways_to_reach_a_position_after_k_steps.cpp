class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        const int MOD = 1e9 + 7;
        const int MAX_POS = 2005; 
        vector<vector<int>> dp(k + 1, vector<int>(2 * MAX_POS, 0));
        dp[0][startPos + MAX_POS] = 1; 
        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j < 2 * MAX_POS; ++j) {
                if (j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
                if (j < 2 * MAX_POS - 1) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
                }
            }
        }
        return dp[k][endPos + MAX_POS];
    }
};