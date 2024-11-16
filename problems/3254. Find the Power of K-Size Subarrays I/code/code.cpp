class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        map[1]=0;
        map[0]=0;
        for(int i=1; i<k; i++){
            if(nums[i] - nums[i-1] ==1 ){
                map[1]++;
            }else{
                map[0]++;
            }
        }
        cout<<map[1]<<" "<<map[0]<<endl;
        vector<int> result;

        if(map[0]==0)    result.push_back(nums[k-1]);
        else result.push_back(-1);
        for(int i=k; i<n; i++){

            if(nums[i]-nums[i-1] == 1)   map[1]++;
            else map[0]++;

            if(nums[i-k] - nums[i-k+1] == -1  && map[1]!=0)   map[1]--;
            else if(map[0]!=0)  map[0]--;

            if(map[0]==0 ) result.push_back(nums[i]);
            else result.push_back(-1);
        }
        return result;
    }
};
