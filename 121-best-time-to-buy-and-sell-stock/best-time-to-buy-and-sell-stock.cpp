class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int i = 0, j = 0;

        int min_price   = prices[0];
        int max_profit = 0;
        int price = 0;
        while(j<size){

            int profit = prices[j] - min_price;
            max_profit = max(max_profit, profit);
            j++;

            if(j<size && prices[j] < min_price){
                min_price = prices[j];

            }                                   
        }
        return max_profit;
    }
};