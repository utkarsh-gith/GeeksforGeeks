// Question Lonk
// Gfg: https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1

/*
Approach 1: Implementing Two Stacks in a Single Array

- Use a single array of fixed size to simulate two stacks.
- Stack 1 grows from the beginning (index 0) toward the right.
- Stack 2 grows from the end (index size-1) toward the left.
- Maintain two pointers: 
    - top1 starts at -1 for Stack 1.
    - top2 starts at size (e.g., 100) for Stack 2.
- For push:
    - Increment/decrement the corresponding top pointer and insert the value.
- For pop:
    - Return the top value and update the pointer.
- Ensure top1 and top2 do not cross to avoid overflow.

Time Complexity: O(1) for all operations  
Space Complexity: O(1) extra (uses fixed-size array)
*/

class twoStacks {
  public:
    
    vector<int> st;
    int top1;
    int top2;

    twoStacks() {
        st.resize(100);
        top1 = -1;
        top2 = 100;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
       st[++top1] = x;
        
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        st[--top2] = x;
    }

    // Function to remove an element from top of the stack1.
        
    int pop1() {
        if(top1 != -1){
            return st[top1--];
        }else{
            return -1;
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if(top2 != 100){
            return st[top2++];
        }else{
            return -1;
        }
    }
};

/*
Approach 2: Dynamic Two Stacks in a Single Array

- Use a single vector `st` to simulate two stacks.
- Stack 1 grows from the beginning (index 0) towards the right.
- Stack 2 grows from the end (index st.size()-1) towards the left.
- Maintain two pointers:
    - `top1` for Stack 1 (starts at -1).
    - `top2` for Stack 2 (starts at st.size()).

Push Operations:
- If there’s no space between top1 and top2 (i.e., top1 + 1 == top2), double the array size and rearrange the elements.
- Push element to the appropriate position and update the corresponding pointer.

Pop Operations:
- Return the element from the top and adjust the pointer.
- If stack is empty, return -1.

Dynamic resizing:
- When resizing, copy existing Stack 1 and Stack 2 elements into new positions while maintaining their growth directions.

Time Complexity: 
- O(1) amortized for push and pop operations  
- O(n) only during resizing

Space Complexity:
- O(n), where n is the total number of elements inserted
*/

class twoStacks {
  public:
    
    vector<int> st;
    int top1;
    int top2;
    int size;
    
    twoStacks() {
        size = 10;
        st.resize(size);
        top1 = -1;
        top2 = size;
    }
    
    void resizeArray() {
        int oldSize = size;
        size *= 2;
        
        st.resize(size);
        
        int oldtop2 = top2;
        top2 = size;
        
        for(int i = oldSize - 1;i >= oldtop2; i--){
            st[--top2] = st[i];
        }
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        if(top1 + 1 == top2){
            resizeArray();
        }
        st[++top1] = x;
        
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        if(top1 + 1 == top2){
            resizeArray();
        }
        st[--top2] = x;
    }

    // Function to remove an element from top of the stack1.
        
    int pop1() {
        if(top1 != -1){
            return st[top1--];
        }else{
            return -1;
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if(top2 != size){
            return st[top2++];
        }else{
            return -1;
        }
    }
};