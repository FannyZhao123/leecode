/*
215. Kth Largest Element in an Array
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

//using heap-sort
//Runtime: 20 ms, faster than 49.87% of C++ online submissions for Kth Largest Element in an Array.
//Memory Usage: 10.1 MB, less than 7.57% of C++ online submissions for Kth Largest Element in an Array.
class Solution {
public:
    //using max-heap
    void heapify (vector<int>& nums, int n, int i){
        int largest = i;
        int l = 2*i+1;
        int r = 2*i+2;
        if (l < n && nums[l] > nums[largest]){
            largest = l;
        }
        if (r < n && nums[r] > nums[largest]){
            largest = r;
        }
        if (largest != i){
            swap(nums[i], nums[largest]);
            heapify (nums, n, largest);
        }
    }
    
    void heap_sort_till_k (vector<int>& nums, int n){
        for (int i= n/2 - 1; i >=0; i--){
            heapify(nums, n, i);
        }
        for (int i = n-1; i >= 0; i-- ){
            swap (nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int l = nums.size();
        if (k < 1 || k > l) throw "1 ≤ k ≤ array's length!";
        heap_sort_till_k (nums, l);
        return nums[l-k];
    }
};


//using priority_queue<int,vector<int>,greater<int>> que;
//Runtime: 28 ms, faster than 30.52% of C++ online submissions for Kth Largest Element in an Array.
//Memory Usage: 10.4 MB, less than 7.57% of C++ online submissions for Kth Largest Element in an Array.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==0 or k==0)
            return -1;
        priority_queue<int,vector<int>,greater<int>> que;
        for(int i=0;i<k;i++){
            que.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            que.push(nums[i]);
            que.pop();
        }
        return que.top();
    }
};
