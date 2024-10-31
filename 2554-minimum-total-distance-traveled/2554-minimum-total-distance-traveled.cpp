#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

class Solution {
public:
    long long minimumTotalDistance(std::vector<int>& robot, std::vector<std::vector<int>>& factory) {
        // Sort robots and factories by their positions
        std::sort(robot.begin(), robot.end());
        std::sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        // DP table, where dp[i][j] is the minimum distance for first i robots and first j factories
        std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(m + 1, LLONG_MAX));
        
        // Initialize with 0 distance when there are no robots to assign
        dp[0][0] = 0;

        // DP processing
        for (int j = 1; j <= m; ++j) {
            dp[0][j] = 0;  // No robots assigned yet, so distance is 0
            for (int i = 1; i <= n; ++i) {
                dp[i][j] = dp[i][j - 1]; // Assume no assignment of i-th robot to j-th factory
                long long distSum = 0;
                
                // Assign up to 'limit' robots to the j-th factory
                for (int k = 1; k <= factory[j - 1][1] && k <= i; ++k) {
                    distSum += std::abs(robot[i - k] - factory[j - 1][0]);
                    if (dp[i - k][j - 1] != LLONG_MAX) {
                        dp[i][j] = std::min(dp[i][j], dp[i - k][j - 1] + distSum);
                    }
                }
            }
        }

        return dp[n][m];
    }
};
