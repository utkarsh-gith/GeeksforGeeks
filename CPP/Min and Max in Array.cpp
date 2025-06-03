// GFG
// Question Link - https://www.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

/*
Approach 1 -
    Using two variables maxEle and minEle to store the maximum and minimum elements
    Traverse through the array and compare maxEle and minEle with every element

    Space Complexity - O(1)
    Time Complexity - O(n)
        where n is size of array 
*/
class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        int maxEle = arr[0];
        int minEle = arr[0];
        
        for(int& a : arr){
            maxEle = max(maxEle, a);
            minEle = min(minEle, a);
        }
        
        return {minEle, maxEle};
    }
};

/*
Approach 2 -
    Sorting the array in increasing order
    return the first and last element of the array

    Space Complexity - O(1)
    Time Complexity - O(nlogn) if used sort methods like quicksort or in-built sort() function
        where n is size of array
*/
class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        sort(arr.begin(), arr.end());
        return {arr[0], arr[arr.size() - 1]};
    }
};