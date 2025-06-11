// Question Lonk
// Gfg: https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1


/*
Approach 1: Using an Auxiliary Stack to Delete the Middle Element

- Calculate the middle index of the stack.
  - For even size, delete the lower middle element.
- Use a temporary stack to hold the top elements until reaching the middle.
- Pop the middle element directly from the original stack.
- Push the saved elements back into the original stack to restore order.

Time Complexity: O(n), Space Complexity: O(n)
*/

class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        int size = s.size();
        int mid = size % 2 == 0 ? size / 2 - 1 : size / 2;
        
        stack<int> st;
        
        for(int k = size - 1;k > mid; k--){
            st.push(s.top());
            s.pop();
        }
        
        s.pop();
        
        while(!st.empty()){
            s.push(st.top());
            st.pop();
        }
    }
};

/*
Approach 2: Recursive Deletion Without Extra Space

- Compute the middle index of the stack.
- Use recursion to pop elements from the top until the middle is reached.
- Remove the middle element.
- During the backtracking phase, push all other elements back onto the stack.

Time Complexity: O(n), Space Complexity: O(n) (due to call stack)
*/

class Solution {
  public:
  
    void recursiveDelete(stack<int>& s, int& mid, int n){
        if(n == mid){
            s.pop();
            return;
        }
        
        int k = s.top();
        s.pop();
        recursiveDelete(s, mid, n - 1);
        s.push(k);
    }
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        int size = s.size();
        int mid = size % 2 == 0 ? size / 2 - 1 : size / 2;
        
        recursiveDelete(s, mid, size - 1);
    }
};