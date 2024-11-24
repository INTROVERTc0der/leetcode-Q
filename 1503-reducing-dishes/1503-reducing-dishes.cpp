class Solution {
public:
    int solve(vector<int>&sat,int i,int time){
        if(i==sat.size()) return 0;

        int includeLikeTimeCoeff= time*sat[i]+solve(sat,i+1,time+1);
        int excludeLikeTimeCoeff= solve(sat,i+1,time);

        return max(includeLikeTimeCoeff,excludeLikeTimeCoeff);
    }
    int solveM(vector<vector<int>>&dp,vector<int>&sat,int i,int time){
        if(i==sat.size()) return 0;

        if(dp[i][time]!=-1)return dp[i][time];

        int includeLikeTimeCoeff= time*sat[i]+solveM(dp,sat,i+1,time+1);
        int excludeLikeTimeCoeff= solveM(dp,sat,i+1,time);

        return dp[i][time]=max(includeLikeTimeCoeff,excludeLikeTimeCoeff);
    }



    int solveT(vector<int>&sat,int n){
        //vector<vector<int>>dp(n+1,vector<int>(n+2,0));
        vector<int> next(n+2,0);
        vector<int> curr(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int time=n;time>=1;time--){
                int includeLikeTimeCoeff= time*sat[i]+next[time+1];
                int excludeLikeTimeCoeff=next[time];

                curr[time]=max(includeLikeTimeCoeff,excludeLikeTimeCoeff);
            }
            next=curr;
        }
        return next[1];
    }
    int solveS(vector<int>&sat,int n){
        vector<vector<int>>dp(n+1,vector<int>(n+2,0));

        for(int i=n-1;i>=0;i--){
            for(int time=n;time>=1;time--){
                int includeLikeTimeCoeff= time*sat[i]+dp[i+1][time+1];
                int excludeLikeTimeCoeff=dp[i+1][time]; 

                dp[i][time]=max(includeLikeTimeCoeff,excludeLikeTimeCoeff);
            }
        }
        return dp[0][1];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end()); //this step is very important i stuck on this condition
        //if the sequence can be anything then try to find the best possible sequence and apply only on that sequence

        //return solve(satisfaction,0,1);



        // //using memoisation 
          int n=satisfaction.size();
        //  vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        //  return solveM(dp,satisfaction,0,1);


        // //using tabualtion
         return solveT(satisfaction,n);

         //return solveS(satisfaction,n);


    }
};