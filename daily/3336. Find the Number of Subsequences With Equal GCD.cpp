// 2026/7/14

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        long long count = 0;

        vector<vector<long long>> dp(201, vector<long long>(201));
        dp[0][0] = 1;

        for (int x : nums) {
            vector<vector<long long>> next(201, vector<long long>(201));

            for (int g1 = 0; g1 <= 200; g1++) {
                for (int g2 = 0; g2 <= 200; g2++) {
                    if (dp[g1][g2] == 0) continue;

                    // Add x to seq1
                    int newG1 = (g1 == 0) ? x : gcd(g1, x);
                    next[newG1][g2] = (next[newG1][g2] + dp[g1][g2]) % 1000000007;

                    // Add x to seq2
                    int newG2 = (g2 == 0) ? x : gcd(g2, x);
                    next[g1][newG2] = (next[g1][newG2] + dp[g1][g2]) % 1000000007;

                    // Don't add x to either subsequence
                    next[g1][g2] = (next[g1][g2] + dp[g1][g2]) % 1000000007;
                } // end for
            } // end for

            dp = next;
        } // end for

        for (int g = 1; g <= 200; g++) {
            count = (count + dp[g][g]) % 1000000007;
        } // end for

        return count;
    } // end subsequencePairCount
};