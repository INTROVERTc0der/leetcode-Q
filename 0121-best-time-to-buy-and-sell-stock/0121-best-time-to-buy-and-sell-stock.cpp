class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX; // Initialize with a very large value
        int maxProfit = 0;      // Initialize maximum profit as 0

        for (int price : prices) {
        // Update minimum price encountered so far
        minPrice = std::min(minPrice, price);
        // Calculate potential profit and update maximum profit
        maxProfit = std::max(maxProfit, price - minPrice);
        }

    return maxProfit;
    }
};