class Solution {
public:
    string makeFancyString(string s) {
        string result;
        int count = 1; // Start with 1 to count the first character

        // Add the first character to the result to start
        result += s[0];
        
        for (int i = 1; i < s.size(); ++i) {
            // Check if the current character is the same as the previous one
            if (s[i] == s[i - 1]) {
                ++count;
            } else {
                count = 1; // Reset count for a new character
            }

            // Only add the character if we have fewer than 3 consecutive
            if (count < 3) {
                result += s[i];
            }
        }

        return result;
    }
};
