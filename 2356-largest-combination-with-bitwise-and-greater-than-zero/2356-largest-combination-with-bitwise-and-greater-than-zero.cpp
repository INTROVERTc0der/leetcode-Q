class Solution {
public:
    int solve(vector<int>&candidates, int index, int count , int AND){
        //base case
        if(index==candidates.size()){
            return (count>0 && AND>0)? count:0;
        }
        //include 
        int include=solve(candidates,index+1,count+1,AND & candidates[index]);
        //exclude
        int exclude=solve(candidates,index+1,count,AND);

        return max(include,exclude);
    }
    
    int largestCombination(vector<int>& candidates) {
        //return solve(candidates,0,0,INT_MAX);

        int maxCombination = 0;
    
    // We will only consider up to 24 bits because 1 <= candidates[i] <= 10^7 (which fits in 24 bits).
    for (int bit = 0; bit < 24; ++bit) {
        int count = 0;
        
        // Count how many numbers have the current bit set.
        for (int num : candidates) {
            if (num & (1 << bit)) {
                count++;
            }
        }
        
        // Update the maximum combination size found so far.
        maxCombination = max(maxCombination, count);
    }
    
    return maxCombination;
    }
};