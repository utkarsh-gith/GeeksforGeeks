// Time Complexity: O(2n), where n is size of array
// Space Complexity: O(n), where n is size of array

class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // Your code goes here
        queue<int> pos;
        queue<int> neg;
        
        for(int& a : arr){
            if(a >= 0){
                pos.push(a);
            }else{
                neg.push(a);
            }
        }
        
        int i = 0;
        while(!pos.empty()){
            arr[i++] = pos.front();
            pos.pop();
        }
        while(!neg.empty()){
            arr[i++] = neg.front();
            neg.pop();
        }
    }
};

// OR

// Time Complexity: O(p + 2n), where p and n are number of positive and negative elements respectively
// Space Complexity: O(n), where n is number of negative elements

class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        int i = 0;
        queue<int> neg;
        
        for(int j = 0;j < arr.size(); j++){
            if(arr[j] >= 0){
                arr[i++] = arr[j];
            }else{
                neg.push(arr[j]);
            }
        }
        
        while(!neg.empty()){
            arr[i++] = neg.front();
            neg.pop();
        }
    }
};