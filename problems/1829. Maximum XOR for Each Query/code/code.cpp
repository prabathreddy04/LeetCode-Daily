class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int value = 0;
        vector<int> result;
        int maxvalue = pow(2, maximumBit)-1;
        for(int i: nums){
            value ^=i;
            result.push_back(value ^ maxvalue);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
