class Solution {
public:
    int solveR(vector<int>& prices, bool buy, int index){
        if(index==prices.size()-1){
            if(buy) return prices[index];
            return 0;
        }
        //buy
        if(!buy){
            //buy it now or wait
            int buynow=-prices[index]+solveR(prices,true,index+1);
            int notbuy=solveR(prices,false,index+1);
            return max(buynow,notbuy);
        }
        //sell
        else{
            //sell it now or not
            int sellnow=prices[index];
            int notsellnow=solveR(prices,true,index+1);
            return max(sellnow,notsellnow);
        }
    }
    //memoization
    int solveM(vector<vector<int>>dp,vector<int>& prices, bool buy, int index){
        if(index==prices.size()-1){
            if(buy) return prices[index];
            return 0;
        }
        if(dp[index][buy]!=-1)return dp[index][buy];
        //buy
        if(!buy){
            //buy it now or wait
            int buynow=-prices[index]+solveR(prices,true,index+1);
            int notbuy=solveR(prices,false,index+1);
            return dp[index][buy]=max(buynow,notbuy);
        }
        //sell
        else{
            //sell it now or not
            int sellnow=prices[index];
            int notsellnow=solveR(prices,true,index+1);
            return dp[index][buy]=max(sellnow,notsellnow);
        }
    }
    //tabulation 
    int solveT(vector<int>& prices){
        vector<vector<int>>dp(prices.size(),vector<int>(2,0));
        //initial initilization
        dp[prices.size()-1][1]=prices[prices.size()-1];
        dp[prices.size()-1][0]=0;

        for(int index=prices.size()-2;index>=0;index--){
            for(int buy=1;buy>=0;buy--){
                if(!buy){
                    //buy it now or wait
                    int buynow=-prices[index]+dp[index+1][true];
                    int notbuy=dp[index+1][false];
                    dp[index][buy]=max(buynow,notbuy);
                }
                //sell
                else{
                //sell it now or not
                    int sellnow=prices[index];
                    int notsellnow=dp[index+1][true];
                    dp[index][buy]=max(sellnow,notsellnow);
                }
            }
        }
        return dp[0][0];

    }
    int maxProfit(vector<int>& prices) {

        // return solveR(prices,false,0);

        //vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        //return solveM(dp,prices,false,0);

        return solveT(prices);

    //     int minPrice = INT_MAX; // Initialize with a very large value
    //     int maxProfit = 0;      // Initialize maximum profit as 0

    //     for (int price : prices) {
    //     // Update minimum price encountered so far
    //     minPrice = std::min(minPrice, price);
    //     // Calculate potential profit and update maximum profit
    //     maxProfit = std::max(maxProfit, price - minPrice);
    //     }

    // return maxProfit;


    }
};