class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return self.min_max(prices)

    # blind
    def naive(self, prices):
        profit = 0
        for i in range(len(prices)):
            for j in range(i + 1, len(prices)):
                if prices[j] - prices[i] > profit:
                    profit = prices[j] - prices[i]
        return profit
    
    # blind
    def max_price(self, prices):
        profit = 0

        # preprocessing
        current_max = prices[-1]
        max_arr = []
        for i in range(1, len(prices) + 1):
            if prices[-i] > current_max:
                current_max = prices[-i]
            max_arr.append(current_max)
        max_arr.reverse()
        
        for i in range(len(prices)):
            if max_arr[i] - prices[i] > profit:
                profit = max_arr[i] - prices[i]
        return profit

