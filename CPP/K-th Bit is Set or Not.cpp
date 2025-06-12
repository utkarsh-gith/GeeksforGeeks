// Code Link: https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1

/*
Approach: Right Shift and Modulo

- To check if the k-th bit (0-indexed) is set in integer n:
    - Right shift n by k positions: `n >> k`.
    - This brings the k-th bit to the least significant position.
    - Then, check if the resulting number is odd using `(n % 2 != 0)`.
        - If it is, the bit was set (1).
        - Otherwise, the bit was not set (0).

Time Complexity: O(1), Space Complexity: O(1)
*/

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        n = n >> k;
        return !(n % 2 == 0);
    }
};

/*
Approach: Bit Masking

- To check if the k-th bit (0-indexed) in integer n is set:
    - Create a bitmask by left shifting 1 by k: `(1 << k)`.
    - Perform a bitwise AND with n: `(n & (1 << k))`.
    - If the result is non-zero, the k-th bit is set.
    - Otherwise, it is not set.

This is the most efficient and standard method for checking individual bits.

Time Complexity: O(1), Space Complexity: O(1)
*/

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        return (n & (1 << k)) != 0;
    }
};

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        return ((n >> k) & 1) != 0;
    }
};