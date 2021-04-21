#include <vector>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last_item = -10001;
        int i = 0;
        int replaced = 0;
        int size = 0;
        for(i = 0; i < nums.size(); i++) {
            // check whether it is duplicate
            if(nums[i] != last_item) {
                nums[replaced] = nums[i];
                replaced += 1;
                last_item = nums[i];
                size++;
            }
        }
        return size;
    }
};
// input: an sorted rray
// requirement: do the array in place --> no extra space for array, constant space is allowed
// output: the length of the array --> how about the array itself ?? pass it by reference
// solution: hash table (x feasible => extra space for the array)
//  1. walk through the array --> if x exist --> insert to array, if exist then remove
// solution 2:
// 1. make a temp variable to store last item
// 2. if the currrent is equal to last then remove
// 3. else not remove
// 4. walk through array and align it


// test [1, 3, 3, 4, 5, 5, 6]
// i == 0 replaced = -1 last_item = 1 dup_count = 0 [1, 3, 3, 4, 5, 5, 6]
// i == 1 replaced = -1 last_item = 3 dup_count = 0 [1, 3, 3, 4, 5, 5, 6]
// i == 2 replaced = 2  last_item = 3 dup_count = 1 [1, 3, 3, 4, 5, 5, 6]
// i == 3 replaced = 3  last_item = 4 dup_count = 0 [1, 3, 4, 4, 5, 5, 6]
// i == 4 replaced = 4  last_item = 5 dup_count = 0 [1, 3, 4, 5, 5, 5, 6]
// i == 5 replaced =   last_item = 5 dup_count = 1 [1, 3, 4, 5, 5, 5, 6]
// i == 6 replaced = 5  last_item = 6 dup_count = 0 [1, 3, 4, 5, 6, 5, 6]