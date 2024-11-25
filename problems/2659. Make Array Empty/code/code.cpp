# Final Solution 

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec;
        
        for (int i = 0; i < n; i++) {
            vec.push_back({nums[i], i});
        }
        
        sort(vec.begin(), vec.end());
        
        long long count = n; 
        for (int i = 1; i < n; i++) {
            if (vec[i].second < vec[i - 1].second) {
                count += n - i; 
            }
        }
        
        return count;
    }
};
