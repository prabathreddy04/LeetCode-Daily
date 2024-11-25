# 2659. Make Array Empty

## Problem Description
You are given an integer array `nums` containing distinct numbers. You can perform the following operations until the array is empty:
1. If the first element has the smallest value, remove it.
2. Otherwise, put the first element at the end of the array.

Return an integer denoting the number of operations it takes to make `nums` empty.

---

## Intuition and Approach

### Step-by-Step Walkthrough

#### **Initial Thoughts:**
The problem asks us to repeatedly remove the smallest element from the front of the array. If the first element is not the smallest, we rotate the array, placing the first element at the end. This process repeats until the array is empty.

I initially attempted to simulate the process step by step, as described in the problem, to find the solution. However, due to the repeated rotations and adjustments required, my approach led to a **Time Limit Exceeded (TLE)** error because of excessive operations.

---

### **My Initial Approach:**
1. **Understanding the Problem:**
   - To solve this, I first needed to find the smallest element and ensure it was at the front of the array.
   - I saved the original indices of the elements to track their positions even as the array was being rotated.
   - I simulated the operations by moving the first element to the end until the smallest element reached the front, at which point it would be removed.
   
2. **Code Implementation (Initial Approach):**

```cpp
class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        vector<pair<int, int>> vec;
        for (int i = 0; i < nums.size(); i++) {
            vec.push_back({nums[i], i});
        }
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());
        
        long long count = 0;
        while (!vec.empty()) {
            int s = vec.size();
            int k = vec[s - 1].second;
            count += k;

            for (auto& i : vec) {
                if (i.second >= k) {
                    i.second -= k;
                } else {
                    i.second += s - k;
                }
            }

            if (!vec.empty()) {
                vec.pop_back();
                for (auto& i : vec) {
                    i.second--;
                }
                count++;
            }
        }
        return count;
```



### **Optimized Approach (Final Solution):**

After analyzing the issue with my initial approach, I realized that we could avoid simulating the rotations directly and instead calculate the number of operations more efficiently.

**Optimized Steps:**
1. **Create a Vector of Pairs:** Store each element of `nums` alongside its original index in a vector of pairs.
2. **Sort the Array by Value:** Sort the vector of pairs by the values of the elements. This ensures that we can process the smallest elements first.
3. **Count Base Operations:** The number of base operations required to remove all elements is equal to the size of the array.
4. **Track Rotations:** We track the rotations needed by comparing the indices of the elements in the sorted order. If the current element's index is less than the previous element's index, it means the element has to "wrap around" (rotate) to the front, so we add the remaining elements to the operation count.
5. **Return Total Count:** Finally, return the total number of operations.

---

### **Code Implementation (Optimized Solution):**

```cpp
class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec;
        
        // Store each element and its original index in a vector of pairs
        for (int i = 0; i < n; i++) {
            vec.push_back({nums[i], i});
        }
        
        // Sort the vector based on the element values
        sort(vec.begin(), vec.end());
        
        // Initialize the operation count with the number of elements in the array
        long long count = n; 
        
        // Track additional operations required due to rotations
        for (int i = 1; i < n; i++) {
            // If the current index is smaller than the previous index, we have a rotation
            if (vec[i].second < vec[i - 1].second) {
                count += n - i;  // Add the remaining operations for the wrap-around
            }
        }
        
        // Return the total count of operations
        return count;
    }
};

