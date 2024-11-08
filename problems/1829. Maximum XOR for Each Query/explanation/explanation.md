# Intuition
We need to realize that the maximum XOR for a query can always be made equal to 2^maximumBit - 1. Here's why:

Every element in nums is constrained such that 0 <= nums[i] < 2^maximumBit.
The XOR of all elements in the nums array will also result in a value between [0, 2^maximumBit - 1].
Now, to maximize the XOR result for each query, we can XOR the obtained prefix XOR value with the number that would give the maximum possible XOR result, which is 2^maximumBit - 1.

Why is the maximum always 2^maximumBit - 1?
Given that all elements of the nums array are in the range [0, 2^maximumBit - 1], after XOR-ing the entire array, the result will also lie within this range. We can XOR this result with any number from the same range to maximize the XOR result. The number that achieves this is 2^maximumBit - 1 because XOR-ing any number with this value gives the complement of the number in that range.

# Approach
Calculate the XOR of the prefix of nums for each element.
XOR this result with the maximum possible value, which is 2^maximumBit - 1.
Push the result of each query into a result vector.
Reverse the result vector at the end since the queries are processed from the last index of nums to the first.
