class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
    // Priority queue to store the character counts, with the character that has the most count at the top
        priority_queue<pair<int, char>> pq;

        // Push characters with their respective counts into the priority queue if their count is non-zero
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string result;

        // Continue until there are no more characters to process
        while (!pq.empty()) {
            auto first = pq.top(); // Get the character with the highest count
            pq.pop();

            // If the last two characters in result are the same as the current character, choose the second one in priority
            if (result.size() >= 2 && result.back() == first.second && result[result.size() - 2] == first.second) {
                if (pq.empty()) {
                    break; // If no other character is available, we are done
                }
                auto second = pq.top();
                pq.pop();

                // Add the second character to the result
                result += second.second;

                // If there's still more of the second character, push it back into the priority queue
                if (second.first > 1) {
                    pq.push({second.first - 1, second.second});
                }

                // Push the first character back into the priority queue for future use
                pq.push(first);
            } else {
                // Otherwise, add the first character to the result
                result += first.second;

                // If there's still more of the first character, push it back into the priority queue
                if (first.first > 1) {
                    pq.push({first.first - 1, first.second});
                }
            }
        }

        return result;
    }
};