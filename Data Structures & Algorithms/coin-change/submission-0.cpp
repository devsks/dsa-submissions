class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> minCoin(amount + 1, -1);
        minCoin[0] = 0;
        sort(coins.begin(), coins.end());
        for (int money = 1; money <= amount; ++money) {
            for (int& coin : coins) {
                int rem = money - coin;
                if(rem < 0)
                    break;
                if (minCoin[rem] != -1) {
                    if (minCoin[money] == -1)
                        minCoin[money] = minCoin[rem] + 1;
                    else
                        minCoin[money] = min(minCoin[money], minCoin[rem] + 1);
                }
            }
        }
        return minCoin[amount];
    }
};
