class Solution {
public:
    int solve(vector<vector<int>>& dp,vector<int>& price, int i, bool buyed ){
        //base case 
        if(i>=price.size()-1 ){
            return (buyed)? price[i]:0;
        }

        if(dp[i][buyed]!=-1)return dp[i][buyed];

        //sell 
        if(buyed){
            int sellprofit=price[i]+solve(dp,price,i+1,false);
            int hold=solve(dp,price,i+1,buyed);
            return dp[i][buyed]=max(sellprofit,hold);
        }
        //buy
        else{
            int buyprofit=-price[i]+solve(dp,price,i+1,true);
            int dontbuy=solve(dp,price,i+1,buyed);
            return dp[i][buyed]=max(buyprofit,dontbuy);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(dp,prices,0,false);
    }
};