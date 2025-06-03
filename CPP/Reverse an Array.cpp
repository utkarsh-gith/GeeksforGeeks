// GFG
// Question Link - https://www.geeksforgeeks.org/problems/reverse-an-array/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

/*
Naive Approach - 
    Create another array and store the reversed array in it

    Space Complexity - O(n)
    Time Complexity - O(n)
        where n is size of array 

Better Approach -
    Using two pointers and swapping the elements
    Start with i = 0 and j = n - 1
    Run and loop while i is less than j and swap elements at i-th and j-th index
    Increment i while decrement j in every loop

    Space Complexity - O(1)
    Time Complexity - O(n)
        where n is size of array 
*/

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        for(int i = 0, j = arr.size() - 1; i < j ; i++, j--){
            swap(arr[i], arr[j]);
        }
    }
};