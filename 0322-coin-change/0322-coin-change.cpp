class Solution {
public:
    int usingrecursion(vector<int>&coins,int amount,int n){
        //base case
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        //solve one case baki recursion sambhal lega
        int mini=INT_MAX;
        for(int i=0;i<=n;i++){
            int subproblm=usingrecursion(coins,amount-coins[i],n);
            if(subproblm!=INT_MAX && subproblm!=-1){
                mini=min(mini,subproblm+1);
            }
            //if(subproblm==-1) mini=INT_MAX; // important condition 
        }
        if(mini==INT_MAX) return -1;
        return mini;
    }

    // solving using memoisation 
    int usingmemoisation(vector<int>& coins , int amount , vector<int>& dp, int n){
        //base case
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;

        if(dp[amount]!=0){
            return dp[amount];
        }
        //solve one case baki recursion sambhal lega
        int mini=INT_MAX;
        for(int i=0;i<=n;i++){
            int subproblm;
            subproblm=usingmemoisation(coins,amount-coins[i],dp,n);
            if(subproblm!=INT_MAX){
                mini=min(mini,subproblm+1);
            }
        }
        dp[amount]=mini;
        return mini;
    }


    int usingtabulation(vector<int>& coins, int amount, int n){
        //creating dp array
        vector<int> dp (amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
           int mini=INT_MAX;
            for(int j=0;j<=n;j++){
                if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX) {
                    mini=min(mini,dp[i-coins[j]]+1); }
            }
            if(mini!=INT_MAX) dp[i]=mini;
        }
        return dp[amount];
    }
     int coinChange(vector<int>& coins, int amount){
         int n=coins.size()-1;
        // //for solving using recursion 
        //return usingrecursion(coins,amount,n);

        //for solving using memoisation
        // vector<int> dp(amount+1,0);
        // int ans=usingmemoisation(coins,amount,dp,n);
        // if(ans==INT_MAX) return -1;
        // else return ans;


        // //using tabulation
        int ans=usingtabulation(coins,amount ,n);
        if(ans==INT_MAX) return -1;
        else return ans;
    }
 };