## Problem Overview
The problem involves computing the sum of node values at each level of a binary tree and finding the **k-th largest sum**. We will use **Breadth-First Search (BFS)** to traverse the tree level by level, calculate the sum for each level, and sort these sums to retrieve the k-th largest value.

## Approach

1. **Level-Order Traversal (BFS)**:
   - Traverse the binary tree level by level using a queue.
   - At each level, compute the sum of node values.
   - Store these sums in a list.

2. **Sort and Retrieve**:
   - Sort the sums in descending order.
   - Return the k-th largest sum using 1-based indexing (`res[k-1]`).
   - If `k` exceeds the number of levels, return `-1`.

## Time and Space Complexity

- **Time Complexity**: 
   - BFS traversal takes **O(N)**, where N is the number of nodes.
   - Sorting the sums takes **O(L log L)**, where L is the number of levels.
   - Overall time complexity is **O(N + L log L)**.

- **Space Complexity**: 
   - The queue used for BFS and the list of sums requires **O(N)** space.
 
