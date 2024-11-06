class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
    int n = nums.size();
    
    // Step 1: Sort the array
    sort(nums.begin(), nums.end());
    
    // Step 2: Iterate through the array
    for (int i = 0; i < n - 2; ++i) {
        // Avoid duplicate triplets for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        int left = i + 1;
        int right = n - 1;
        
        // Step 3: Two-pointer technique
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                // Found a triplet
                result.push_back({nums[i], nums[left], nums[right]});
                
                // Skip duplicates for the second and third elements
                while (left < right && nums[left] == nums[left + 1]) ++left;
                while (left < right && nums[right] == nums[right - 1]) --right;
                
                ++left;
                --right;
            }
            else if (sum < 0) {
                ++left;
            }
            else {
                --right;
            }
        }
    }
    
    return result;
    }
};