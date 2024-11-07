class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int result = 0;
        for(int i=0; i<31; i++){
            int sum = 0;
            for(int k:candidates){
                if(k & 1<<i) sum++;
            }
            result = max(sum, result);
        }
        return result ;
    }
};
