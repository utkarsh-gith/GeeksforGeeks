class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        
        stack<int> s;
        
        for(int i = 0;i < k;i++){
            s.push(q.front());
            q.pop();
        }
        
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        
        int x = q.size() - k;
        
        while(x--){
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};