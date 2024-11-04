class Solution {
public:
    string compressedString(string word) {
        std::string comp;
    int n = word.length();
    
    for (int i = 0; i < n;) {
        char current_char = word[i];
        int count = 0;
        
        // Count up to 9 consecutive occurrences of the same character
        while (i < n && word[i] == current_char && count < 9) {
            count++;
            i++;
        }
        
        // Append count and character to the compressed string
        comp += std::to_string(count) + current_char;
    }
    
    return comp;
    }
};