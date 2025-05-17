//time limit exceeded

class Solution {
  public:
    string FirstNonRepeating(string &s) {
        
        map<char,int> count;
        int n = s.size();
        char j = 0;
        string res = "";
        
        for(int i = 0;i < n;i++){
            
            count[s[i]]++;
            if(count[s[j]] == 1){
                res += s[j];
            }else{
                while(j <= i && count[s[j]] != 1){
                    j++;
                }
                if(j > i){
                    res += '#';
                }else{
                    res += s[j];
                }
            }
            
        }
        
        return res;
        
    }
};

//OR

class Solution {
  public:
    string FirstNonRepeating(string &s) {
        
        map<char, int> count;
        queue<char> q;
        string res = "";
        
        for(char c : s){
            
            count[c]++;
            
            q.push(c);
            
            while(!q.empty()){
                
                if(count[q.front()] > 1){
                    q.pop();
                }else{
                    res.push_back(q.front());
                    break;
                }
            }
            
            if(q.empty()){
                res.push_back('#');
            }
        }
        
        return res;
    }
};