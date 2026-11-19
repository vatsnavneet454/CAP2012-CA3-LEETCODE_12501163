// LeetCode 121 - Best Time to Buy and Sell Stock (Easy)
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int bestProfit = 0;

        for (int i = 1; i < static_cast<int>(prices.size()); i++) {
            bestProfit = max(bestProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        return bestProfit;
    }
};
