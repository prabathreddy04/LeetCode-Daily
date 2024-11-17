class Solution { 
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>prefixSum(n+1,0); 
        for(int i=1; i<=n; i++){
            prefixSum[i]=prefixSum[i-1]+nums[i-1];
        }
        deque<int>candiIdx;
        int len=INT_MAX;

        for(int i=0; i<=n; i++){
            while(!candiIdx.empty() && prefixSum[i]-prefixSum[candiIdx.front()]>=k){
                len=min(len,i-candiIdx.front());
                candiIdx.pop_front();
            }
            while(!candiIdx.empty() && prefixSum[i]<=prefixSum[candiIdx.back()]) {
                candiIdx.pop_back();
            }
            candiIdx.push_back(i);
        }
        return len == INT_MAX ? -1 : len;
   }
};
