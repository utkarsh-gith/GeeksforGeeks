class Solution {
  public:
    int circularTour(vector<int>& a1, vector<int>& a2) {
        
        int n = a1.size();
        
        int i = 0;
        
        int index = -1;
        
        while(i < n){
            
            int balance = 0;
            int j = 0;
            for(j = 0;j < n;j++){
                balance += a1[(j + i) % n] - a2[(j + i) % n];
                if(balance < 0){
                    i = j + i;
                    break;   
                }
            }
            if(j == n){
                index = i;
                break;
            }
            i++;
            
        }
        
        return index;
    }
};

// OR

class Solution {
  public:
    int circularTour(vector<int>& a1, vector<int>& a2) {
        
        int n = a1.size();
        
        int total_surplus = 0;
        int current_surplus = 0;
        
        int index = 0;
        
        for(int i = 0;i < n;i++){
            
            int balance = a1[i] - a2[i];
            total_surplus += balance;
            current_surplus += balance;
            
            if(current_surplus < 0){
                index = i + 1;
                current_surplus  = 0;
            }
            
        }
        
        return (total_surplus >= 0) ? index : -1;
    }
};