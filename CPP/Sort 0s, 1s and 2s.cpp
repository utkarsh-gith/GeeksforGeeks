// Leetcode
// Question Link - https://leetcode.com/problems/sort-colors/description/

// GFG
// Question Link - https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

/*
Approach 1 -
    Sort the array in increasing order
    Use sort algorithms like quicksort of sort function

    Space Complexity - O(1)
    Time Complexity - O(nlogn)
        where n is size of array 
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

/*
Approach 2 -
    Count the number of 0's and 1's
    Replace all elements to 0 until count of 0
    Replace all elements to 1 from count of 0 until count of 1
    Replace all elements to 2 from count of 1 to end of array

    Space Complexity - O(1)
    Time Complexity - O(n) -> traversing the array two times (one for count and another for overwritting)
        where n is size of array 
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int red = 0, white = 0;
        for(int i=0; i<n ; i++){
            if(nums[i] == 0)
                red ++;
            if(nums[i] == 1)
                white ++;
        }
        int i=0;
        while(i < red){
            nums[i++] = 0;
        }
        while(i < red + white){
            nums[i++] = 1;
        }
        while(i < n){
            nums[i++] = 2;
        }
    }
};

/*
Approach 3 -
    Dutch National Flag Algorithm
    This algorthim is used to sort 0's , 1's and 2's in an unsorted array of 0,1 and 2

    It is called "Dutch national flag algorithm" because the flag of netherlands have three colors red, white and blue
    Also Leetcode question "75. Sort Colors" is the same question

    The idea is to use three pointers: low, mid , high
    low points to start of 1's
    high points to end of 1's

    0's get sorted from 0 to low - 1
    1's get sorted from low to mid - 1
    2's het sorted from high to n - 1
        where n is size of array
    As the algorithm completes, spaced between mid and (high - 1) becomes 0
    So only the algoirthm executes while mid is less than or equal to high (mid <= high)

    low and mid is initialised to index 0
    high is initialised to index n - 1

    Three Rules:

        if mid point to 0, swap it with low, increment low and mid
            swap(arr[low], arr[mid])
            low++
            mid++

        if mid point to 1, just increment mid
            mid++

        if mid point to 2, swap it with high, decrement high
            swap(arr[mid], arr[high])
            high--    


    Space Complexity - O(1)
    Time Complexity - O(n) -> traverses the array single time
        where n is size of array 
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low++], nums[mid++]);
            }else if(nums[mid] == 2){
                swap(nums[mid], nums[high--]);
            }else{
                mid++;
            }
        }
    }
};