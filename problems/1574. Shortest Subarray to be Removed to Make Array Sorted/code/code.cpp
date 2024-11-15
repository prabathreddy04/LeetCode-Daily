class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Find the longest non-decreasing prefix
        int left = 0;
        while (left < n - 1 && arr[left] <= arr[left + 1]) {
            left++;
        }
        
        // If the whole array is sorted, return 0
        if (left == n - 1) {
            return 0;
        }
        
        //  Find the longest non-decreasing suffix
        int right = n - 1;
        while (right > left && arr[right] >= arr[right - 1]) {
            right--;
        }

        //  Check the case when the shortest subarray is the entire array
        int ans = min(n - left - 1, right);

        //  Try to find the shortest subarray to remove by merging the prefix and suffix
        for (int i = 0; i <= left; i++) {
            while (right < n && arr[i] > arr[right]) {
                right++;
            }
            if (right < n) {
                ans = min(ans, right - i - 1);
            }
        }
        
        return ans;
    }
};
