# 2026/7/14

class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        MAX_VALUE = 200

        dp = [[0] * (MAX_VALUE + 1) for _ in range(MAX_VALUE + 1)]
        dp[0][0] = 1

        for x in nums:
            next_dp = [
                [0] * (MAX_VALUE + 1)
                for _ in range(MAX_VALUE + 1)
            ]

            for g1 in range(MAX_VALUE + 1):
                for g2 in range(MAX_VALUE + 1):
                    ways = dp[g1][g2]

                    if ways == 0:
                        continue

                    next_dp[g1][g2] = (
                        next_dp[g1][g2] + ways
                    ) % MOD

                    new_g1 = gcd(g1, x)
                    next_dp[new_g1][g2] = (
                        next_dp[new_g1][g2] + ways
                    ) % MOD

                    new_g2 = gcd(g2, x)
                    next_dp[g1][new_g2] = (
                        next_dp[g1][new_g2] + ways
                    ) % MOD

            dp = next_dp

        answer = 0

        for g in range(1, MAX_VALUE + 1):
            answer = (answer + dp[g][g]) % MOD

        return answer
        