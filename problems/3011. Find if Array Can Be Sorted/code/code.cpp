class Solution {
public:
    int countBits(int num) {
        int i = 0;
        int count = 0;
        while (i < 32 && 1 << i <= num) {
            if (1 << i & num)
                count++;
            i++;
        }
        return count;
    }
    bool canSortArray(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i : nums) {
            map[i] = countBits(i);
        }
        int n = nums.size();
        bool isSortable = true;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    if (map[nums[j]] == map[nums[j + 1]]) {
                        swap(nums[j], nums[j + 1]);
                    } else {
                        isSortable = false;
                    }
                }
            }
        }
        return isSortable;
    }
};
