# Intuition
At the first glance, one might think of ways to calculate all different combinations possible and picking the largest combination, which is not the metod we are supposed to follow in bit manipulatiobns.

to find the largest combination of numbers in the list candidates whose AND is greater than 0 so if all the numbers in a combination has a ith bit set , it means their AND will surely be greater than 0 , so the problem breaks down to find the largest combination of numbers in the list candidates where a specific bit position (from 0 to 31) is set to 1. In other words, we want to find the maximum number of elements in candidates that share a common bit position set to 1.

# Approach
## 1.Initialize Variables:
We start by defining a variable ans to store the maximum count of elements that share the same bit position with a bit set to 1.

## 2.Iterate Over Bit Positions:
Since integers are 32 bits in length, we loop from 0 to 31 to cover all possible bit positions.

## 3.Count Set Bits for Each Position:
For each bit position i (from 0 to 31), we count how many elements in candidates have that specific bit set to 1.

To check if the i-th bit of a number candidate is set, we use the expression candidate & (1 << i). 1 << i shifts 1 to the i-th bit position, creating a mask (like 00010000 for i = 4). candidate & (1 << i) checks if this bit is set by applying the mask; if the result is non-zero, then this bit is set in candidate.

## 4. Update Maximum Count:
After counting the elements with the i-th bit set, we update ans to hold the maximum of ans and cnt.

## 5. Return the Result:
After iterating over all bit positions, ans holds the largest combination of elements with a common set bit, which is returned as the answer.
