// Question Link: https://www.geeksforgeeks.org/problems/set-kth-bit3724/1

/*
Approach: Bit Masking to Set the k-th Bit

- To set the k-th bit (0-indexed) in an integer `n`, use the bitwise OR operation.
- Create a mask with only the k-th bit set: `(1 << k)`.
- Perform: `n | (1 << k)`
    - If the k-th bit is already set, the value remains unchanged.
    - If it's not set, this operation sets it to 1.

This is a standard and efficient way to set a specific bit.

Time Complexity: O(1), Space Complexity: O(1)
*/

class Solution {
  public:
    int setKthBit(int n, int k) {
        return (n | (1 << k));
    }
};
