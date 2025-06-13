// Question Link: https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1

/*
Approach: XOR from Range l to r Using Prefix XOR Pattern

- The XOR of all numbers from 0 to n follows a pattern based on n % 4:
    - n % 4 == 0 → XOR = n
    - n % 4 == 1 → XOR = 1
    - n % 4 == 2 → XOR = n + 1
    - n % 4 == 3 → XOR = 0

- This is encoded in the `giveXOR(n)` function.

- To find XOR from l to r:
    - XOR(0 to r) ^ XOR(0 to l - 1)
    - Because XOR is reversible:  
      (a ^ a) = 0 and (a ^ 0) = a

- So, `findXOR(l, r) = giveXOR(l - 1) ^ giveXOR(r)`

Time Complexity: O(1)  
Space Complexity: O(1)
*/
class Solution {
  public:
    int giveXOR(int n){
        if(n % 4 == 1) return 1;
        if(n % 4 == 2) return n + 1;
        if(n % 4 == 3) return 0;
        return n;
    }
    int findXOR(int l, int r) {
        return giveXOR(l - 1) ^ giveXOR(r);
    }
};

/*
Pattern: XOR from 1 to n

We want to find the XOR of all numbers from 1 to n.

But the known pattern is for XOR from 0 to n:

XOR(0 to n) follows a pattern based on n % 4:
------------------------------------------------------
n % 4 == 0 → XOR = n
n % 4 == 1 → XOR = 1
n % 4 == 2 → XOR = n + 1
n % 4 == 3 → XOR = 0
------------------------------------------------------

To compute XOR from 1 to n:
- Use: XOR(1 to n) = XOR(0 to n) ^ 0 = XOR(0 to n)

Examples:
----------
n = 1 → 1                 → 1 % 4 = 1 → result = 1
n = 2 → 1 ^ 2 = 3         → 2 % 4 = 2 → result = n + 1 = 3
n = 3 → 1 ^ 2 ^ 3 = 0     → 3 % 4 = 3 → result = 0
n = 4 → 1 ^ 2 ^ 3 ^ 4 = 4 → 4 % 4 = 0 → result = n = 4
n = 5 → result = XOR(0 to 5) = 1
n = 6 → result = XOR(0 to 6) = 7
n = 7 → result = XOR(0 to 7) = 0
n = 8 → result = XOR(0 to 8) = 8
*/