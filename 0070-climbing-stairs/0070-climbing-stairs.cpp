class Solution {
public:
    int solveM(int n, vector<int>& dp){
        if(n==1) return 1;
        if(n==2)return 2;
        if(dp[n]!=-1)return dp[n];
        int fn = solveM(n-1,dp)+solveM(n-2,dp);
        return dp[n]=fn;
    }
    int solveT(int n){
        if(n==1)return 1;
        if(n==2)return 2;
        vector<int>dp(n+1,0);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            int fn = dp[i-1]+dp[i-2];
            dp[i]=fn;
        }
        return dp[n];
    }
    int climbStairs(int n) {
        return solveT(n);
        //vector<int>dp(n+1,-1);
        //return solveM(n,dp);
    }
};