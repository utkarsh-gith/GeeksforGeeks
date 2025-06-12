// Question Link: https://www.geeksforgeeks.org/problems/set-bits0143/1

/*
Approach: Count Set Bits Using Bitwise Right Shift

- Initialize a counter to 0.
- Loop while n > 0:
    - Use `n & 1` to check if the least significant bit is set.
    - If yes, increment the count.
    - Right shift n by 1 to check the next bit.
- Continue until all bits have been processed.

Time Complexity: O(log n), Space Complexity: O(1)
*/

class Solution {
  public:
    int setBits(int n) {
        int count = 0;
        
        
        while(n > 0){
            if(n % 2 == 1){
                count++;
            }
            
            n /= 2;
        }
        
        return count;
    }
};

// Same same but different

class Solution {
  public:
    int setBits(int n) {
        int count = 0;
        
        
        while(n > 0){
            count += (n & 1);
            n >>= 1;
        }
        
        return count;
    }
};

/*
Approach: Brian Kernighan’s Algorithm

- This algorithm efficiently counts the number of set bits (1s) in the binary representation of an integer.
- Key observation: `n & (n - 1)` clears the lowest set bit in `n`.
- Repeat this operation and increment a counter until `n` becomes 0.

Steps:
1. Initialize count = 0.
2. While n > 0:
    - Do n = n & (n - 1)
    - Increment count
3. Return count

Time Complexity: O(number of set bits), Space Complexity: O(1)
*/

class Solution {
  public:
    int setBits(int n) {
        int count = 0;
        
        
        while(n > 0){
            count += 1;
            n = n & (n - 1);
        }
        
        return count;
    }
};