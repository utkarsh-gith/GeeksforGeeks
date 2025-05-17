// using recursion (time limit exceeded)

class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        
        if(q.empty()){
            return q;
        }
        
        int temp = q.front();
        q.pop();
        q =  rev(q);
        q.push(temp);
        
        return q;
        
    }
};

// using stack

class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        stack<int> st;
        
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        return q;
    }
};