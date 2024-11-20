class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        
        // Step 1: Count total occurrences of 'a', 'b', and 'c'
        unordered_map<char, int> total;
        for (char c : s) {
            total[c]++;
        }

        // Step 2: Check if it's possible to satisfy the condition
        if (total['a'] < k || total['b'] < k || total['c'] < k) {
            return -1;
        }

        // Step 3: Sliding window to find the largest valid subarray
        unordered_map<char, int> window;
        window['a'] = 0;
        window['b'] = 0;
        window['c'] = 0;

        int l = 0, maxWindow = 0;

        for (int r = 0; r < n; r++) {
            window[s[r]]++;  // Add character to the window

            // Calculate remaining counts outside the window
            int remaining_a = total['a'] - window['a'];
            int remaining_b = total['b'] - window['b'];
            int remaining_c = total['c'] - window['c'];

            // Shrink the window if it becomes invalid
            while (remaining_a < k || remaining_b < k || remaining_c < k) {
                window[s[l]]--;
                remaining_a = total['a'] - window['a'];
                remaining_b = total['b'] - window['b'];
                remaining_c = total['c'] - window['c'];
                l++;
            }

            // Update the maximum valid window size
            maxWindow = max(maxWindow, r - l + 1);
        }

        // Step 4: Calculate and return the result
        return n - maxWindow;
    }
};
